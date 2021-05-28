//
// Created by duruyao on 2021/5/25.
//

#include "rpc_service.h"

using grpc::Server;
using grpc::Status;
using grpc::ServerReader;
using grpc::ServerWriter;
using grpc::ClientContext;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ClientReaderWriter;
using grpc::ServerReaderWriter;

using routeguide::Point;
using routeguide::Feature;
using routeguide::Rectangle;
using routeguide::RouteNote;
using routeguide::RouteSummary;

using std::chrono::system_clock;

/**
 *
 */
MyRPCService::MyRPCService() {
    for (int i = 0; i < 26; i++) {
        Feature feature;
        feature.set_name("point_" + std::to_string(i + 1));
        feature.mutable_location()->set_latitude(302131123 + 100 * i);
        feature.mutable_location()->set_longitude(1202193123 + 100 * i);
        featureList.push_back(feature);
    }
}

/**
 *
 * @param ctx
 * @param point
 * @param feature
 * @return
 */
Status MyRPCService::GetFeature(ServerContext *ctx, const Point *point, Feature *feature) {
    Status ret = Status::CANCELLED;

    fprintf(stdout, "<--- [Point]\n%s\n", point->DebugString().data());

    feature->set_name(getFeatureName(*point, featureList));
    feature->mutable_location()->CopyFrom(*point);

    feature->set_allocated_timestamp(getTimestamp());

    fprintf(stdout, "---> [Feature]\n%s\n", feature->DebugString().data());

    ret = Status::OK;
    return ret;
}

/**
 *
 * @param ctx
 * @param rectangle
 * @param writer
 * @return
 */
Status MyRPCService::ListFeatures(ServerContext *ctx, const Rectangle *rectangle, ServerWriter<Feature> *writer) {
    Status ret = Status::CANCELLED;

    const auto &lo = rectangle->lo();
    const auto &hi = rectangle->hi();

    const auto &top = (std::max)(lo.latitude(), hi.latitude());
    const auto &bottom = (std::min)(lo.latitude(), hi.latitude());
    const auto &left = (std::min)(lo.longitude(), hi.longitude());
    const auto &right = (std::max)(lo.longitude(), hi.longitude());

    for (const Feature &f : featureList) {
        if (f.location().latitude() >= bottom && f.location().latitude() <= top &&
            f.location().longitude() >= left && f.location().longitude() <= right) {
            writer->Write(f);
        }
    }

    ret = Status::OK;
    return ret;
}

/**
 *
 * @param ctx
 * @param reader
 * @param summary
 * @return
 */
Status MyRPCService::RecordRoute(ServerContext *ctx, ServerReader<Point> *reader, RouteSummary *summary) {
    Status ret = Status::CANCELLED;

    Point point;
    int pointCount = 0;
    int featureCount = 0;
    double distance = 0.0;
    Point previous;

    system_clock::time_point startTime = system_clock::now();
    google::protobuf::Timestamp *start = getTimestamp();
    while (reader->Read(&point)) {
        pointCount++;
        if (!getFeatureName(point, featureList).empty()) {
            featureCount++;
        }
        if (pointCount != 1) {
            distance += getDistance(previous, point);
        }
        previous = point;
    }
    system_clock::time_point endTime = system_clock::now();
    google::protobuf::Timestamp *end = getTimestamp();
    summary->set_point_count(pointCount);
    summary->set_feature_count(featureCount);
    summary->set_distance(static_cast<long>(distance));
    auto secs = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
    summary->set_elapsed_time(secs.count());
    summary->set_allocated_duration(getDuration(*start, *end));

    ret = Status::OK;
    return ret;
}

/**
 *
 * @param ctx
 * @param stream
 * @return
 */
Status MyRPCService::RouteChat(ServerContext *ctx, ServerReaderWriter<RouteNote, RouteNote> *stream) {
    Status ret = Status::CANCELLED;

    RouteNote note;
    while (stream->Read(&note)) {
        std::unique_lock<std::mutex> lock(mutex_);
        for (const RouteNote &n : recvNotes) {
            if (n.location().latitude() == note.location().latitude() &&
                n.location().longitude() == note.location().longitude()) {
                stream->Write(n);
            }
        }
        recvNotes.push_back(note);
    }

    ret = Status::OK;
    return ret;
}

/**
 *
 * @param point
 * @return
 */
std::string MyRPCService::getFeatureName(const Point &point, const std::vector<Feature> &features) {
    for (const Feature &f : features) {
        if (point.latitude() == f.location().latitude() && point.longitude() == f.location().longitude()) {
            return f.name();
        }
    }
    return std::__cxx11::string();
}

/**
 *
 * @param start
 * @param end
 * @return
 */
double MyRPCService::getDistance(const Point &start, const Point &end) {
    const double kCoordFactor = 10000000.0;
    double lat1 = start.latitude() / kCoordFactor;
    double lat2 = end.latitude() / kCoordFactor;
    double lon1 = start.longitude() / kCoordFactor;
    double lon2 = end.longitude() / kCoordFactor;
    double latRad1 = convertToRadians(lat1);
    double latRad2 = convertToRadians(lat2);
    double deltaLatRad = convertToRadians(lat2 - lat1);
    double deltaLonRad = convertToRadians(lon2 - lon1);

    double a = pow(sin(deltaLatRad / 2), 2) +
               cos(latRad1) * cos(latRad2) * pow(sin(deltaLonRad / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    int R = 6371000;  // metres

    return R * c;
}

/**
 * 
 * @return 
 */
google::protobuf::Timestamp *MyRPCService::getTimestamp() {
    auto *timestamp = new(google::protobuf::Timestamp);
    struct timeval tv{};
    gettimeofday(&tv, nullptr);

    timestamp->set_seconds(tv.tv_sec);
    timestamp->set_nanos(tv.tv_usec * 1000);

    return timestamp;
}

/**
 * 
 * @param start 
 * @param end 
 * @return 
 */
google::protobuf::Duration *
MyRPCService::getDuration(google::protobuf::Timestamp &start, google::protobuf::Timestamp &end) {
    auto *duration = new(google::protobuf::Duration);
    duration->set_seconds(end.seconds() - start.seconds());
    duration->set_nanos(end.nanos() - start.nanos());

    if (duration->seconds() < 0 && duration->nanos() > 0) {
        duration->set_seconds(duration->seconds() + 1);
        duration->set_nanos(duration->nanos() - 1000000000);
    } else if (duration->seconds() > 0 && duration->nanos() < 0) {
        duration->set_seconds(duration->seconds() - 1);
        duration->set_nanos(duration->nanos() + 1000000000);
    }
    return duration;
}
