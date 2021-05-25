//
// Created by duruyao on 2021/5/25.
//

#include "rpc_server.h"

MyRPCServer::MyRPCServer(std::string &serverAddr) : addr(serverAddr) {

}

void MyRPCServer::run() {
    builder.AddListeningPort(addr, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<Server> server(builder.BuildAndStart());
    if (nullptr == server) {
        fprintf(stderr, "error building and starting RPC Server (%s)\n", addr.data());
        return;
    }
    fprintf(stdout, "RPC Server listen on %s", addr.data());
    server->Wait();
}

void MyRPCServer::start() {
    std::thread myThread(&MyRPCServer::run, this);
    myThread.detach();
}
