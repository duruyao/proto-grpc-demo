#! /bin/bash

## https://www.zlib.net/

zip_dir="${PWD}/zlib1211.zip"
new_folder="${PWD}/zlib_source"
HIKSDK_DIR="/data1/duruyao/HikSDK"

mkdir -p ${new_folder} && rm -rf ${new_folder}/*
unzip -q ${zip_dir} -d ${new_folder}

src_dir="${new_folder}/`ls ${new_folder}`"
ins_dir="${HIKSDK_DIR}/zlib"

mkdir -p ${ins_dir} && rm -rf ${ins_dir}/*
cd ${src_dir}

./configure --prefix=${ins_dir}

make -j16 && make install

