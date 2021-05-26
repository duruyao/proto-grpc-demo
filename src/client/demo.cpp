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

int main(int argc, char **argv) {
    fprintf(stdout,
            "+-------------------------------+\n"
            "| RPC-CLIENT-DEMO               |\n"
            "| date: 2021.05.24              |\n"
            "| author: duruyao@hikvision.com |\n"
            "+-------------------------------+\n\n");

    std::string addr((nullptr == argv[1]) ? "0.0.0.0:1213" : argv[1]);
    MyRPCClient client(addr);
    if (!client.connectOK())
        return 1;

    fprintf(stdout, "RPC Client connect to %s\n\n", addr.data());

    { // GetFeature
        for (int n = 0; n < 20; n++) {
            ClientContext ctx;
            Point point1;
            Feature feature1;
            Status status;

            point1.set_longitude(1202193123 + 100 * n);
            point1.set_latitude(302131123 + 100 * n);

            fprintf(stdout, "---> [Point]\n%s\n", point1.DebugString().data());

            status = client.STUB->GetFeature(&ctx, point1, &feature1);

            if (status.ok()) {
                fprintf(stdout, "<--- [Feature]\n%s\n", feature1.DebugString().data());
            } else {
                fprintf(stderr, "error calling GetFeature\n\n");
            }
            sleep(2);
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
