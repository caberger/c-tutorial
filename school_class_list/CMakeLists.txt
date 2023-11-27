cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_COMPILER_ID "GNU")

project(school)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target)
SET(GCC_MALLOC_COMPILE_FLAGS "-fsanitize=address -Wmismatched-new-delete -Wfree-nonheap-object")
SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} ${GCC_MALLOC_COMPILE_FLAGS}")

SET(CMAKE_VERBOSE_NAKEFILE ON)

FILE(GLOB all_sources *.c)
add_executable(school ${all_sources})
