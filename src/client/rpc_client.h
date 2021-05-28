//
// Created by duruyao on 2021/5/25.
//

#ifndef PROTO_GRPC_DEMO_RPC_CLIENT_H
#define PROTO_GRPC_DEMO_RPC_CLIENT_H

#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include "route_guide.pb.h"
#include "route_guide.grpc.pb.h"

#define STUB    getStub()

class MyRPCClient final {
public:
    MyRPCClient() = delete;

    ~MyRPCClient() noexcept = default;

    explicit MyRPCClient(const std::string &addr);

    MyRPCClient(const MyRPCClient &) = delete;

    MyRPCClient(MyRPCClient &&) noexcept = delete;

    MyRPCClient &operator=(const MyRPCClient &) = delete;

    MyRPCClient &operator=(MyRPCClient &&) noexcept = delete;

    inline std::unique_ptr<routeguide::RouteGuideService::Stub> &getStub() noexcept { return stub; }

    inline bool connectOK() const noexcept { return (nullptr != channel && nullptr != stub); }

private:
    std::shared_ptr<grpc::Channel> channel;
    std::unique_ptr<routeguide::RouteGuideService::Stub> stub;

public:
    static google::protobuf::Timestamp *getTimestamp();

    static google::protobuf::Duration *
    getDuration(google::protobuf::Timestamp &start, google::protobuf::Timestamp &end);
};

#endif //PROTO_GRPC_DEMO_RPC_CLIENT_H
