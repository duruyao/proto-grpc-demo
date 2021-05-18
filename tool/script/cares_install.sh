#! /bin/bash

## https://github.com/c-ares/c-ares/releases

zip_dir="${PWD}/c-ares-cares-1_17_1.zip"
new_folder="${PWD}/cares_source"
HIKSDK_DIR="/data1/duruyao/HikSDK"

mkdir -p ${new_folder} && rm -rf ${new_folder}/*
unzip -q ${zip_dir} -d ${new_folder}

src_dir="${new_folder}/`ls ${new_folder}`"
ins_dir="${HIKSDK_DIR}/cares"

mkdir -p ${ins_dir} && rm -rf ${ins_dir}/*
cd ${src_dir}
./buildconf
autoconf configure.ac
./configure --prefix=${ins_dir}
make -j16 && make install

