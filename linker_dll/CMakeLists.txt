cmake_minimum_required(VERSION 3.16)

project(linker_dll)

set(linker_src
     ${CMAKE_CURRENT_SOURCE_DIR}/../linker/dlltoexe.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../linker/image_util.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../linker/linker.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../linker/std.cpp
)

set(linker_stdutil_src
     ${CMAKE_CURRENT_SOURCE_DIR}/../stdutil/stdutil.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../stdutil/stdutil.h
)

add_library(linker SHARED
                ${linker_stdutil_src}
                ${linker_src}
	linker_dll.cpp
)

target_compile_options(linker PRIVATE /Gz)




