cmake_minimum_required(VERSION 3.16)
project(RaylibProject LANGUAGES CXX C)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find system-installed raylib
find_package(raylib REQUIRED)

# Automatically collect all .cpp and .hpp files inside src/
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.hpp" "src/*.h")

# Define executable with gathered source files
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Include src directory for easy #include "File.hpp" paths
target_include_directories(${PROJECT_NAME} PRIVATE src)

# Link to system raylib
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)