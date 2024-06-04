cmake_minimum_required(VERSION 3.24)

project(Sum_24_Michael_Calle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(Orca)
add_subdirectory(Sum_24_Michael_Calle)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT BestGame)
