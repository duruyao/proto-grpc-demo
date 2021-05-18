#! /bin/bash

## https://github.com/google/re2/releases

zip_dir="${PWD}/re2-2021-04-01.zip"
new_folder="${PWD}/re2_source"
HIKSDK_DIR="/data1/duruyao/HikSDK"

mkdir -p ${new_folder} && rm -rf ${new_folder}/*
unzip -q ${zip_dir} -d ${new_folder}

src_dir="${new_folder}/`ls ${new_folder}`"
makefile_dir="${src_dir}/MakeFile"
ins_dir="${HIKSDK_DIR}/re2"
old_ins_dir="/usr/local"

mkdir -p ${ins_dir} && rm -rf ${ins_dir}/*
cd ${src_dir}

## modify `prefix="/data1/duruyao/HikSDK/re2"` in `MakeFile`
sed -i "s/\/usr\/local/\/data1\/duruyao\/HikSDK\/re2/g" `grep "\/usr\/local" -rl `

make -j16 && make install

