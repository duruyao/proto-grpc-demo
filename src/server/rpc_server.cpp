//
// Created by duruyao on 2021/5/25.
//

#include "rpc_server.h"

void MyRPCServer::run() {
    builder.AddListeningPort(addr, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<Server> server(builder.BuildAndStart());
    if (nullptr == server) {
        fprintf(stderr, "error building and starting RPC Server (%s)\n", addr.data());
        return;
    }
    server->Wait();
}

void MyRPCServer::start() {
    std::thread myThread(&MyRPCServer::run, this);
    fprintf(stdout, "RPC Server listen on %s\n\n", addr.data());
    myThread.join();

}
