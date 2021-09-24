# Installation Guide of Protocol Buffers and gRPC

## [[Index]](#installation-guide-of-protocol-buffers-and-grpc)

- [1. Protocol Buffers](#1-protocol-buffers)
- [2. Dependents of gRPC](#2-dependents-of-grpc)
    - [2.1. abseil-cpp](#21-abseil-cpp)
    - [2.2. c-ares](#22-c-ares)
    - [2.3. re2](#23-re2)
    - [2.4. zlib](#24-zlib)
- [3. gRPC](#3-grpc)
- [4. Remark](#4-remark)

---

## 1. Protocol Buffers

### 1.1. Download

- 从 [https://github.com/protocolbuffers/protobuf/releases](https://github.com/protocolbuffers/protobuf/releases) 下载 ZIP 格式的源代码压缩包

### 1.2. Compile & Install

- 执行 bash 脚本 [third_party/protobuf/install_protobuf.sh](../third_party/protobuf/install_protobuf.sh) 检查依赖，编译源代码，链接共享库并安装

用法示例如下（**可能需要 sudo 权限**）：

```shell
chmod +x install_protobuf.sh && \
./install_protobuf.sh <PROTOBUF_ZIP_PATH> <PROTOBUF_INSTALL_PATH>
```

### 1.3. Check

- 执行`/usr/bin/ldd <PROTOBUF_INSTALL_PATH>/lib/libproto*.so`检查 Protocol Buffers 是否成功安装，确认正确链接所有共享库

- 执行`<PROTOBUF_INSTALL_PATH>/bin/protoc --version`显示 Protocol Buffers 版本

---

## 2. Dependents of gRPC

编译 gRPC 源代码之前需要安装多个 **依赖库** 或 **软件**（包括 [Protocol Buffers](#1-protocol-buffers)）。

### 2.1. abseil-cpp

#### 2.1.1. Download

- 从 [https://github.com/abseil/abseil-cpp/releases](https://github.com/abseil/abseil-cpp/releases) 下载 ZIP 格式的源代码压缩包

#### 2.1.2. Compile & Install

- 执行 bash 脚本 [third_party/abseil-cpp/install_abseil-cpp.sh](../third_party/abseil-cpp/install_abseil-cpp.sh) 检查依赖，编译源代码，链接共享库并安装

用法示例如下（**可能需要 sudo 权限**）：

```shell
chmod +x install_abseil-cpp.sh &&  \
./install_abseil-cpp.sh <ABSEIL_ZIP_PATH> <ABSEIL_INSTALL_PATH>
```

#### 2.1.3. Check

- 执行`/usr/bin/ldd <ABSEIL_INSTALL_PATH>/lib/libabsl*.so`检查 abseil-cpp 被成功安装，确认正确链接所有共享库

### 2.2. c-ares

#### 2.2.1. Download

- 从 [https://github.com/c-ares/c-ares/releases](https://github.com/c-ares/c-ares/releases) 下载 ZIP 格式的源代码压缩包

#### 2.2.2. Compile & Install
 
- 执行 bash 脚本 [third_party/c-ares/install_c-ares.sh](../third_party/c-ares/install_c-ares.sh) 检查依赖，编译源代码，链接共享库并安装
 
- 用法示例如下（**可能需要 sudo 权限**）：

```shell
chmod +x install_c-ares.sh &&   \
./install_c-ares.sh <CARES_ZIP_PATH> <CARES_INSTALL_PATH>
```

#### 2.2.3. Check

- 执行`/usr/bin/ldd <CARES_INSTALL_PATH>/lib/libcares*.so`检查 c-ares 是否被成功安装，确认正确链接所有共享库

### 2.3. re2

#### 2.3.1. Download

- 从 [https://github.com/google/re2/releases](https://github.com/google/re2/releases) 下载 ZIP 格式的源代码压缩包

#### 2.3.2. Compile & Install

- 执行 bash 脚本 [third_party/re2/install_re2.sh](../third_party/re2/install_re2.sh) 检查依赖，编译源代码，链接共享库并安装

用法示例如下（**可能需要 sudo 权限**）：

```shell
chmod +x install_re2.sh && \
./install_re2.sh <RE2_ZIP_PATH> <RE2_INSTALL_PATH>
```

#### 2.3.3. Check

- 执行`/usr/bin/ldd <RE2_INSTALL_PATH>/lib/libre2*.so`检查 re2 是否被成功安装，确认正确链接所有共享库

### 2.4. zlib

#### 2.4.1. Download

- 从 [https://www.zlib.net/](https://www.zlib.net/) 下载 ZIP 格式的源代码压缩包

#### 2.4.2. Compile & Install

- 执行 bash 脚本 [third_party/zlib/install_zlib.sh](../third_party/zlib/install_zlib.sh) 检查依赖，编译源代码，链接共享库并安装

用法示例如下（**可能需要 sudo 权限**）：

```shell
chmod +x install_zlib.sh &&    \
./install_zlib.sh <ZLIB_ZIP_PATH> <ZLIB_INSTALL_PATH>
```

#### 2.4.3. Check

- 执行`/usr/bin/ldd <ZLIB_INSTALL_PATH>/lib/libz*.so`检查 zlib 是否被安装成，确认正确链接所有共享库

---

## 3. gRPC

### 3.1. Download

- 从 [https://github.com/grpc/grpc/releases](https://github.com/grpc/grpc/releases) 下载 ZIP 格式的源代码压缩包

### 3.2. Compile & Install

- 编译源代码之前修改 [third_party/grpc/install_grpc.sh](../third_party/grpc/install_grpc.sh) 的内容，正确设置 **`my_prefix_path`** 和 **`my_cxx_flags`** 的值

- 执行 bash 脚本 [third_party/grpc/install_grpc.sh](../third_party/grpc/install_grpc.sh) 检查依赖，编译源代码，链接共享库并安装

用法示例如下（**可能需要 sudo 权限**）：

```shell
chmod +x install_grpc.sh &&    \
./install_grpc.sh <GRPC_ZIP_PATH> <GRPC_INSTALL_PATH> <SDK_HOME>
```

### 3.3 Check

- 执行`/usr/bin/ldd <GRPC_INSTALL_PATH>/lib/libgrpc*.so`检查 gRPC 是否被成功安装，确认正确链接所有共享库

---

## 4. Remark

建议所有的 **依赖库** 和 **软件** 被安装到统一的路径（`<YOUR_SDK_HOME>/<APP_NAME>`），就像这样：

```shell
/opt/HikSDK/
├── abseil-cpp
│   ├── include
│   └── lib
├── c-ares
│   ├── include
│   ├── lib
│   └── share
├── grpc
│   ├── bin
│   ├── include
│   ├── lib
│   └── share
├── protobuf
│   ├── bin
│   ├── include
│   └── lib
├── re2
│   ├── include
│   └── lib
└── zlib
    ├── include
    ├── lib
    └── share
```
