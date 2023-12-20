cmake_minimum_required(VERSION 3.10)

project(ExamplesLibrary C)

set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES src/ex1.c)
set(HEADER_FILES include/ex1.h)

add_library(examples-lib ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(examples-lib PUBLIC ${HEADERS_DIR})