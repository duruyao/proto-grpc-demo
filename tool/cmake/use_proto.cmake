################################################################################
#       USING PROTOCOL BUFFERS                                                 #
################################################################################

if (WIN32)
    ## TODO: set HIKSDK_DIR
    ## TODO: set proto_home
    ##
elseif (UNIX AND NOT APPLE)
    set(HIKSDK_DIR /data1/duruyao/HikSDK)
    set(proto_home ${HIKSDK_DIR}/proto)
    set(proto_bin_dir ${proto_home}/bin)
    set(proto_lib_dir ${proto_home}/lib)
    set(proto_include_dir ${proto_home}/include)

    list(APPEND CMAKE_PREFIX_PATH ${proto_home}/cmake)
    list(APPEND CMAKE_PREFIX_PATH ${proto_home}/lib/cmake)

    link_directories(${proto_lib_dir})
    include_directories(${proto_include_dir})
    include_directories(${proto_gen_dir})
else (APPLE)
    ## TODO: set HIKSDK_DIR
    ## TODO: set proto_home
    ##
endif ()

#set(proto_src_dir ${CMAKE_CURRENT_SOURCE_DIR}/proto)

if (DEFINED proto_src_dir)
    ## make dir for `*.pb.cc`, `*.pb.h` files generated by `protoc`
    set(proto_gen_dir ${proto_src_dir}/gen)
    file(MAKE_DIRECTORY ${proto_gen_dir})

    ## get all `*.proto` files
    file(GLOB proto_all_files CONFIGURE_DEPENDS "${proto_src_dir}/*.proto")
    list(APPEND proto_files ${proto_all_files})

    add_custom_command(OUTPUT proto_gen_files
            COMMAND ${proto_bin_dir}/protoc -I ${proto_src_dir} --cpp_out=${proto_gen_dir} ${proto_files}
            DEPENDS ${proto_files}
            )

    add_custom_target(proto_2_cxx DEPENDS proto_gen_files)
endif ()

list(APPEND 3rd_party_libs protobuf)
