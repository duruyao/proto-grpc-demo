#! /bin/bash

## https://github.com/abseil/abseil-cpp/releases

zip_dir="${PWD}/abseil-cpp-master.zip"
new_folder="${PWD}/abseil_source"
HIKSDK_DIR="/data1/duruyao/HikSDK"

mkdir -p ${new_folder} && rm -rf ${new_folder}/*
unzip -q ${zip_dir} -d ${new_folder}

src_dir="${new_folder}/`ls ${new_folder}`"
build_dir="${src_dir}/build"
ins_dir="${HIKSDK_DIR}/absl"

mkdir -p ${build_dir} && rm -rf ${build_dir}/*
mkdir -p ${ins_dir} && rm -rf ${ins_dir}/*
cd ${build_dir}
cmake .. 	-DCMAKE_CXX_FLAGS="-std=c++11"	\
			-DCMAKE_BUILD_TYPE=Release		\
			-DBUILD_SHARED_LIBS=ON			\
			-DCMAKE_INSTALL_PREFIX=${ins_dir}

make -j16 && make install

