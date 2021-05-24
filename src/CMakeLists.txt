## using proto
set(proto_src_dir ${PROJECT_SOURCE_DIR}/src/proto)          ## set your folder of .proto files as `proto_src_dir`
set(proto_gen_dir ${PROJECT_SOURCE_DIR}/src/proto/gen)      ## generate .cc, .h files to `proto_gen_dir`
include(${PROJECT_SOURCE_DIR}/tools/cmake/use_proto.cmake)

## using grpc
set(grpc_src_dir ${PROJECT_SOURCE_DIR}/src/proto)           ## set your folder of .proto files as `grpc_src_dir`
set(grpc_gen_dir ${PROJECT_SOURCE_DIR}/src/proto/gen)       ## generate .cc, .h files to `grpc_gen_dir`
include(${PROJECT_SOURCE_DIR}/tools/cmake/use_grpc.cmake)

message(STATUS "THIRD_PARTY_LIBS: ${third_party_libs}")

#get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
#foreach (dir ${dirs})
#    message(STATUS "INCLUDE DIR: ${dir}")
#endforeach ()

add_subdirectory(server)
add_subdirectory(client)
