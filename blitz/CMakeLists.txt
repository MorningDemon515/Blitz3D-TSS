cmake_minimum_required (VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)

project (blitz)

set(CMAKE_CXX_FLAGS_DEBUG "/MTd /Z7 /Od /RTC1")   
set(CMAKE_CXX_FLAGS_RELEASE "/MT /O2")  

set(blitz_src 
      ${CMAKE_CURRENT_SOURCE_DIR}/libs.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/libs.h
      ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

set(compiler_src
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/assem_x86/asm_insts.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/assem_x86/assem_x86.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/assem_x86/operand.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/codegen_x86/codegen_x86.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/codegen_x86/tile.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/compiler.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/decl.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/declnode.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/environ.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/exprnode.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/node.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/parser.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/prognode.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/std.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/stmtnode.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/toker.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/type.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/varnode.cpp

      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/assem_x86/assem_x86.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/assem_x86/insts.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/assem_x86/operand.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/codegen_x86/codegen_x86.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/codegen_x86/tile.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/assem.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/codegen.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/compiler.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/decl.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/declnode.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/environ.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/ex.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/exprnode.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/label.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/node.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/nodes.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/parser.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/prognode.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/std.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/stmtnode.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/stringmap.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/toker.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/type.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/var.h
      ${CMAKE_CURRENT_SOURCE_DIR}/../compiler/varnode.h
)

set(blitz_stdutil_src
     ${CMAKE_CURRENT_SOURCE_DIR}/../stdutil/stdutil.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/../stdutil/stdutil.h
)

add_executable(blitzcc
       ${blitz_stdutil_src}
       ${compiler_src}
       ${blitz_src}
)

target_link_libraries(blitzcc PRIVATE
           odbc32.lib
           odbccp32.lib
)

target_compile_options(blitzcc PRIVATE /Gz)

target_compile_definitions(blitzcc PRIVATE
    $<$<CONFIG:Debug>:WIN32;_DEBUG;PRO;_CONSOLE>
    $<$<CONFIG:Release>:WIN32;NDEBUG;PRO;_CONSOLE;_HAS_STD_BYTE=0;_NO_DEBUG_HEAP=1>
)

