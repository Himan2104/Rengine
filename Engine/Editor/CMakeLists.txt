include(${CMAKE_SOURCE_DIR}/Rengine.cmake)

add_rengine_library(Editor
        SOURCES
                Source/EditorUI.cxx

        PUBLIC_INCLUDES
                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include>

        PUBLIC_DEPENDENCIES
                Rengine::Core
                Rengine::GFX
                ImGui-SFML::ImGui-SFML
)

