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

Execute the script named [third_party/protobuf/install_protobuf.sh](../third_party/protobuf/install_protobuf.sh) to check pre-requisites , compile source codes, link shared libraries and install.

The usage likes this (**sudo permission may be needed**):

```shell
chmod +x install_protobuf.sh && \
./install_protobuf.sh <PROTOBUF_ZIP_DIR> <PROTOBUF_INSTALL_DIR>
```

### 1.3. Check

Check if Protocol Buffers is installed successfully by execute `/usr/bin/ldd <PROTOBUF_INSTALL_DIR>/lib/libproto*.so`, and make sure all dependent libraries are linked rightly.

Show version of Protocol Buffers by execute `<PROTOBUF_INSTALL_DIR>/bin/protoc --version`.

---

## 2. Dependents of gRPC

Install multiple libraries or applications (contains [Protocol Buffers](#1-protocol-buffers)) before compiling source codes of gRPC.

### 2.1. abseil-cpp

#### 2.1.1. Download

Download source files (ZIP format) from [https://github.com/abseil/abseil-cpp/releases](https://github.com/abseil/abseil-cpp/releases).

#### 2.1.2. Compile & Install

Execute the script named [third_party/abseil-cpp/install_abseil-cpp.sh](../third_party/abseil-cpp/install_abseil-cpp.sh) to check pre-requisites, compile source codes, link shared libraries and install.

The usage likes this (**sudo permission may be needed**):

```shell
chmod +x install_abseil-cpp.sh &&  \
./install_abseil-cpp.sh <ABSEIL_ZIP_DIR> <ABSEIL_INSTALL_DIR>
```

#### 2.1.3. Check

Check if abseil-cpp is installed successfully by execute `/usr/bin/ldd <ABSEIL_INSTALL_DIR>/lib/libabsl*.so`, and make sure all dependent libraries are linked rightly.

### 2.2. c-ares

#### 2.2.1. Download

Download source files (ZIP format) from [https://github.com/c-ares/c-ares/releases](https://github.com/c-ares/c-ares/releases).

#### 2.2.2. Compile & Install
 
Execute the script named [third_party/c-ares/install_c-ares.sh](../third_party/c-ares/install_c-ares.sh) to check pre-requisites , compile source codes, link shared libraries and install.
 
The usage likes this (**sudo permission may be needed**):

```shell
chmod +x install_c-ares.sh &&   \
./install_c-ares.sh <CARES_ZIP_DIR> <CARES_INSTALL_DIR>
```

#### 2.2.3. Check

Check if c-ares is installed successfully by execute `/usr/bin/ldd <CARES_INSTALL_DIR>/lib/libcares*.so`, and make sure all dependent libraries are linked rightly.

### 2.3. re2

#### 2.3.1. Download

Download source files (ZIP format) from [https://github.com/google/re2/releases](https://github.com/google/re2/releases).

#### 2.3.2. Compile & Install

Execute the script named [third_party/re2/install_re2.sh](../third_party/re2/install_re2.sh) to check pre-requisites , compile source codes, link shared libraries and install.

The usage likes this (**sudo permission may be needed**):

```shell
chmod +x install_re2.sh && \
./install_re2.sh <RE2_ZIP_DIR> <RE2_INSTALL_DIR>
```

#### 2.3.3. Check

Check if re2 is installed successfully by execute `/usr/bin/ldd <RE2_INSTALL_DIR>/lib/libre2*.so`, and make sure all dependent libraries are linked rightly.

### 2.4. zlib

#### 2.4.1. Download

Download source files (ZIP format) from [https://www.zlib.net/](https://www.zlib.net/).

#### 2.4.2. Compile & Install

-Execute the script named [third_party/zlib/install_zlib.sh](../third_party/zlib/install_zlib.sh) to check pre-requisites , compile source codes, link shared libraries and install.

The usage likes this (**sudo permission may be needed**):

```shell
chmod +x install_zlib.sh &&    \
./install_zlib.sh <ZLIB_ZIP_DIR> <ZLIB_INSTALL_DIR>
```

#### 2.4.3. Check

Check if zlib is installed successfully by execute `/usr/bin/ldd <ZLIB_INSTALL_DIR>/lib/libz*.so`, and make sure all dependent libraries are linked rightly.

---

## 3. gRPC

### 3.1. Download

Download source files (ZIP format) from [https://github.com/grpc/grpc/releases](https://github.com/grpc/grpc/releases).

### 3.2. Compile & Install

Execute the script named [third_party/grpc/install_grpc.sh](../third_party/grpc/install_grpc.sh) to check pre-requisites , compile source codes, link shared libraries and install.

The usage likes this (**sudo permission may be needed**):

```shell
chmod +x install_grpc.sh &&    \
./install_grpc.sh <GRPC_ZIP_DIR> <GRPC_INSTALL_DIR> <SDK_HOME>
```

Make sure you have set the value of **`my_prefix_path`** and **`my_cxx_flags`** rightly by modifying [third_party/grpc/install_grpc.sh](../third_party/grpc/install_grpc.sh) before compiling source codes.

### 3.3 Check

Check if gRPC is installed successfully by command `/usr/bin/ldd <GRPC_INSTALL_DIR>/lib/libgrpc*.so`, and make sure all dependent libraries are linked rightly.

---

## 4. Remark

It is recommended that all libraries or applications are installed to `<YOUR_SDK_HOME>/<APP_NAME>`, likes this:

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
