if (WIN32)
    ## TODO: set absl_home
    ##
elseif (UNIX AND NOT APPLE)
    set(absl_home /opt/HikSDK/absl)
    set(absl_include_dir ${absl_home}/include)

    link_directories(${absl_lib_dir})
    include_directories(SYSTEM ${absl_include_dir})
else (APPLE)
    ## TODO: set absl_home
    ##
endif ()
