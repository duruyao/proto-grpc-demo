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

- 执行 bash 脚本 [tools/script/proto_install](../tools/script/proto_install) 检查依赖，编译源代码，链接共享库并安装

用法示例如下（**可能需要 sudo 权限**）：

```shell
chmod +x proto_install && \
./proto_install <PROTO_ZIP_DIR> <PROTO_INSTALL_DIR>
```

### 1.3. Check

- 执行`/usr/bin/ldd <PROTO_INSTALL_DIR>/lib/libproto*.so`检查 Protocol Buffers 是否成功安装，确认正确链接所有共享库

- 执行`<PROTO_INSTALL_DIR>/bin/protoc --version`显示 Protocol Buffers 版本

---

## 2. Dependents of gRPC

编译 gRPC 源代码之前需要安装多个 **依赖库** 或 **软件**（包括 [Protocol Buffers](#1-protocol-buffers)）。

### 2.1. abseil-cpp

#### 2.1.1. Download

- 从 [https://github.com/abseil/abseil-cpp/releases](https://github.com/abseil/abseil-cpp/releases) 下载 ZIP 格式的源代码压缩包

#### 2.1.2. Compile & Install

- 执行 bash 脚本 [tools/script/abseil_install](../tools/script/abseil_install) 检查依赖，编译源代码，链接共享库并安装

用法示例如下（**可能需要 sudo 权限**）：

```shell
chmod +x abseil_install &&  \
./abseil_install <ABSL_ZIP_DIR> <ABSL_INSTALL_DIR>
```

#### 2.1.3. Check

- 执行`/usr/bin/ldd <ABSL_INSTALL_DIR>/lib/libabsl*.so`检查 abseil-cpp 被成功安装，确认正确链接所有共享库

### 2.2. c-ares

#### 2.2.1. Download

- 从 [https://github.com/c-ares/c-ares/releases](https://github.com/c-ares/c-ares/releases) 下载 ZIP 格式的源代码压缩包

#### 2.2.2. Compile & Install
 
- 执行 bash 脚本 [tools/script/cares_install](../tools/script/cares_install) 检查依赖，编译源代码，链接共享库并安装
 
- 用法示例如下（**可能需要 sudo 权限**）：

```shell
chmod +x cares_install &&   \
./cares_install <CARES_ZIP_DIR> <CARES_INSTALL_DIR>
```

#### 2.2.3. Check

- 执行`/usr/bin/ldd <CARES_INSTALL_DIR>/lib/libcares*.so`检查 c-ares 是否被成功安装，确认正确链接所有共享库

### 2.3. re2

#### 2.3.1. Download

- 从 [https://github.com/google/re2/releases](https://github.com/google/re2/releases) 下载 ZIP 格式的源代码压缩包

#### 2.3.2. Compile & Install

- 执行 bash 脚本 [tools/script/re2_install](../tools/script/re2_install) 检查依赖，编译源代码，链接共享库并安装

用法示例如下（**可能需要 sudo 权限**）：

```shell
chmod +x re2_install && \
./re2_install <RE2_ZIP_DIR> <RE2_INSTALL_DIR>
```

#### 2.3.3. Check

- 执行`/usr/bin/ldd <RE2_INSTALL_DIR>/lib/libre2*.so`检查 re2 是否被成功安装，确认正确链接所有共享库

### 2.4. zlib

#### 2.4.1. Download

- 从 [https://www.zlib.net/](https://www.zlib.net/) 下载 ZIP 格式的源代码压缩包

#### 2.4.2. Compile & Install

- 执行 bash 脚本 [tools/scripts/zlib_install](../tools/script/zlib_install) 检查依赖，编译源代码，链接共享库并安装

用法示例如下（**可能需要 sudo 权限**）：

```shell
chmod +x zlib_install &&    \
./zlib_install <ZLIB_ZIP_DIR> <ZLIB_INSTALL_DIR>
```

#### 2.4.3. Check

- 执行`/usr/bin/ldd <ZLIB_INSTALL_DIR>/lib/libz*.so`检查 zlib 是否被安装成，确认正确链接所有共享库

---

## 3. gRPC

### 3.1. Download

- 从 [https://github.com/grpc/grpc/releases](https://github.com/grpc/grpc/releases) 下载 ZIP 格式的源代码压缩包

### 3.2. Compile & Install

- 编译源代码之前修改 [tools/scripts/grpc_install](../tools/script/grpc_install) 的内容，正确设置 **`my_prefix_path`** 和 **`my_cxx_flags`** 的值

- 执行 bash 脚本 [tools/scripts/grpc_install](../tools/script/grpc_install) 检查依赖，编译源代码，链接共享库并安装

用法示例如下（**可能需要 sudo 权限**）：

```shell
chmod +x grpc_install &&    \
./grpc_install <GRPC_ZIP_DIR> <GRPC_INSTALL_DIR>
```

### 3.3 Check

- 执行`/usr/bin/ldd <GRPC_INSTALL_DIR>/lib/libgrpc*.so`检查 gRPC 是否被成功安装，确认正确链接所有共享库

---

## 4. Remark

建议所有的 **依赖库** 和 **软件** 被安装到统一的路径（`<YOUR_SDK_DIR>/<APP_NAME>`），就像这样：

```shell
/opt/HikSDK/
├── absl
│   ├── include
│   └── lib
├── cares
│   ├── include
│   ├── lib
│   └── share
├── grpc
│   ├── bin
│   ├── include
│   ├── lib
│   └── share
├── proto
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
