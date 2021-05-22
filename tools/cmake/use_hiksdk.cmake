################################################################################
#       USING PROTOCOL BUFFERS                                                 #
################################################################################

if (NOT DEFINED USE_HIKSDK_CMAKE)
    set(USE_HIKSDK_CMAKE)

    if (WIN32)
        ## TODO: set HIKSDK_DIR
        ##
    elseif (UNIX AND NOT APPLE)
        set(HIKSDK_DIR /data1/duruyao/HikSDK)
    else (APPLE)
        ## TODO: set HIKSDK_DIR
        ##
    endif ()

endif (NOT DEFINED USE_HIKSDK_CMAKE)
