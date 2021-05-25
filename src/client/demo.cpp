#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "route_guide.pb.h"
#include "route_guide.grpc.pb.h"

using routeguide::TestMsg;

int main() {
    fprintf(stdout,
            "+-------------------------------+\n"
            "| RPC-CLIENT-DEMO               |\n"
            "| date: 2021.05.24              |\n"
            "| author: duruyao@hikvision.com |\n"
            "+-------------------------------+\n\n");

    TestMsg testMsg1;
    TestMsg testMsg2;

    testMsg1.set_id(23);
    testMsg1.set_title("TEST-MESSAGE-1");
    testMsg1.set_timestamp(1621837293123UL);

    testMsg2.ParseFromString(testMsg1.SerializeAsString());
    testMsg2.set_title("TEST-MESSAGE-2");
    testMsg2.set_msg_type(TestMsg::MAG_TYPE_TRACK);

    fprintf(stdout, "[testMsg1]\n%s\n", testMsg1.DebugString().data());
    fprintf(stdout, "[testMsg2]\n%s\n", testMsg2.DebugString().data());

    return 0;
}
