include(${CMAKE_SOURCE_DIR}/Rengine.cmake)

add_rengine_library(AF
        SOURCES
                Runtime/Source/Bootstrapper.cxx
                Runtime/Source/Resolution.cxx
                Runtime/Source/Window.cxx

        PUBLIC_INCLUDES
                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Runtime/Include>

        PUBLIC_DEPENDENCIES
                Rengine::Core
                SFML::Graphics
                ImGui-SFML::ImGui-SFML
)

#add_rengine_library(AF-Editor)
#       SOURCES
#)
