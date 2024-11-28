cmake_minimum_required(VERSION 3.22)

project(LearningDesignPatterns CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

set(HEADER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

function(group_header_files_by_directory BASE_DIR)
    file(GLOB_RECURSE ALL_FILES "${BASE_DIR}/*.h")
    foreach(FILE_PATH ${ALL_FILES})
        file(RELATIVE_PATH REL_PATH "${BASE_DIR}" "${FILE_PATH}")
        get_filename_component(FILE_NAME "${REL_PATH}" NAME)
        get_filename_component(FILE_DIR "${REL_PATH}" DIRECTORY)
        string(REPLACE "/" "\\" GROUP_NAME "${FILE_DIR}")
        source_group("Header Files/${GROUP_NAME}" FILES "${FILE_PATH}")
    endforeach()
endfunction()

function(group_source_files_by_directory BASE_DIR)
    file(GLOB_RECURSE ALL_FILES "${BASE_DIR}/*.cpp")
    foreach(FILE_PATH ${ALL_FILES})
        file(RELATIVE_PATH REL_PATH "${BASE_DIR}" "${FILE_PATH}")
        get_filename_component(FILE_NAME "${REL_PATH}" NAME)
        get_filename_component(FILE_DIR "${REL_PATH}" DIRECTORY)
        string(REPLACE "/" "\\" GROUP_NAME "${FILE_DIR}")
        source_group("Source Files/${GROUP_NAME}" FILES "${FILE_PATH}")
    endforeach()
endfunction()

group_header_files_by_directory("${HEADER_DIR}")
group_source_files_by_directory("${SOURCE_DIR}")

# Command Pattern

file(GLOB_RECURSE COMMAND_PATTERN_HEADERS "${HEADER_DIR}/CommandPattern/*.h")
file(GLOB_RECURSE COMMAND_PATTERN_SOURCES "${SOURCE_DIR}/CommandPattern/*.cpp")
add_executable(CommandPattern "test/TestCommandPattern.cpp" "${COMMAND_PATTERN_SOURCES}" "${COMMAND_PATTERN_HEADERS}")
target_include_directories(CommandPattern PUBLIC "${HEADER_DIR}")

# Double Buffer

file(GLOB_RECURSE DOUBLE_BUFFER_HEADERS "${HEADER_DIR}/DoubleBuffer/*.h")
file(GLOB_RECURSE DOUBLE_BUFFER_SOURCES "${SOURCE_DIR}/DoubleBuffer/*.cpp")
add_executable(DoubleBuffer "test/TestDoubleBuffer.cpp" "${DOUBLE_BUFFER_SOURCES}" "${DOUBLE_BUFFER_HEADERS}")
target_include_directories(DoubleBuffer PUBLIC "${HEADER_DIR}")
