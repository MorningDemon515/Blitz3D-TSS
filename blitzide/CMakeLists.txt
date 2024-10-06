cmake_minimum_required (VERSION 3.16)

project (blitzide)

set(CMAKE_CXX_STANDARD 20)

set(ide_src 
     ${CMAKE_CURRENT_SOURCE_DIR}/about.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/blitzide.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/editor.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/funclist.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/htmlhelp.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/libs.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/mainframe.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/prefs.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/stdafx.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/tabber.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/blitzide.rc
)

add_compile_options(
        $<$<CONFIG:Debug>:/MTd> 
        $<$<CONFIG:Release>:/MT> 
    ) 

add_executable(ide ${ide_src})

target_link_libraries(ide
                        winmm.lib
)

target_compile_options(ide PRIVATE /Gz)

set_target_properties(ide PROPERTIES LINK_FLAGS "/ENTRY:WinMainCRTStartup")


