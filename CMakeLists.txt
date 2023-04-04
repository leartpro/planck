cmake_minimum_required(VERSION 3.8)
project(planck)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        planck
        src/main.cpp
        src/Lexer.cpp
        src/AST.cpp
        src/Parser.cpp
        src/Interpreter.cpp
        src/Token.cpp)
