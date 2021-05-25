//
// Created by duruyao on 2021/5/25.
//

#include "rpc_client.h"

using grpc::CreateChannel;
using grpc::InsecureChannelCredentials;

MyRPCClient::MyRPCClient(const std::string &addr) : channel(CreateChannel(addr, InsecureChannelCredentials())),
                                                    stub(routeguide::RouteGuideService::NewStub(channel)) {
    if (!channel || !stub)
        fprintf(stderr, "error creating channel or stub\n");
}
