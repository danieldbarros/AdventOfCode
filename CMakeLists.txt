cmake_minimum_required(VERSION 3.5)
project(AdventOfCode2023)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set source files directory
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/2023)

# Find all .cpp files in the 2023 folder
file(GLOB_RECURSE SOURCE_FILES "${SOURCE_DIR}/*.cpp")

# Iterate over each source file and create an executable for it
foreach(SOURCE_FILE ${SOURCE_FILES})
    # Get the name of the file without extension
    get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)
    # Create an executable with the same name as the source file
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})
    # Set output directory for the executable
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin
    )
endforeach()