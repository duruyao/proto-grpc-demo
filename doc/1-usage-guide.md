# Usage Guide of Protocol Buffers and gRPC

## [[Index]](#usage-guide-of-protocol-buffers-and-grpc)

- [1. Protocol Buffers]()
    - [1.1. 简介](#11-introduction)
    - [1.2. 安装](#12-install)
    - [1.3. 使用](#13-usage)
        - [1.3.1. 定义 Message](#131-defining-message)
            - [1.3.1.1. 字段类型](#1311-field-types)
            - [1.3.1.2. 字段名称](#1312-field-names)
            - [1.3.1.3. 字段号](#1313-field-numbers)
            - [1.3.1.4. 默认值](#1314-default-values)
            - [1.3.1.5. 嵌套类型](#1315-nested-types)
            - [1.3.1.6. 枚举类型](#1316-enumerations)
            - [1.3.1.7. 映射类型](#1317-maps)
        - [1.3.2. 导入 Message](#132-importing-message)
        - [1.3.3. 更新 Message](#133-updating-message)
        - [1.3.4. 映射 JSON](#134-json-mapping)
        - [1.3.5. 编译 proto](#135-compiling-proto-files)
        - [1.3.6. C++ 编程接口](#136-cpp-api)
    - [1.4. 样例项目](#14-demo-project)
- [2. gRPC](#2-grpc)
    - [2.1. 简介](#21-introduction)
    - [2.2. 安装](#22-install)
    - [2.3. 使用](#23-usage)

---

## 1. Protocol Buffers

### 1.1. Introduction

[Protocol Buffers](https://developers.google.com/protocol-buffers) 是 Google 的跨语言的，跨平台的可扩展的机制，用于对结构化数据进行序列化。它类似于 XML，但更小，更快，更简单。先定义数据的构造方式，再生成特定的编程语言的源代码，就可以轻松地在各种数据流中用他们读/写结构化数据。

Protocol Buffers 当前支持生成 Java，Python，Objective-C 和 C++ 的代码。使用最新的`proto3`版本，还可以在 Dart，Go，Ruby 和 C＃ 中使用。

系统性地学习请优先参见下述 **官方文档**，前人之述备矣。

- [Protocol Buffers 源代码](https://github.com/protocolbuffers/protobuf)

- [Protocol Buffers 语法概述](https://developers.google.com/protocol-buffers/docs/overview)

- [Protocol Buffers 配合编程语言使用](https://developers.google.com/protocol-buffers/docs/tutorials)

### 1.2. Install

参考 [Protocol Buffers 源码编译安装指南](./0-install-guide.md#1-protocol-buffers)。

### 1.3. Usage

本节主要讲述了：1）使用 Protocol Buffers 构造数据、2）生成相应的 C++ `Class` 以及 3）使用 C++ 编程接口。本节使用的语法标准为`proto3`，关于 `proto2` 的信息请参考 *[Proto2 Language Guide](https://developers.google.com/protocol-buffers/docs/proto)* 。

#### 1.3.1. Defining Message

Protocol Buffers 使用一种名为 Message 的抽象数据类型（类似于 C++ 中的 `Class`），通过`message`关键字，定义在`.proto`的文件中。下面是一个简单的例子：

```protobuf
// date:   2021.05.26
// file:   simple_msg.proto
// author: duruyao@hikvision.com

syntax = "proto3";

package simple_demo;

/* SearchRequest represents a search query, with pagination
 * options to indicate which results to include in the response. */
message SearchRequest {
  string query = 1;
  repeated string factors = 2;  // multiple factor that we want to search in query
  int32 page_number = 3;        // page number that we want
  int32 result_per_page = 4;    // number of results to return per page that we want
}

message SearchResponse {

}
```

- 必须在文件正文（非注释、非空行）的 **第一行** 明确`proto`语法标准，上述示例确定语法标准为`proto3`

- `package simple_demo;`为当前文件声明 **包名**，编译该`.proto`文件生成的 C++ 代码中，`simple_demo`为 **其命名空间**

- Message 中的每个字段至少包含 “类型”、“名称”、“字段号”，即`[Field Value Type] [Field Name] = [Field Number];`

- `repeated`关键字表示该字段出现 0 次或多次（类似 C++ 中的`std::vector`），未使用该关键字的字段出现 0 次或 1 次（`singular`类型）

- 多个 Message 可以被定义在同一个`.proto`文件中（也可以通过`import`语法引用其他文件中的 Message）

- `proto`语法支持 C/C++ 风格的注释，即`//...`和`/*...*/`

- 建议使用 **大驼峰** 规范为 Message 命名

##### 1.3.1.1. Field Types

Message 基础数据类型与 C++ 的基础数据类型的对应关系如下：

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
| `sfixed32` | 比`uint32`更高效地编码其值总是 4 字节的数 | `int`<br>`int32_t` |
| `sfixed64` | 比`uint32`更高效地编码其值总是 8 字节的数 | `int64_t` |
| `bool` | 布尔类型 | `bool` |
| `string` | 始终包含`UTF-8`编码或 7 位`ASCII`编码的字节序列，并且长度不能超过`2 ^ 32` | `std::__cxx11::string` |
| `bytes` | 可以包含不超过`2 ^ 32`的任意字节序列 | `std::__cxx11::string` |

##### 1.3.1.2. Field Names

- Message 中字段的命名规则与 C/C++ 变量（对象、字段）命名规则一致

- 建议使用 **下划线分隔** 的方式为字段命名，如`result_per_page`、`page_1`、`page_2`（优势：与生成的 C++ API 中的名称保持一致）

- 建议使用 **复数** 的方式为`repeated`修饰的字段命名，如`factors`

##### 1.3.1.3. Field Numbers

- 在一个 Message 内，每个字段都有 **唯一** 的字段号，**不可重复**

- 字段号使用后，更改要 **慎重**（多人共用同一个`.proto`时可能会出现问题）

- 不同于 ENUM 类型中有且必须有字段号`0`，Message 类型中可用的字段号的范围是`[1, 19000) U (19999, 2 ^ 29 - 1]`（其中`[19000, 19999]`被 Protocol Buffers 保留）

- 字段号范围为`[1, 15]`的字段需要 1 个字节来编码，为频繁出现的字段分配这些字段号可以优化编码

- 字段号范围为`[2, 2 ^ 11 - 1]`的字段需要 2 个字节来编码

- 其他字段号范围的字段的编码规则参考 *[Encoding Guide](https://developers.google.com/protocol-buffers/docs/encoding)*

##### 1.3.1.4. Default Values

Protocol Buffers 编码（序列化） Message 时，某些字段的值未指定，那么解析（反序列化）时，生成的 Message 中的相应字段将设置为该字段的默认值。各个数据类型的默认值如下：

| proto 数据类型 | 默认值（对应 C++ ） |
| :-: | :-: |
| `string` | 空的`std::__cxx11::string` |
| `bytes` | 空的`std::__cxx11::string` |
| `bool` | `false` |
| 数字类型 | `0` |
| 枚举类型 | 第一个枚举值（字段号必须为`0`）

##### 1.3.1.5. Nested Types

Protocol Buffers 支持在 Message a 中嵌套定义并使用另一个 Message b（Message b 也可以继续嵌套定义其他 Message ），如下示例所示:

```protobuf
syntax = "proto3";

message SearchResponse {
  message Result {
    string url = 1;
    string title = 2;
    repeated string snippets = 3;
  }
  repeated Result results = 1;
}
```

Protocol Buffers 允许在 Message a 中使用已经定义好的 Message b 及 b 嵌套定义的 Message c（**定义顺序不影响编译**），如下示例所示:

```protobuf
syntax = "proto3";

message SearchResponse {
  repeated Result results = 1;
  ExtraInfo.Error error = 2;
  ExtraInfo.Time  timestamp = 3;
}

message Result {
  string url = 1;
  string title = 2;
  repeated string snippets = 3;
}

message ExtraInfo {
  message Error {
    uint32 code = 1;
    string note = 2;
  }
  message Time {
    uint64 timestamp_u64 = 1;
    string timestamp_str = 2;
  }
}
```

##### 1.3.1.6. Enumerations

Protocol Buffers 支持通过使用`enum`关键字定义枚举类型，示例如下：

```protobuf
syntax = "proto3";

message SearchRequest {
  string query = 1;
  int32 page_number = 2;
  int32 result_per_page = 3;
  enum Corpus {
    UNIVERSAL = 0;
    WEB = 1;
    IMAGES = 2;
    LOCAL = 3;
    NEWS = 4;
    PRODUCTS = 5;
    VIDEO = 6;
  }
  Corpus corpus = 4;
}
```
- ENUM 中的每个字段至少包含 “枚举常量”、“字段号”，即`[Constant] = [Field Number];`

- 每个 ENUM 有且必须有一个字段号为 0 的枚举常量作为其第一个枚举常量，同时也是其 **默认值**

Protocol Buffers 支持使用已存在的枚举常量，通过为枚举类型创建别名来实现，即设置`allow_alias = true`。示例如下：

```protobuf
syntax = "proto3";

message MyMessage1 {
  enum EnumAllowingAlias {
    option allow_alias = true;
    UNKNOWN = 0;
    STARTED = 1;
    RUNNING = 2;
  }
}
message MyMessage2 {
  enum EnumNotAllowingAlias {
    UNKNOWN = 0;
    STARTED = 1;
//  RUNNING = 1;    // Uncommenting this line will cause
                    // a compile error inside Google and
                    // a warning message outside.
  }
}
```

##### 1.3.1.7. Maps

Protocol Buffers 支持使用 Maps，示例如下：

```protobuf
syntax = "proto3";

message Project {
  string name = 1;
  string repository_url = 2;
  repeated string authors = 3;
}

message TestMsg {
  map<uint32, Project> id_2_project = 1;
}
```

- map 字段不能被`repeated`关键字修饰

- map 是无序的

#### 1.3.2. Importing Message

Protocol Buffers 允许使用定义在其他`.proto`文件中的 Message，通过使用`import`语句导入相应的`.proto`来实现。示例如下：

```protobuf
// project/src/proto/route_guide.proto

syntax = "proto3";

message Point {
    int32 latitude = 1;
    int32 longitude = 2;
}
```

```protobuf
// project/doc/test_import.proto

syntax = "proto3";
import public "../src/proto/route_guide.proto";

message TestMsg {
  repeated routeguide.Point points = 1;
}
```

- 在使用`import`语句时，`public`关键字不是必须的

- 使用`public`意味 **依赖关系可以传递**，例如：b.proto 中 `import public "a.proto";`，c.proto 中 `import "b.proto";`，那么在 c.proto 中可以直接使用 a.proto 中定义的 Message

#### 1.3.3. Updating Message

随着开发的推进，`.proto`文件将被频繁修改，如果你已经在 C++ 代码中使用了访问其中 Message 的 API，那么可能会出现一些问题（某些 API 会消失、更新）。当开发团队本应共用相同的`.proto`文件，但各自的内容却不一致时，问题会更复杂。

最简单的解决办法就是永远和团队在`.proto`的内容上保持一致，但这其实很难。遵循下述的 **更新规则** 和 **更新建议** 可以尽量减少团队的麻烦：

- **不要修改** 已存在字段的字段号

- 如果在`.proto`中添加新字段，仍可以使用新生成的 C++ 代码来解析旧的`.proto`生成的 C++ 代码序列化的 Message。同样，由新代码创建的 Message 可也以被旧代码解析（新字段会被忽略，标记为`Unknown Fields`）

- 字段可以被移除，该字段号 **不该** 再被使用。使用`reserved`关键字可以保证`.proto`的其他使用者无法再使用此字段号，例如：`reserved 2;`、`reserved 15, 9 to 11;`、`reserved "foo", "bar";`

- `int32`、`uint32`、`int64`、`uint64`以及`bool`类型彼此兼容，所以可以修改字段从一种类型到另一种类型（位数不同会被截断）

- `sint32`与`sint64`类型兼容（与其他数字类型不兼容）

- `fixed32`与`sfixed32`类型兼容

- `fixed64`与`sfixed64`类型兼容

- 当字节序列是`UTF-8`编码方式时，`string`与`bytes`类型兼容

- `int32`、`uint32`、`int64`、`uint64`以及 枚举常量 彼此兼容（不建议如此修改）

#### 1.3.4. JSON Mapping

`proto3`版本的 Protocol Buffers 支持 Message 格式数据与 JSON 格式数据互相映射，从而使在团队间共享数据更加容易。

`proto3`的数据类型与`JSON`的数据类型存在如下的映射关系：

| proto3 | JSON | 示例 | 备注 |
| :-- | :-- | :-- | :-- |
| `message` | `object` | `{"fooBar1": v1, "fooBar2": v2, ...}` | `Message`映射<br>为`object`后<br>，其字段命名<br>遵循为 **小驼峰** <br>规范 |
| `enum` | `string` | `"FOO_BAR"` |  |
| `map<K, V>` | `object` | `{"k1": v1,<br> "k2": v2, ...}` | `map`中的所有<br>的`key`映射为<br>`string` |
| `repeated V` | `array` | `[v1, v2, ...]` | 空的`repeated`<br>字段映射为值是<br>`null`的`array` |
| `bool` | `true`,<br>`false` | `true`,<br>`false` |  |
| `string` | `string` | `"Hello World!"` |  |
| `bytes` | `base64 string` | `"YWJoKSctPUB+"` | `bytes`值映射<br>为带有填充的<br>标准`base64`编<br>码的`string` |
| `int32`,<br>`fixed32`,<br>`uint32` | `number` | `1`,<br>`-10`,<br>`0` |  |
| `int64`,<br>`fixed64`,<br>`uint64` | `string` | `"1"`,<br>`"-10"`,<br>`"0"` | 64 位数字类<br>型映射结果为<br>`string` |
| `float`,<br>`double` | `number` | `1.1`,<br>`-10.0`,<br>`0`,<br>`"NaN"`,<br>`"Infinity"`,<br>`"-Infinity"` | 浮点型映射<br>结果可能为<br>数字或值是<br>`"NaN"`、<br>`"Infinity"`、<br>`"-Infinity"`<br>的`string` |

相关的 C++ API 声明在`google/protobuf/util/json_util.h`中：

```c++
// google/protobuf/util/json_util.h

namespace google::protobuf::util {

    /**
     * Convert proto to JSON
     */
    util::Status 
    util::MessageToJsonString(const Message &message,
                              std::string *output,
                              const JsonOptions &options);
    
    /**
     * Convert JSON to proto
     */
    util::Status 
    util::JsonStringToMessage(StringPiece input,
                              Message *message,
                              const JsonParseOptions &options);
}
```

#### 1.3.5. Compiling Proto Files

Protocol Buffers 的编译器`protoc`默认编译生成 C++ 源代码文件。

确认已经正确安装 Protocol Buffers（参考 [Protocol Buffers 源码编译安装指南](./0-install-guide.md#1-protocol-buffers)），编译`.proto`文件生成 C++ API 文件（`.cc`、`.h`）方式如下：

```shell
<PROTOBUF_INSTALL_DIR>/bin/protoc      \
    -I --proto_path=<IMPORT_PATH>   \
    --cpp_out=<DST_DIR>             \
    <PROTOBUF_FILENAME_1> <PROTOBUF_FILENAME_2> ...
```

示例：

```shell
pushd /data1/duruyao/project/proto-grpc-demo &&     \
mkdir -p src/proto/gen &&                           \
/data1/duruyao/HikSDK/proto/bin/protoc              \
    -I --proto_path=./src/proto                     \
    --cpp_out=./src/proto/gen route_guide.proto &&  \
ls ./src/proto/gen && popd
```

选择合适的 Protcol Buffers 的编译器`protoc`，也可以编译生成其他编程语言的源代码文件。

确认已经正确安装 **支持多语言** 版本的 Protocol Buffers，编译`.proto`文件生成 多语言 API 文件方式如下：

```shell
<PROTOBUF_INSTALL_DIR>/bin/protoc      \
    -I --proto_path=<IMPORT_PATH>   \
    --cpp_out=<DST_DIR>             \
    --java_out=<DST_DIR>            \
    --python_out=<DST_DIR>          \
    --go_out=<DST_DIR>              \
    --ruby_out=<DST_DIR>            \
    --objc_out=<DST_DIR>            \
    --csharp_out=<DST_DIR>          \
    <PROTOBUF_FILENAME_1> <PROTOBUF_FILENAME_2> ...
```

#### 1.3.6. CPP API

我们从一个简单的示例出发介绍常用的 C++ API：

```protobuf
// project/src/proto/addressbook.proto

syntax = "proto3";

package tutorial;

message Person {
  string name = 1;
  int32 id = 2;
  string email = 3;

  enum PhoneType {
    MOBILE = 0;
    HOME = 1;
    WORK = 2;
  }

  message PhoneNumber {
    string number = 1;
    PhoneType type = 2;
  }

  repeated PhoneNumber phones = 4;
}

message AddressBook {
  repeated Person people = 1;
}
```

编译上述的`addressbook.proto`将生成`addressbook.pb.cc`、`addressbook.pb.h`。相应的 C++ API 如下：

```c++
// project/src/proto/gen/addressbook.pb.h

namespace tutorial {

    //// name

    // Check if the 'name' filed is not empty.
    inline bool has_name() const;
    // Reset the 'name' filed to default value.
    inline void clear_name();
    // Get value of the 'name' filed.
    inline const ::std::string& name() const;
    // Set value of the 'name' filed.
    inline void set_name(const ::std::string& value);
    // Set value of the 'name' filed.
    inline void set_name(const char* value);
    //Return a pointer points to the 'name' filed.
    inline ::std::string* mutable_name();
 
    //// id

    inline bool has_id() const;
    inline void clear_id();
    inline int32_t id() const;
    inline void set_id(int32_t value);  

    //// email

    inline bool has_email() const;
    inline void clear_email();
    inline const ::std::string& email() const;
    inline void set_email(const ::std::string& value);
    inline void set_email(const char* value);
    inline ::std::string* mutable_email();  

    //// phones

    // Get number of element of the 'phones' filed.
    inline int phones_size() const;
    inline void clear_phones();
    inline const ::google::protobuf::
                    RepeatedPtrField<::tutorial::Person_PhoneNumber >& phones() const;
    inline ::google::protobuf::
                    RepeatedPtrField< ::tutorial::Person_PhoneNumber >* mutable_phones();
    // Get value of element of the 'phones' filed.
    inline const ::tutorial::Person_PhoneNumber& phones(int index) const;
    // Return a pointer points to element of the 'phones' filed.
    inline ::tutorial::Person_PhoneNumber* mutable_phones(int index);
    // Add a new element to the 'phones' filed, and return the pointer points to the new.
    inline ::tutorial::Person_PhoneNumber* add_phones();

}
```

在 C++ 代码中使用上述 API 的示例如下：

```c++
#include <string>
#include <fstream>
#include <iostream>

#include "addressbook.pb.h"

using tutorial::Person;
using tutorial::PhoneType;
using tutorial::PhoneNumber;
using tutorial::AddressBook;

void ListPeople(const AddressBook &address_book) {
    for (int i = 0; i < address_book.people_size(); i++) {
        const Person &person = address_book.people(i);

        std::cout << "Person ID: " << person.id() << std::endl;
        std::cout << "Name: " << person.name() << std::endl;
        if (person.has_email()) {
            std::cout << "E-mail address: " << person.email() << std::endl;
        }

        for (int j = 0; j < person.phones_size(); j++) {
            const Person::PhoneNumber &phone_number = person.phones(j);

            switch (phone_number.type()) {
                case Person::MOBILE:
                    std::cout << "Mobile phone #: ";
                    break;
                case Person::HOME:
                    std::cout << "Home phone #: ";
                    break;
                case Person::WORK:
                    std::cout << "Work phone #: ";
                    break;
            }
            std::cout << phone_number.number() << std::endl;
        }
    }
}
```

### 1.4. Demo Project

参考首页的 [Demo Project](../README.md#2-demo-project)。

---

## 2. gRPC

### 2.1. Introduction

### 2.2. Install

### 2.3. Usage
