# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Set project name
project(PointerProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the executable, this takes the source file and output name
add_executable(app main.cpp)

