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

function(copy_dll_to_install target dst)
	set(SRC $<TARGET_FILE_DIR:${target}>/${target}.dll)
	set(DST ${CMAKE_SOURCE_DIR}/_release/${dst}.dll)
	add_custom_command(TARGET ${target} POST_BUILD VERBATIM
			COMMAND ${CMAKE_COMMAND} -E echo "Copying ${target} output file \"${SRC}\" to \"${DST}\""
			COMMAND ${CMAKE_COMMAND} -E copy ${SRC} ${DST})
endfunction()

copy_dll_to_install(linker bin/linker)





