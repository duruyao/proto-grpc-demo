#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "rpc_server.h"

int main(int argc, char **argv) {
    fprintf(stdout,
            "+-------------------------------+\n"
            "| RPC-SERVER-DEMO               |\n"
            "| date: 2021.05.24              |\n"
            "| author: duruyao@hikvision.com |\n"
            "+-------------------------------+\n\n");

    std::string addr((nullptr == argv[1]) ? "0.0.0.0:1213" : argv[1]);
    MyRPCServer server(addr);
    server.start();

    return 0;
}