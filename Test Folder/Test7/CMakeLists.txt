#CMakeLists.txt

#Minimum CMake version required(The project requires at least CMake version 3.12.)
cmake_minimum_required(VERSION 3.12)

#It defines Project Information:
#- Project name → test
#- Project version → 1.0
#- Programming language → CXX = C++
project(test VERSION 1.0 LANGUAGES CXX)
#Compile the project using the C++17 standard.
set(CMAKE_CXX_STANDARD 17)
#C++17 is required. Do not silently fall back to an older C++ standard.
#C++17 Not optional it is requirement.
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#"1. Define header file locations"
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#2. "GLOB_RECURSE searches recursively for files matching a pattern."
#2. "Find all .cpp files inside src and all of its subdirectories."
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

# 3. "Building the Executable File"
add_executable(${PROJECT_NAME} ${SOURCES})