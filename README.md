# Demo of Using Protocol Buffers and gRPC by C++

## Rre-requisites

### Protocol Buffers

- Protocol Buffers 源码编译安装指南：[Installation Guide of Protocol Buffers](./doc/0-install-guide.md#1-protocol-buffers)

- Protocol Buffers 编程使用指南：[Usage Guide of Protocol Buffers](./doc/1-usage-guide.md#1-protocol-buffers)

### gRPC

- gRPC 源码编译安装指南：[Installation Guide of gRPC](./doc/0-install-guide.md#2-dependents-of-grpc)

- gRPC 编程使用指南：[Usage Guide of gRPC](./doc/1-usage-guide.md#2-grpc)

## 编译当前项目

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

运行`build/src/server/rpc_server_demo`：

```shell
+-------------------------------+
| RPC-SERVER-DEMO               |
| date:   2021.05.24            |
| author: duruyao@hikvision.com |
+-------------------------------+

RPC Server listen on 0.0.0.0:1213
```

运行`build/src/client/rpc_client_demo`：

```shell
+-------------------------------+
| RPC-CLIENT-DEMO               |
| date:   2021.05.24            |
| author: duruyao@hikvision.com |
+-------------------------------+

RPC Client connect to 0.0.0.0:1213

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