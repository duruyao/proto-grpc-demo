################################################################################
#       USING PROTOCOL BUFFERS                                                 #
################################################################################

if (NOT DEFINED USE_HIKSDK_CMAKE)
    set(USE_HIKSDK_CMAKE)

    if (WIN32)
        ## TODO: set HIKSDK_DIR
        ##
    elseif (UNIX AND NOT APPLE)
        cmake_host_system_information(RESULT current_hostname QUERY HOSTNAME)
        if (${current_hostname} STREQUAL "xiaomi-laptop")
            set(HIKSDK_DIR /opt/HikSDK)
        else ()
            set(HIKSDK_DIR /data1/duruyao/HikSDK)
        endif ()
    else (APPLE)
        ## TODO: set HIKSDK_DIR
        ##
    endif ()

endif (NOT DEFINED USE_HIKSDK_CMAKE)
