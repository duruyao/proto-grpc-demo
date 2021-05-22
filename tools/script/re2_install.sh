#! /bin/bash

## https://github.com/google/re2/releases

if [ $# != 2 ]; then
    printf "USAGE (sudo permission may be needed):\n"
	printf "	\`${0} <ZIP_DIR> <INSTALL_DIR>\`\n"
	exit 1;
fi

zip_dir="${1}"
ins_dir="${2}"
new_folder="${PWD}/re2_source"

mkdir -p ${new_folder} && rm -rf ${new_folder}/*
unzip -q ${zip_dir} -d ${new_folder}

src_dir="${new_folder}/`ls ${new_folder}`"
makefile_dir="${src_dir}/MakeFile"
old_ins_dir="/usr/local"

mkdir -p ${ins_dir} && rm -rf ${ins_dir}/*
cd ${src_dir}

## modify `prefix="/opt/HikSDK/re2"` in `MakeFile`
sed -i "s/\/usr\/local/\/opt\/HikSDK\/re2/g" `grep "\/usr\/local" -rl `

make -j16 && make install
