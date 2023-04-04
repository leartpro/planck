cmake_minimum_required(VERSION 3.8)
project(planck)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        planck
        src/main.cpp
        src/Lexer.cpp src/Lexer.h
        src/Parser.cpp src/Parser.h
        src/Interpreter.cpp src/Interpreter.h
        src/AST.h
        src/Token.h)
