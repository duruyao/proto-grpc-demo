//
// Created by duruyao on 2021/5/25.
//

#include "rpc_client.h"

using grpc::CreateChannel;
using grpc::InsecureChannelCredentials;

/**
 *
 * @param addr
 */
MyRPCClient::MyRPCClient(const std::string &addr) : channel(CreateChannel(addr, InsecureChannelCredentials())),
                                                    stub(routeguide::RouteGuideService::NewStub(channel)) {
    if (!channel || !stub)
        fprintf(stderr, "error creating channel or stub\n");
}

/**
 *
 * @return
 */
google::protobuf::Timestamp *MyRPCClient::getTimestamp() {
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
MyRPCClient::getDuration(google::protobuf::Timestamp &start, google::protobuf::Timestamp &end) {
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
