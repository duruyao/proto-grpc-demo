//
// Created by duruyao on 2021/6/21.
//

#include <zmq.h>
#include <zmq.hpp>

#include <iostream>

void udpServerRun() {
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REP);
    socket.bind("udp://*:5007");

    zmq::message_t request;
    socket.recv(&request);
    std::cout << "[RECV]" << std::endl;
    zmq::message_t reply(11);
    memcpy(reply.data(), "Hello World", 11);
    socket.send(reply);
}