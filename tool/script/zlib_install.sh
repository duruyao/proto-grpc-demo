#! /bin/bash

## https://www.zlib.net/

if [ $# != 2 ]; then
    printf "USAGE (sudo permission may be needed):\n"
	printf "	\`${0} <ZIP_DIR> <INSTALL_DIR>\`\n"
	exit 1;
fi

zip_dir="${1}"
ins_dir="${2}"
new_folder="${PWD}/zlib_source"

mkdir -p ${new_folder} && rm -rf ${new_folder}/*
unzip -q ${zip_dir} -d ${new_folder}

src_dir="${new_folder}/`ls ${new_folder}`"

mkdir -p ${ins_dir} && rm -rf ${ins_dir}/*
cd ${src_dir}

./configure --prefix=${ins_dir}

make -j16 && make install

