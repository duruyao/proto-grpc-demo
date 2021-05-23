# Installation Guide of Protocol Buffers and gRPC

## 1. Protocol Buffers

- Download source files (ZIP format) from [https://github.com/protocolbuffers/protobuf/releases](https://github.com/protocolbuffers/protobuf/releases).

- Execute the script named [proto_install](../tools/script/proto_install) which is in `tools/scripts` to check pre-requisites , compile source codes, link shared libraries and install. The usage is likes `./proto_install <PROTO_ZIP_DIR> <PROTO_INSTALL_DIR>`

- Check if Protocol Buffers is installed successfully by execute `ldd <PROTO_INSTALL_DIR>/lib/libproto*.so`, and make sure all dependent libraries are linked rightly.

- Show version of Protocol Buffers by execute `<PROTO_INSTALL_DIR>/bin/protoc --version`.

## 2. Dependents of gRPC

Install multiple libraries or applications (contains [Protocol Buffers](#1-protocol-buffers)) before compiling source codes of gRPC.

### 2.1. abseil-cpp

- Download source files (ZIP format) from [https://github.com/abseil/abseil-cpp/releases](https://github.com/abseil/abseil-cpp/releases).

- Execute the script named [abseil_install](../tools/script/abseil_install) which is in `tools/scripts` to check pre-requisites , compile source codes, link shared libraries and install. The usage is likes `./abseil_install <ABSL_ZIP_DIR> <ABSL_INSTALL_DIR>`

- Check if abseil-cpp is installed successfully by execute `ldd <ABSL_INSTALL_DIR>/lib/libabsl*.so`, and make sure all dependent libraries are linked rightly.

### 2.2. c-ares

- Download source files (ZIP format) from [https://github.com/c-ares/c-ares/releases](https://github.com/c-ares/c-ares/releases).

- Execute the script named [cares_install](../tools/script/cares_install) which is in `tools/scripts` to check pre-requisites , compile source codes, link shared libraries and install. The usage is likes `./cares_install <CARES_ZIP_DIR> <CARES_INSTALL_DIR>`

- Check if c-ares is installed successfully by execute `ldd <CARES_INSTALL_DIR>/lib/libcares*.so`, and make sure all dependent libraries are linked rightly.

### 2.3. re2

- Download source files (ZIP format) from [https://github.com/google/re2/releases](https://github.com/google/re2/releases).

- Execute the script named [re2_install](../tools/script/re2_install) which is in `tools/scripts` to check pre-requisites , compile source codes, link shared libraries and install. The usage is likes `./re2_install <RE2_ZIP_DIR> <RE2_INSTALL_DIR>`

- Check if re2 is installed successfully by execute `ldd <RE2_INSTALL_DIR>/lib/libre2*.so`, and make sure all dependent libraries are linked rightly.

### 2.4. zlib

- Download source files (ZIP format) from [https://www.zlib.net/](https://www.zlib.net/).

- Execute the script named [zlib_install](../tools/script/zlib_install) which is in `tools/scripts` to check pre-requisites , compile source codes, link shared libraries and install. The usage is likes `./zlib_install <ZLIB_ZIP_DIR> <ZLIB_INSTALL_DIR>`

- Check if zlib is installed successfully by execute `ldd <ZLIB_INSTALL_DIR>/lib/libz*.so`, and make sure all dependent libraries are linked rightly.

### 3. gRPC

- Download source files (ZIP format) from [https://github.com/grpc/grpc/releases](https://github.com/grpc/grpc/releases).

- Execute the script named [grpc_install](../tools/script/grpc_install) which is in `tools/scripts` to check pre-requisites , compile source codes, link shared libraries and install. The usage is likes `./grpc_install <GRPC_ZIP_DIR> <GRPC_INSTALL_DIR>`. Make sure you have set the value of **`my_prefix_path`** and **`my_cxx_flags`** rightly by modifying [grpc_install](../tools/script/grpc_install) before compiling source codes.

- Check if gRPC is installed successfully by command `ldd <GRPC_INSTALL_DIR>/lib/libgrpc*.so`, and make sure all dependent libraries are linked rightly.

### 4. Remark

It is recommended that all libraries or applications are installed to `<HIKSDK_DIR>/<APP_NAME>`, likes this:

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