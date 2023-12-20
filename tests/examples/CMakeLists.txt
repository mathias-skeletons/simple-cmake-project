cmake_minimum_required(VERSION 3.14)

project(ExamplesLibraryTests
        LANGUAGES C
)

set(CHECK_VERSION 0.15.2)

if(APPLE)
    set(CHECK_LIBRARY "/opt/homebrew/Cellar/check/${CHECK_VERSION}/lib/libcheck.dylib")
    set(CHECK_INCLUDE_DIR "/opt/homebrew/Cellar/check/${CHECK_VERSION}/include")
    include_directories(${CHECK_INCLUDE_DIR})
else ()
    find_package(Check ${CHECK_VERSION} REQUIRED)
endif()

include_directories("../../examples/include")

add_subdirectory("../../examples" ExamplesLibrary)

enable_testing()

set(SOURCE_FILES src/ex1_test.c src/ex2_test.c)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${CHECK_LIBRARY} examples-lib)
add_test(${PROJECT_NAME} ${PROJECT_NAME})