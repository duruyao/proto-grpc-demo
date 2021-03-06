################################################################################
#       USING PROTOCOL BUFFERS                                                 #
################################################################################

if (NOT DEFINED USE_PROTO_CMAKE)
    set(USE_PROTO_CMAKE)

    include(${PROJECT_SOURCE_DIR}/tools/cmake/use_hiksdk.cmake)

    if (WIN32)
        ## TODO: set proto_home
        ##
    elseif (UNIX AND NOT APPLE)
        set(proto_home ${HIKSDK_DIR}/proto)
        set(proto_bin_dir ${proto_home}/bin)
        set(proto_lib_dir ${proto_home}/lib)
        set(proto_include_dir ${proto_home}/include)

        list(APPEND CMAKE_PREFIX_PATH ${proto_home}/cmake)
        list(APPEND CMAKE_PREFIX_PATH ${proto_home}/lib/cmake)

        link_directories(${proto_lib_dir})
        include_directories(SYSTEM ${proto_include_dir})
    else (APPLE)
        ## TODO: set proto_home
        ##
    endif ()

    if (DEFINED proto_in_dir AND DEFINED proto_out_dir)
        ## make dir for `*.pb.cc`, `*.pb.h` files generated by `protoc`
        file(MAKE_DIRECTORY ${proto_out_dir})

        ## get all `*.proto` files
        file(GLOB proto_all_files CONFIGURE_DEPENDS "${proto_in_dir}/*.proto")
        list(APPEND proto_files ${proto_all_files})

        add_custom_command(OUTPUT proto_gen_files
                COMMAND ${proto_bin_dir}/protoc -I ${proto_in_dir} --cpp_out=${proto_out_dir} ${proto_files}
                DEPENDS ${proto_files}
                )

        add_custom_target(proto_2_cxx DEPENDS proto_gen_files)
    else ()
        message(ERROR "include 'use_proto.cmake' without defining 'proto_in_dir' or 'proto_out_dir'")
    endif ()

    list(APPEND third_party_libs protobuf)

endif (NOT DEFINED USE_PROTO_CMAKE)
