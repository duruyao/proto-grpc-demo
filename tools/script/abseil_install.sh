#! /bin/bash

## https://github.com/abseil/abseil-cpp/releases

if [ $# != 2 ]; then
    printf "USAGE (sudo permission may be needed):\n"
	printf "	\`${0} <ZIP_DIR> <INSTALL_DIR>\`\n"
	exit 1;
fi

zip_dir="${1}"
ins_dir="${2}"
new_folder="${PWD}/abseil_source"

mkdir -p ${new_folder} && rm -rf ${new_folder}/*
unzip -q ${zip_dir} -d ${new_folder}

src_dir="${new_folder}/`ls ${new_folder}`"
build_dir="${src_dir}/build"

mkdir -p ${build_dir} && rm -rf ${build_dir}/*
mkdir -p ${ins_dir} && rm -rf ${ins_dir}/*

cd ${build_dir}

## add rpath for the installed lib

cmake ..    -DCMAKE_CXX_FLAGS="-std=c++11"          \
            -DCMAKE_BUILD_TYPE=Release              \
            -DBUILD_SHARED_LIBS=ON                  \
            -DCMAKE_INSTALL_PREFIX=${ins_dir}       \
            -DCMAKE_SKIP_BUILD_RPATH=OFF            \
            -DCMAKE_BUILD_WITH_INSTALL_RPATH=OFF    \
            -DCMAKE_INSTALL_RPATH="${ins_dir}/lib"  \
            -DCMAKE_INSTALL_RPATH_USE_LINK_PATH=ON

make -j16 && make install

