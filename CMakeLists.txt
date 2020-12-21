cmake_minimum_required(VERSION 3.16)
project(cppdb CXX)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED Yes)

add_compile_options(-Wall -Wextra -Wpedantic)


add_executable(cppdb main.cpp
            "include/Common.h"
            "src/Common.cpp"

            "include/InputBuffer.h"
            "src/InputBuffer.cpp"
        )

target_include_directories(cppdb PUBLIC "${PROJECT_SOURCE_DIR}/include")
