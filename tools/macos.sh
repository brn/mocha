#!/bin/sh

readonly CURRENT=`pwd`;
readonly DEPS_DIR=${CURRENT}/src/.deps/${1}
readonly V8_LIB=$2
readonly UV_LIB=$3

#Make tarball and move to src/.libtmp
PackAndStaging()
{
    tar -czf ${1}.tar.gz $1
    cp -v -r ${1}.tar.gz ../.libtmp
    cd ../.libtmp
    tar -xvzf ${1}.tar.gz
    cd ../lib
}

Staging()
{
    cd src/lib
    readonly TMP_DIRNAME=${CURRENT}/src/.libtmp
    if [ ! -d $TMP_DIRNAME ]; then
        mkdir -p $TMP_DIRNAME
    fi
    
    if [ ! -d ${TMP_DIRNAME}/icu ]; then
        echo "==STAGING ICU=="
        PackAndStaging icu
    fi

    if [ ! -d ${TMP_DIRNAME}/libedit ]; then
        echo "==STAGING LIBEDIT=="
        PackAndStaging libedit
    fi

    if [ ! -d ${TMP_DIRNAME}/v8 ]; then
        echo "==STAGING V8=="
        PackAndStaging v8
    fi

    if [ ! -d ${TMP_DIRNAME}/libuv ]; then
        echo "==STAGING LIVUV=="
        PackAndStaging libuv
    fi
    cd ../../
}


BuildLibEdit()
{
    if [ ! -d ${DEPS_DIR}/libedit -o ! -f ${DEPS_DIR}/libedit/libedit.a ]; then
        echo "==BUILD LIBEDIT=="
        if [ ! -f ${DEPS_DIR}/libedit ]; then
            mkdir -p ${DEPS_DIR}/libedit/include
        fi
        cd src/.libtmp/libedit/
        ./configure --enable-widec --enable-static
        make
        cd src
        cp histedit.h ${DEPS_DIR}/libedit/include
        cp .libs/libedit.a ${DEPS_DIR}/libedit
        cd ../
        make clean
        cd ../../../
    fi
}

BuildICU()
{
    if [ ! -d ${DEPS_DIR}/icu -o ! -f ${DEPS_DIR}/icu/libicui18n.a -o ! -f ${DEPS_DIR}/icu/libicuuc.a -o ! -f ${DEPS_DIR}/icu/libicudata.a ]; then
        echo "==BUILD ICU=="
        mkdir -p ${DEPS_DIR}/icu/include/
        cd src/.libtmp/icu/source
        ./runConfigureICU MacOSX --enable-static --disable-shared 
        ./configure --enable-static --disable-shared
        make
        cp -r common/unicode ${DEPS_DIR}/icu/include/
        cp lib/*.a ${DEPS_DIR}/icu/
        make clean
        cd ../../../../
    fi
}

BuildV8()
{
    if [ ! -d ${DEPS_DIR}/v8 -o ! -f ${DEPS_DIR}/v8/libv8.a ]; then
        echo "==BUILD V8=="
        if [ ! -d ${DEPS_DIR}/v8 ]; then
            mkdir -p ${DEPS_DIR}/v8/
        fi
        cd src/.libtmp/v8
        scons arch=x64
        cp $V8_LIB ${DEPS_DIR}/v8/
        cp -r include ${DEPS_DIR}/v8/
        scons --clean
        cd ../../../
    fi
}

BuildLibUV()
{
    if [ ! -d ${DEPS_DIR}/libuv -o ! -f ${DEPS_DIR}/libuv/libuv.a ]; then
        echo "==BUILD LIBUV=="
        if [ ! -d ${DEPS_DIR}/libuv ]; then
            mkdir -p ${DEPS_DIR}/libuv/
        fi
        cd src/.libtmp/libuv/
        ./gyp_uv -f xcode
        xcodebuild -arch x86_64 -project uv.xcodeproj -configuration Release -target All
        cp ${UV_LIB} ${DEPS_DIR}/libuv/
        cp -r include ${DEPS_DIR}/libuv/include
        xcodebuild clean
        cd ../../../
    fi
}

All()
{
    echo "**********BEGIN BUILDING LIBS**********"
    Staging
    BuildV8
    BuildLibUV
    BuildICU
    BuildLibEdit
    echo "**********END BUILDING LIBS**********"
}
All

