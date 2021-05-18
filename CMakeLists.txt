cmake_minimum_required(VERSION 2.8)
project(proto_grpc_demo C CXX)
set(CMAKE_CXX_STANDARD 11)

#include_directories(/data1/duruyao/HikSDK/proto/include)
#include_directories(/data1/duruyao/HikSDK/grpc/include)

if (WIN32)
    ## TODO: set HIKSDK_DIR
    ##
elseif (UNIX AND NOT APPLE)
    SET(HIKSDK_DIR /opt/HikSDK)
elseif (APPLE)
    ## TODO: set HIKSDK_DIR
    ##
endif ()

include(CheckFunctionExists)
include(CheckLibraryExists)
include(CheckIncludeFiles)
include(CheckIncludeFile)
include(CheckSymbolExists)
include(CheckStructHasMember)
include(CMakeDependentOption)
include(FindPkgConfig)

add_subdirectory(src)
