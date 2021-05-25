//
// Created by duruyao on 2021/5/25.
//

#ifndef PROTO_GRPC_DEMO_RPC_SERVER_H
#define PROTO_GRPC_DEMO_RPC_SERVER_H

#include "grpcpp/grpcpp.h"
#include "grpc/support/log.h"

#include "route_guide.pb.h"
#include "route_guide.grpc.pb.h"

#include "rpc_service.h"

using grpc::Server;
using grpc::ServerAsyncResponseWriter;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerCompletionQueue;
using grpc::Status;

class MyRPCServer {
public:
    MyRPCServer() = delete;

    explicit MyRPCServer(std::string &serverAddr);

    MyRPCServer(const MyRPCServer &) = delete;

    MyRPCServer(MyRPCServer &&) noexcept = delete;

    MyRPCServer &operator=(const MyRPCServer &) = delete;

    MyRPCServer &operator=(MyRPCServer &&) = delete;

    ~MyRPCServer() noexcept = default;

    void start();

private:
    const std::string addr;
    MyRPCService service;
    ServerBuilder builder;

private:
    void run();
};

#endif //PROTO_GRPC_DEMO_RPC_SERVER_H
