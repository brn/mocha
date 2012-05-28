#!/bin/sh

readonly CURRENT=`pwd`;
readonly DEPS_DIR=${CURRENT}/src/.deps/${1}
readonly PLATFORM=$1
readonly V8_LIB=$2
readonly UV_LIB=$3
readonly UV_LOC=$4

#Make tarball and move to src/.libtmp
PackAndStaging()
{
    tar -czf ${1}.tar.gz $1
    mv -v ${1}.tar.gz ../.libtmp
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
        echo "======STAGING ICU======"
        PackAndStaging icu
    fi

    if [ ! -d ${TMP_DIRNAME}/libedit ]; then
        echo "======STAGING LIBEDIT======"
        PackAndStaging libedit
    fi

    if [ ! -d ${TMP_DIRNAME}/v8 ]; then
        echo "======STAGING V8======"
        PackAndStaging v8
    fi

    if [ ! -d ${TMP_DIRNAME}/libuv ]; then
        echo "======STAGING LIVUV======"
        PackAndStaging libuv
    fi
    cd ../../
}


BuildLibEdit()
{
    if [ ! -d ${DEPS_DIR}/libedit -o ! -f ${DEPS_DIR}/libedit/libedit.a ]; then
        echo "======BUILD LIBEDIT======"
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
        echo "======BUILD ICU======"
        mkdir -p ${DEPS_DIR}/icu/include/
        cd src/.libtmp/icu/source
        echo `pwd`
        if [ "${PLATFORM}" = "macos" ]; then
            ./runConfigureICU MacOSX --enable-static --disable-shared 
            ./configure --enable-static --disable-shared
        elif [ "${PLATFORM}" = "linux" ]; then
            ./configure --enable-static --disable-shared
        fi
        make
        cp -r common/unicode ${DEPS_DIR}/icu/include/
        cp i18n/unicode/*.h ${DEPS_DIR}/icu/include/unicode/
        cp lib/*.a ${DEPS_DIR}/icu/
        make clean
        cd ../../../../
    fi
}

BuildV8()
{
    if [ ! -d ${DEPS_DIR}/v8 -o ! -f ${DEPS_DIR}/v8/libv8.a ]; then
        echo "======BUILD V8======"
        if [ ! -d ${DEPS_DIR}/v8 ]; then
            mkdir -p ${DEPS_DIR}/v8/
        fi
        cd src/.libtmp/v8
        if [ "${PLATFORM}" = "macos" ]; then
            scons arch=x64
        elif [ "${PLATFORM}" = "linux" ]; then
            scons
        fi
        cp $V8_LIB ${DEPS_DIR}/v8
        cp -r include ${DEPS_DIR}/v8
        scons --clean
        cd ../../../
    fi
}

CopyLibUV()
{
    cp ${UV_LOC} ${DEPS_DIR}/libuv/
    cp -r include ${DEPS_DIR}/libuv/include
}

BuildLibUV()
{
    if [ ! -d ${DEPS_DIR}/libuv ]; then
        echo "======BUILD LIBUV======"
        mkdir -p ${DEPS_DIR}/libuv/
    fi
    cd src/.libtmp/libuv/
    if [ ! -f ${DEPS_DIR}/libuv/${UV_LIB} ]; then
        if [ "${PLATFORM}" = "macos" ]; then
            ./gyp_uv -f xcode
            xcodebuild -project uv.xcodeproj -configuration Release -target All ARCHS="x86_64"
            CopyLibUV
            xcodebuild clean
        elif [ "${PLATFORM}" = "linux" ]; then
            ./gyp_uv -f make
            make
            CopyLibUV
            make clean
        fi
    fi
    cd ../../../
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

