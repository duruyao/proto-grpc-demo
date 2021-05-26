# Demo of Using Protocol Buffers and gRPC by C++

## 1. Rre-requisites

### 1.1. Protocol Buffers

- Protocol Buffers 源码编译安装指南：[Installation Guide of Protocol Buffers](./doc/0-install-guide.md#1-protocol-buffers)

- Protocol Buffers 编程使用指南：[Usage Guide of Protocol Buffers](./doc/1-usage-guide.md#1-protocol-buffers)

### 1.2. gRPC

- gRPC 源码编译安装指南：[Installation Guide of gRPC](./doc/0-install-guide.md#2-dependents-of-grpc)

- gRPC 编程使用指南：[Usage Guide of gRPC](./doc/1-usage-guide.md#2-grpc)

## 2. Demo Project

### 2.1. Compiling Source

执行下述命令编译此项目：

```shell
mkdir -p build && rm -rf build/* &&                                     \
        pushd build && /usr/bin/cmake .. &&                             \
        /usr/bin/cmake --build . --target clean -- -j 16 &&             \
        /usr/bin/cmake --build . --target proto_2_cxx -- -j 16 &&       \
        /usr/bin/cmake --build . --target grpc_2_cxx -- -j 16 &&        \
        /usr/bin/cmake --build . --target rpc_server_demo -- -j 16 &&   \
        /usr/bin/cmake --build . --target rpc_client_demo -- -j 16 &&   \
        popd
```

### 2.2. Run Demo

执行`build/src/server/rpc_server_demo <IPV4:PORT>`启动 RPC 服务端：

```shell
+-------------------------------+
| RPC-SERVER-DEMO               |
| date:   2021.05.24            |
| author: duruyao@hikvision.com |
+-------------------------------+

RPC Server listen on IPV4:PORT
```

执行`build/src/client/rpc_client_demo <IPV4:PORT>`启动 RPC 客户端：

```shell
+-------------------------------+
| RPC-CLIENT-DEMO               |
| date:   2021.05.24            |
| author: duruyao@hikvision.com |
+-------------------------------+

RPC Client connect to IPV4:PORT

---> [Point]
latitude: 302131223
longitude: 1202193223

<--- [Feature]
name: "point_2"
location {
  latitude: 302131223
  longitude: 1202193223
}
```

### 2.3. Overview

在此项目中，客户端通过 RPC 的方式与服务端的通信，发送 **序列化** 的数据作为请求，接收服务端的返回的应答数据，并 **反序列化** 为一个 C++ 中的对象。

其中序列化数据方式为 [Protocol Buffers](https://developers.google.com/protocol-buffers)，RPC 框架为 [gRPC](https://grpc.io/)。
