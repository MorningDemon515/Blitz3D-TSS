cmake_minimum_required(VERSION 3.16)

project(Blitz3D)

add_subdirectory(bbruntime_dll)
add_subdirectory(blitz)
add_subdirectory(blitzide)
add_subdirectory(debugger)
add_subdirectory(linker_dll)

add_executable(Blitz3D WIN32
        bblaunch/bblaunch.cpp
        bblaunch/bblaunch.ico
        bblaunch/bblaunch.rc
)

target_compile_options(Blitz3D PRIVATE /Gz)


