################################################################################
#       USING ZMQ                                                              #
################################################################################

if (NOT DEFINED USE_ZMQ_CMAKE)
    set(USE_ZMQ_CMAKE)

    include(${PROJECT_SOURCE_DIR}/tools/cmake/use_hiksdk.cmake)

    if (WIN32)
        ## TODO: set zmq_home
    elseif (UNIX AND NOT APPLE)
        set(zmq_home ${HIKSDK_DIR}/zmq)
        set(zmq_lib_dir ${zmq_home}/lib)
        set(zmq_include_dir ${zmq_home}/include)

        list(APPEND CMAKE_PREFIX_PATH ${zmq_home}/cmake)
        list(APPEND CMAKE_PREFIX_PATH ${zmq_home}/lib/cmake)

        link_directories(${zmq_lib_dir})
        include_directories(SYSTEM ${zmq_include_dir})

        set(cppzmq_home ${HIKSDK_DIR}/cppzmq)
        set(cppzmq_include_dir ${cppzmq_home}/include)

        include_directories(SYSTEM ${cppzmq_include_dir})
    else (APPLE)
        ## TODO: set zmq_home
        ##
    endif ()

    list(APPEND third_party_libs zmq)

endif (NOT DEFINED USE_ZMQ_CMAKE)
