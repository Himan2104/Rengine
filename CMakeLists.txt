cmake_minimum_required(VERSION 3.27)

project(Rengine VERSION 0.1.4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
option(REN_DEBUG "Enable debug mode" OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(REN_DEBUG)
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_definitions(REN_RELEASE)
endif()

add_compile_definitions(REN_VERSION=${PROJECT_VERSION})
add_compile_definitions(REN_VERSION_MAJOR=${PROJECT_VERSION_MAJOR})
add_compile_definitions(REN_VERSION_MINOR=${PROJECT_VERSION_MINOR})
add_compile_definitions(REN_VERSION_PATCH=${PROJECT_VERSION_PATCH})

#dependencies
add_subdirectory(External/SFML)
set(SFML_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/External/SFML/include)

add_subdirectory(Engine)
add_subdirectory(Demo)
