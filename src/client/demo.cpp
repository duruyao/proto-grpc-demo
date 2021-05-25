#include <cstdio>
#include <iostream>

#include "rpc_client.h"

using grpc::Channel;
using grpc::Status;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientWriter;
using grpc::ClientReaderWriter;

using grpc::CreateChannel;
using grpc::InsecureChannelCredentials;

using routeguide::Point;
using routeguide::Feature;
using routeguide::Rectangle;
using routeguide::RouteNote;
using routeguide::RouteSummary;

int main() {
    fprintf(stdout,
            "+-------------------------------+\n"
            "| RPC-CLIENT-DEMO               |\n"
            "| date: 2021.05.24              |\n"
            "| author: duruyao@hikvision.com |\n"
            "+-------------------------------+\n\n");

//    TestMsg testMsg1;
//    TestMsg testMsg2;
//
//    testMsg1.set_id(23);
//    testMsg1.set_title("TEST-MESSAGE-1");
//    testMsg1.set_timestamp(1621837293123UL);
//
//    testMsg2.ParseFromString(testMsg1.SerializeAsString());
//    testMsg2.set_title("TEST-MESSAGE-2");
//    testMsg2.set_msg_type(TestMsg::MAG_TYPE_TRACK);
//
//    fprintf(stdout, "[testMsg1]\n%s\n", testMsg1.DebugString().data());
//    fprintf(stdout, "[testMsg2]\n%s\n", testMsg2.DebugString().data());

    std::string addr("0.0.0.0:1213");
    MyRPCClient client(addr);
    if (!client.connectOK())
        return 1;

    fprintf(stdout, "RPC Client connect to %s\n\n", addr.data());

    { // GetFeature
        ClientContext ctx;
        Point point1;
        Feature feature1;
        Status status;

        point1.set_longitude(1202193123 + 100);
        point1.set_latitude(302131123 + 100);

        fprintf(stdout, "---> [Point]\n%s\n", point1.DebugString().data());

        status = client.STUB->GetFeature(&ctx, point1, &feature1);

        if (status.ok()) {
            fprintf(stdout, "<--- [Feature]\n%s\n", feature1.DebugString().data());
        } else {
            fprintf(stderr, "error calling GetFeature\n\n");
        }
    }

    { // ListFeatures

    }

    { // RecordRoute

    }

    { // RouteChat

    }

    return 0;
}
