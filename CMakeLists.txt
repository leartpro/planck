cmake_minimum_required(VERSION 3.8)
project(planck)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        planck
        src/planck/AST.h
        src/planck/Token.h
        src/planck/Lexer.cpp src/planck/Lexer.h
        src/planck/Parser.cpp src/planck/Parser.h
        src/planck/Interpreter.cpp src/planck/Interpreter.h
        src/planck/main.cpp
)
add_executable(
        flanck
        src/flanck/flanck.cpp)
