cmake_minimum_required(VERSION 3.12)
project(Menu VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)