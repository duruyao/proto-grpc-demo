## using proto
set(proto_in_dir ${PROJECT_SOURCE_DIR}/src/proto)           ## set your folder of .proto files as `proto_in_dir`
set(proto_out_dir ${PROJECT_SOURCE_DIR}/src/proto/gen)      ## generate .cc, .h files to `proto_out_dir`
include(${PROJECT_SOURCE_DIR}/tools/cmake/use_proto.cmake)

## using grpc
set(grpc_in_dir ${PROJECT_SOURCE_DIR}/src/proto)            ## set your folder of .proto files as `grpc_in_dir`
set(grpc_out_dir ${PROJECT_SOURCE_DIR}/src/proto/gen)       ## generate .cc, .h files to `grpc_out_dir`
include(${PROJECT_SOURCE_DIR}/tools/cmake/use_grpc.cmake)

## using zmq
include(${PROJECT_SOURCE_DIR}/tools/cmake/use_zmq.cmake)

message(STATUS "THIRD_PARTY_LIBS: ${third_party_libs}")

add_subdirectory(server)
add_subdirectory(client)
