//
// Created by duruyao on 2021/5/25.
//

#ifndef PROTO_GRPC_DEMO_RPC_SERVICE_H
#define PROTO_GRPC_DEMO_RPC_SERVICE_H

#include <chrono>
#include <cmath>
#include <memory>
#include <string>
#include <mutex>
#include <atomic>
#include <thread>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <grpc/grpc.h>
#include <grpcpp/server.h>
#include <condition_variable>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include <grpcpp/security/server_credentials.h>

#include "route_guide.pb.h"
#include "route_guide.grpc.pb.h"


class MyRPCService final : public routeguide::RouteGuideService::Service {
public:
    MyRPCService();

    MyRPCService(const MyRPCService &) = delete;

    MyRPCService(MyRPCService &&) noexcept = delete;

    MyRPCService &operator=(const MyRPCService &) = delete;

    MyRPCService &operator=(MyRPCService &&) = delete;

    ~MyRPCService() noexcept override = default;

private:
    // see 'route_guide.proto'
    // rpc GetFeature(Point) returns (Feature) {}
    grpc::Status GetFeature(grpc::ServerContext *ctx,
                            const routeguide::Point *point,
                            routeguide::Feature *feature) override;

    // see 'route_guide.proto'
    // rpc ListFeatures(Rectangle) returns (stream Feature) {}
    grpc::Status ListFeatures(grpc::ServerContext *ctx,
                              const routeguide::Rectangle *rectangle,
                              grpc::ServerWriter<routeguide::Feature> *writer) override;

    // see 'route_guide.proto'
    // rpc RecordRoute(stream Point) returns (RouteSummary) {}
    grpc::Status RecordRoute(grpc::ServerContext *ctx,
                             grpc::ServerReader<routeguide::Point> *reader,
                             routeguide::RouteSummary *summary) override;

    // see 'route_guide.proto'
    // rpc RouteChat(stream RouteNote) returns (stream RouteNote) {}
    grpc::Status RouteChat(grpc::ServerContext *ctx,
                           grpc::ServerReaderWriter<routeguide::RouteNote,
                                   routeguide::RouteNote> *stream) override;

private:
    std::vector<routeguide::Feature> featureList;
    std::mutex mutex_;
    std::vector<routeguide::RouteNote> recvNotes;

private:

    static std::string getFeatureName(const routeguide::Point &point, const std::vector<routeguide::Feature> &features);

    static double getDistance(const routeguide::Point &start, const routeguide::Point &end);

    static inline double convertToRadians(double num) { return (num * 3.1415926 / 180); }
};

#endif //PROTO_GRPC_DEMO_RPC_SERVICE_H
