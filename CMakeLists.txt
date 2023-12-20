cmake_minimum_required(VERSION 3.18)

project(CMakeProject C)

enable_testing()
add_subdirectory(tests/examples)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/examples/include)

add_executable(main main.c)

target_link_libraries(main examples-lib)
add_dependencies(main examples-lib)
