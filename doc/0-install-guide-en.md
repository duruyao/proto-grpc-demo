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

Download source files (ZIP format) from [https://github.com/protocolbuffers/protobuf/releases](https://github.com/protocolbuffers/protobuf/releases).

### 1.2. Compile & Install

Execute the script named [proto_install](../tools/script/proto_install) which is in [tools/scripts/](../tools/script) to check pre-requisites , compile source codes, link shared libraries and install.

The usage likes this (**sudo permission may be needed**):

```shell
chmod +x proto_install && \
./proto_install <PROTO_ZIP_DIR> <PROTO_INSTALL_DIR>
```

### 1.3. Check

Check if Protocol Buffers is installed successfully by execute `/usr/bin/ldd <PROTO_INSTALL_DIR>/lib/libproto*.so`, and make sure all dependent libraries are linked rightly.

Show version of Protocol Buffers by execute `<PROTO_INSTALL_DIR>/bin/protoc --version`.

---

## 2. Dependents of gRPC

Install multiple libraries or applications (contains [Protocol Buffers](#1-protocol-buffers)) before compiling source codes of gRPC.

### 2.1. abseil-cpp

#### 2.1.1. Download

Download source files (ZIP format) from [https://github.com/abseil/abseil-cpp/releases](https://github.com/abseil/abseil-cpp/releases).

#### 2.1.2. Compile & Install

Execute the script named [abseil_install](../tools/script/abseil_install) which is in [tools/scripts/](../tools/script) to check pre-requisites, compile source codes, link shared libraries and install.

The usage likes this (**sudo permission may be needed**):

```shell
chmod +x abseil_install &&  \
./abseil_install <ABSL_ZIP_DIR> <ABSL_INSTALL_DIR>
```

#### 2.1.3. Check

Check if abseil-cpp is installed successfully by execute `/usr/bin/ldd <ABSL_INSTALL_DIR>/lib/libabsl*.so`, and make sure all dependent libraries are linked rightly.

### 2.2. c-ares

#### 2.2.1. Download

Download source files (ZIP format) from [https://github.com/c-ares/c-ares/releases](https://github.com/c-ares/c-ares/releases).

#### 2.2.2. Compile & Install
 
Execute the script named [cares_install](../tools/script/cares_install) which is in [tools/scripts/](../tools/script) to check pre-requisites , compile source codes, link shared libraries and install.
 
The usage likes this (**sudo permission may be needed**):

```shell
chmod +x cares_install &&   \
./cares_install <CARES_ZIP_DIR> <CARES_INSTALL_DIR>
```

#### 2.2.3. Check

Check if c-ares is installed successfully by execute `/usr/bin/ldd <CARES_INSTALL_DIR>/lib/libcares*.so`, and make sure all dependent libraries are linked rightly.

### 2.3. re2

#### 2.3.1. Download

Download source files (ZIP format) from [https://github.com/google/re2/releases](https://github.com/google/re2/releases).

#### 2.3.2. Compile & Install

Execute the script named [re2_install](../tools/script/re2_install) which is in [tools/scripts/](../tools/script) to check pre-requisites , compile source codes, link shared libraries and install.

The usage likes this (**sudo permission may be needed**):

```shell
chmod +x re2_install && \
./re2_install <RE2_ZIP_DIR> <RE2_INSTALL_DIR>
```

#### 2.3.3. Check

Check if re2 is installed successfully by execute `/usr/bin/ldd <RE2_INSTALL_DIR>/lib/libre2*.so`, and make sure all dependent libraries are linked rightly.

### 2.4. zlib

#### 2.4.1. Download

Download source files (ZIP format) from [https://www.zlib.net/](https://www.zlib.net/).

#### 2.4.2. Compile & Install

-Execute the script named [zlib_install](../tools/script/zlib_install) which is in [tools/scripts/](../tools/script) to check pre-requisites , compile source codes, link shared libraries and install.

The usage likes this (**sudo permission may be needed**):

```shell
chmod +x zlib_install &&    \
./zlib_install <ZLIB_ZIP_DIR> <ZLIB_INSTALL_DIR>
```

#### 2.4.3. Check

Check if zlib is installed successfully by execute `/usr/bin/ldd <ZLIB_INSTALL_DIR>/lib/libz*.so`, and make sure all dependent libraries are linked rightly.

---

## 3. gRPC

### 3.1. Download

Download source files (ZIP format) from [https://github.com/grpc/grpc/releases](https://github.com/grpc/grpc/releases).

### 3.2. Compile & Install

Execute the script named [grpc_install](../tools/script/grpc_install) which is in [tools/scripts/](../tools/script) to check pre-requisites , compile source codes, link shared libraries and install.

The usage likes this (**sudo permission may be needed**):

```shell
chmod +x grpc_install &&    \
./grpc_install <GRPC_ZIP_DIR> <GRPC_INSTALL_DIR>
```

Make sure you have set the value of **`my_prefix_path`** and **`my_cxx_flags`** rightly by modifying [grpc_install](../tools/script/grpc_install) before compiling source codes.

### 3.3 Check

Check if gRPC is installed successfully by command `/usr/bin/ldd <GRPC_INSTALL_DIR>/lib/libgrpc*.so`, and make sure all dependent libraries are linked rightly.

---

## 4. Remark

It is recommended that all libraries or applications are installed to `<YOUR_SDK_DIR>/<APP_NAME>`, likes this:

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
