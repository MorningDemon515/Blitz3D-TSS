cmake_minimum_required (VERSION 3.16)

project (debugger)

set(CMAKE_CXX_STANDARD 20)

set(debugger_src 
     ${CMAKE_CURRENT_SOURCE_DIR}/debuggerapp.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/debugtree.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/mainframe.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/prefs.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/sourcefile.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/stdafx.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/stdutil.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/tabber.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/debugger.rc
)

add_compile_options(
        $<$<CONFIG:Debug>:/MTd> 
        $<$<CONFIG:Release>:/MT> 
        /SUBSYSTEM:WINDOWS
    ) 

add_library(debugger SHARED ${debugger_src})

target_link_libraries(debugger
                        winmm.lib
)

target_compile_options(debugger PRIVATE /Gz)

# Need this for MFC based DLLs.
target_compile_definitions(debugger PRIVATE _USRDLL)

function(copy_dll_to_install target dst)
	set(SRC $<TARGET_FILE_DIR:${target}>/${target}.dll)
	set(DST ${CMAKE_SOURCE_DIR}/_release/${dst}.dll)
	add_custom_command(TARGET ${target} POST_BUILD VERBATIM
			COMMAND ${CMAKE_COMMAND} -E echo "Copying ${target} output file \"${SRC}\" to \"${DST}\""
			COMMAND ${CMAKE_COMMAND} -E copy ${SRC} ${DST})
endfunction()

copy_dll_to_install(debugger bin/debugger)
