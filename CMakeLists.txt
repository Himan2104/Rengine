cmake_minimum_required(VERSION 3.27)

project(Rengine VERSION 0.1.4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_DEBUG_POSTFIX d)

#option(BUILD_SHARED_LIBS "Build shared libraries" ON)
set(BUILD_SHARED_LIBS ON)
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

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#dependencies
add_subdirectory(External/SFML)
set(SFML_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/External/SFML/include)
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/External/imgui)
set(IMGUI_SFML_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/External/imgui-sfml)
set(IMGUI_SFML_FIND_SFML OFF)
set(IMGUI_SFML_IMGUI_DEMO ON)
add_subdirectory(External/imgui-sfml)

#Rengine
add_subdirectory(Engine)
#add_subdirectory(Demo)

add_subdirectory(GameApplication)
add_subdirectory(EditorApplication)

file(GLOB_RECURSE UT_SOURCES "UnitTests/*.cxx")

add_executable(UnitTests ${UT_SOURCES})
target_link_libraries(UnitTests rengine-core rengine-mt rengine-af)
add_test(NAME UnitTests COMMAND UnitTests)
