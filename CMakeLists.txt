cmake_minimum_required(VERSION 3.16)
project(cdb C)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED Yes)

add_compile_options(-Wall -Wextra -Wpedantic -Wno-unknown-pragmas)


add_executable(cdb main.c

            "include/common.h"
            "src/common.c"

            "include/input_buffer.h"
            "src/input_buffer.c"
        )

target_include_directories(cdb PUBLIC "${PROJECT_SOURCE_DIR}/include")
