cmake_minimum_required(VERSION 3.8)
project(planck)

set(CMAKE_CXX_STANDARD 11)

add_executable(planck
        src/main.cpp
        src/lexer/lexer.cpp src/lexer/lexer.h
        src/lexer/token.cpp src/lexer/token.h
        )
