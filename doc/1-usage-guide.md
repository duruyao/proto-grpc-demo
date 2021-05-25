# Usage Guide of Protocol Buffers and gRPC

## [[Index]](#usage-guide-of-protocol-buffers-and-grpc)

- [1. Protocol Buffers]()
    - [1.1. 简介](#11-introduction)
    - [1.2. 安装](#12-install)
    - [1.3. 使用](#13-usage)
        - [1.3.1. 定义 Message](#131-defining-a-message-type)
        - [1.3.2. 数据类型](#132-scalar-value-types)
        - [1.3.3. 缺省值](#133-default-values)
        - [1.3.4. 导入 Message](#134-importing-a-message-type)
        - [1.3.5. 更新 Message](#135-updating-a-message-type)
        - [1.3.6. 映射 JSON](#136-json-mapping)
        - [1.3.7. 编译 proto](#137-compiling-proto-files)
        - [1.3.8. C++ 编程接口](#138-cpp-api)
    - [1.4. 示例]()
        - [1.4.1. CMake]()
        - [1.4.2. 运行]()
- [2. gRPC]()
    - [2.1. 简介](#21-introduction)
    - [2.2. 安装](#22-install)
    - [2.3. 使用](#23-usage)

## 1. Protocol Buffers

### 1.1. Introduction

[Protocol Buffers](https://developers.google.com/protocol-buffers) 是 Google 的跨语言的，跨平台的可扩展的机制，用于对结构化数据进行序列化。它类似于 XML，但更小，更快，更简单。先定义数据的构造方式，再生成特定的编程语言的源代码，就可以轻松地在各种数据流中用他们读/写结构化数据。

Protocol Buffers 当前支持生成 Java，Python，Objective-C 和 C++ 的代码。使用最新的 proto3 版本，还可以使用 Dart，Go，Ruby 和 C＃。

系统性地学习请优先参见下述官方文档，前人之述备矣。

- [Protocol Buffers 源代码](https://github.com/protocolbuffers/protobuf)

- [Protocol Buffers 语法概述](https://developers.google.com/protocol-buffers/docs/overview)

- [Protocol Buffers 配合编程语言使用](https://developers.google.com/protocol-buffers/docs/tutorials)

### 1.2. Install

参考 [Protocol Buffers 源码编译安装指南](./0-install-guide.md#1-protocol-buffers)。

### 1.3. Usage

本节主要讲述了：使用 Protocol Buffers 构造数据、生成相应的 C++ `Class` 以及使用 C++ 编程接口。本节使用的语法标准为 `proto3`，关于 `proto2` 的信息请参考 *[Proto2 Language Guide](https://developers.google.com/protocol-buffers/docs/proto)* 。

#### 1.3.1. Defining A Message Type

#### 1.3.2. Scalar Value Types



| proto 数据类型 | 备注 | C++ 数据类型 |
| :-: | :-: | :-: |
| `double` | 双精度浮点型 | `double` |
| `float` | 单精度浮点型 | `float` |
| `int32` | 32位有符号整型 | `int`<br>`int32_t` |
| `int64` | 64位有符号整型 | `int64_t` |
| `uint32` | 32位无符号整型 | `unsigned int`<br>`uint32_t` |
| `uint64` | 64位无符号整型 | `uint64_t` |
| `sint32` | 比`int32`更高效地编码负数 | `int`<br>`int32_t` |
| `sint64` | 比`int64`更高效地编码负数 | `int64_t` |
| `fixed32` | 比`uint32`更高效地编码其值经常大于`2 ^ 28`的数 | `unsigned int`<br>`uint32_t` |
| `fixed64` | 比`uint64`更高效地编码其值经常大于`2 ^ 56`的数 | `uint64_t` |
| `sfixed32` | 比`uint32`更高效地编码其值总是4字节的数 | `int`<br>`int32_t` |
| `sfixed64` | 比`uint32`更高效地编码其值总是8字节的数 | `int64_t` |
| `bool` |  | `bool` |
| `string` | 始终包含`UTF-8`编码或7位`ASCII`编码的字节序列，并且长度不能超过`2 ^ 32` | `std::__cxx11::string` |
| `bytes` | 可以包含不超过`2 ^ 32`的任意字节序列 | `std::__cxx11::string` |

#### 1.3.3. Default Values



#### 1.3.4. Importing A Message Type

#### 1.3.5. Updating A Message Type

#### 1.3.6. JSON Mapping

#### 1.3.7. Compiling Proto Files

#### 1.3.8. CPP API

---

## 2. gRPC

### 2.1. Introduction

### 2.2. Install

### 2.3. Usage
