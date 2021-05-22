cmake_minimum_required(VERSION 3.0)
project(proto_grpc_demo C CXX)
set(CMAKE_CXX_STANDARD 11)

if (WIN32)
    ##
    ##
elseif (UNIX AND NOT APPLE)
    ##
    ##
elseif (APPLE)
    ##
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
