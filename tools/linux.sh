#!/bin/sh

`cd ../`

`cd src/lib && mkdir ../.libtmp && cp -v -r icu ../.libtmp && cp -v -r libedit ../.libtmp && cp -v -r v8 ../.libtmp && cp -v -r libuv ../.libtmp && cd ../../`

if [ ! -d src/.depls/linux/icu/include ]; then
    `mkdir -p src/.deps/linux/icu/include/`
fi

if [ ! -d src/.deps/linux/v8 ]; then
    `mkdir -p src/.deps/linux/v8/`
fi

if [ ! -d src/.deps/linux/libuv ]; then
    `mkdir -p src/.deps/linux/libuv/`
fi

if [ ! -d src/.deps/linux/libedit/include ]; then
    `mkdir -p src/.deps/linux/libedit/include`
fi

if [! -d src/.deps/linux/libedit]
    `cd src/.libtmp/libedit-devel/ && ./configure --enable-widec --enable-static && make && cd src && cp histedit.h ../../../.deps/linux/libedit/include && cp .libs/libedit.a ../../../.deps/linux/libedit/ && cd ../ && make clean && cd ../../../`
fi

if [! -d src/.deps/linux/icu]
    `cd src/.libtmp/icu/source && sh ./runConfigure Linux && ./configure --enable-static --disable-shared && make && cp -r common/unicode ../../../.deps/linux/icu/include/ && cp lib/*.a ../../../.deps/linux/icu/ && make clean && cd ../../../../`
fi

if [! -d src/.deps/linux/v8]
    `cd src/.libtmp/v8 && scons && cp libv8.a ../../.deps/linux/v8/ && cp -r include/ ../../.deps/linux/v8/ && scons --clean && cd ../../../`
fi

if [! -d src/.deps/linux/libuv]
    `cd src/.libtmp/libuv/ && ./gyp_uv -f make && make && cp uv.a ../../.deps/linux/libuv/ && cp -r include ../../.deps/linux/libuv/include && make clean && cd ../../../`
fi

