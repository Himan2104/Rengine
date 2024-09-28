cmake_minimum_required(VERSION 3.27)

project(Rengine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
option(REN_DEBUG "Enable debug mode" OFF)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(REN_DEBUG)
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_definitions(REN_RELEASE)
endif()

#dependencies
add_subdirectory(External/SFML)
set(SFML_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/External/SFML/include)

add_subdirectory(Engine)
add_subdirectory(Demo)