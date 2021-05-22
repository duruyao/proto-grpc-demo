################################################################################
#       USING ABSEIL                                                           #
################################################################################

include(${PROJECT_SOURCE_DIR}/tools/cmake/use_hiksdk.cmake)

if (WIN32)
    ## TODO: set absl_home
    ##
elseif (UNIX AND NOT APPLE)
    set(absl_home ${HIKSDK_DIR}/absl)
    set(absl_include_dir ${absl_home}/include)

    link_directories(${absl_lib_dir})
    include_directories(SYSTEM ${absl_include_dir})
else (APPLE)
    ## TODO: set absl_home
    ##
endif ()
