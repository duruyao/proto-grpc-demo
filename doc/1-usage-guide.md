# Usage Guide of Protocol Buffers and gRPC

## [[Index]](#usage-guide-of-protocol-buffers-and-grpc)

- [1. Protocol Buffers]()
    - [1.1. 简介](#11-introduction)
    - [1.2. 使用]()
        - [1.2.1. 定义消息]()
        - [1.2.2. 数据类型]()
    - [1.3. Demo]()
        - [1.3.1. CMake]()
        - [1.3.2. 运行]()
- [2. gRPC]()

## 1. Protocol Buffers

### 1.1. Introduction

[Protocol Buffers](https://developers.google.com/protocol-buffers) 是 Google 的跨语言的，跨平台的可扩展的机制，用于对结构化数据进行序列化。它类似于 XML，但更小，更快，更简单。先定义数据的构造方式，再生成特定的编程语言的源代码，就可以轻松地在各种数据流中用他们读/写结构化数据。

Protocol Buffers 当前支持生成 Java，Python，Objective-C 和 C++ 的代码。使用最新的 proto3 版本，还可以使用 Dart，Go，Ruby 和 C＃。

系统性地学习请优先参见下述官方文档，前人之述备矣。

- [Protocol Buffers 源代码](https://github.com/protocolbuffers/protobuf)

- [Protocol Buffers 语法概述](https://developers.google.com/protocol-buffers/docs/overview)

- [Protocol Buffers 配合编程语言使用](https://developers.google.com/protocol-buffers/docs/tutorials)


## 2. gRPC
