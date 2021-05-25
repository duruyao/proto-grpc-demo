//
// Created by duruyao on 2021/5/25.
//

#ifndef PROTO_GRPC_DEMO_RPC_SERVICE_H
#define PROTO_GRPC_DEMO_RPC_SERVICE_H

#include <mutex>
#include <atomic>
#include <thread>
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
    MyRPCService() = default;

    MyRPCService(const MyRPCService &) = delete;

    MyRPCService(MyRPCService &&) noexcept = delete;

    MyRPCService &operator=(const MyRPCService &) = delete;

    MyRPCService &operator=(MyRPCService &&) = delete;

    ~MyRPCService() noexcept override = default;

private:
};

#endif //PROTO_GRPC_DEMO_RPC_SERVICE_H
