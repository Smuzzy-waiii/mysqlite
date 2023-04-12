cmake_minimum_required(VERSION 3.22)
project(mysqlite C)

set(CMAKE_C_STANDARD 11)

include_directories(repl_helper)
include_directories(SQLCompiler)
include_directories(VirtualMachine)

add_executable(mysqlite
        repl_helper/repl_helper.c
        repl_helper/repl_helper.h
        SQLCompiler/SQLCompiler.c
        SQLCompiler/SQLCompiler.h
        VirtualMachine/VirtualMachine.c
        VirtualMachine/VitualMachine.h
        main.c)
