include_directories(${proto_out_dir})
include_directories(${grpc_out_dir})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

AUX_SOURCE_DIRECTORY(${proto_out_dir} source_files)
AUX_SOURCE_DIRECTORY(${grpc_out_dir} source_files)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} source_files)

set(app_name "client_demo")

add_executable(${app_name} ${source_files})

target_link_libraries(${app_name} ${third_party_libs})
