cmake_minimum_required(VERSION 3.16)

project(bbruntime_dll)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_DEBUG "/MTd /Z7 /Od /RTC1")   
set(CMAKE_CXX_FLAGS_RELEASE "/MT /O2")  

set(bbruntime_src
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/basic.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbaudio.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbbank.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbblitz3d.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbfilesystem.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbgraphics.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbinput.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbmath.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbruntime.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbsockets.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbstream.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbstring.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbsys.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbutf8.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/gxdir.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/gxfilesystem.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/runtime.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/std.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/unzip.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/userlibs.cpp

     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/basic.h
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bb_basic.h
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbaudio.h
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbbank.h
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbblitz3d.h
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbfilesystem.h
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbgraphics.h
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbinput.h
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbmath.h
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbruntime.h
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbsockets.h
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbstream.h
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbstring.h
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbsys.h
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/bbutf8.h
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/constants.h
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/gxdir.h
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/gxfilesystem.h
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/resource.h
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/std.h
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/unzip.h
     ${CMAKE_CURRENT_SOURCE_DIR}/../bbruntime/userlibs.h
)

set(bbruntime_stdutil_src
     ${CMAKE_CURRENT_SOURCE_DIR}/../stdutil/stdutil.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../stdutil/stdutil.h
)

add_library(runtime SHARED
                ${bbruntime_stdutil_src}
                ${bbruntime_src}
                bbexe.ico
	bbruntime_dll.cpp
                bbruntime_dll.h
	bbruntime_dll.rc
                resource.h
)

target_compile_options(runtime PRIVATE /Gz)

target_link_options(runtime PRIVATE /SUBSYSTEM:WINDOWS)

target_compile_definitions(runtime PRIVATE
    $<$<CONFIG:Debug>:WIN32;_DEBUG;PRO;_CONSOLE>
    $<$<CONFIG:Release>:WIN32;NDEBUG;PRO;_CONSOLE;_HAS_STD_BYTE=0;_NO_DEBUG_HEAP=1>
)

target_link_libraries(runtime
                 wsock32.lib
                 amstrmid.lib
                 winmm.lib
                 dxguid.lib
                 Ws2_32.lib
                 odbc32.lib
                 odbccp32.lib
)

function(copy_dll_to_install target dst)
	set(SRC $<TARGET_FILE_DIR:${target}>/${target}.dll)
	set(DST ${CMAKE_SOURCE_DIR}/_release/${dst}.dll)
	add_custom_command(TARGET ${target} POST_BUILD VERBATIM
			COMMAND ${CMAKE_COMMAND} -E echo "Copying ${target} output file \"${SRC}\" to \"${DST}\""
			COMMAND ${CMAKE_COMMAND} -E copy ${SRC} ${DST})
endfunction()

copy_dll_to_install(runtime bin/runtime)




