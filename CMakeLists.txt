cmake_minimum_required(VERSION 3.22)

project(DesignPatterns CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

set(HEADER_DIR "include")
set(SOURCE_DIR "src")

# Double Buffer

file(GLOB_RECURSE DOUBLE_BUFFER_HEADERS "${HEADER_DIR}/DoubleBuffer/**/*.h")
file(GLOB_RECURSE DOUBLE_BUFFER_SOURCES "${HEADER_DIR}/DoubleBuffer/**/*.cpp")
add_executable(DoubleBuffer "test/TestDoubleBuffer.cpp" "${DOUBLE_BUFFER_SOURCES}" "${DOUBLE_BUFFER_HEADERS}")
target_include_directories(DoubleBuffer PUBLIC "${HEADER_DIR}")
