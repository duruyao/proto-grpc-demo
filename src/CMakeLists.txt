## using proto
set(proto_src_dir ${CMAKE_CURRENT_SOURCE_DIR}/proto)        ## set your folder of .proto files as `proto_src_dir`
set(proto_gen_dir ${CMAKE_CURRENT_SOURCE_DIR}/proto/gen)    ## generate .cc, .h files to `proto_gen_dir`
include(${PROJECT_SOURCE_DIR}/tools/cmake/use_proto.cmake)

## using grpc
set(grpc_src_dir ${CMAKE_CURRENT_SOURCE_DIR}/proto)         ## set your folder of .proto files as `grpc_src_dir`
set(grpc_gen_dir ${CMAKE_CURRENT_SOURCE_DIR}/proto/gen)     ## generate .cc, .h files to `grpc_gen_dir`
include(${PROJECT_SOURCE_DIR}/tools/cmake/use_grpc.cmake)

include_directories(${proto_gen_dir})
include_directories(${grpc_gen_dir})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/main)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/service)

AUX_SOURCE_DIRECTORY(${proto_gen_dir} source_files)
AUX_SOURCE_DIRECTORY(${grpc_gen_dir} source_files)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/main source_files)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/service source_files)

message(STATUS "THIRD_PARTY_LIBS: ${third_party_libs}")

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach (dir ${dirs})
    message(STATUS "INCLUDE DIR: ${dir}")
endforeach ()

add_executable(${PROJECT_NAME} ${source_files})

target_link_libraries(${PROJECT_NAME} ${third_party_libs})
