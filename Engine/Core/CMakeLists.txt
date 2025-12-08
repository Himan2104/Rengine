include(${CMAKE_SOURCE_DIR}/Rengine.cmake)

add_rengine_library(Core
        SOURCES
                Runtime/Source/Color.cxx
                Runtime/Source/EventSystem.cxx
                Runtime/Source/Log.cxx

        PUBLIC_INCLUDES
                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Runtime/Include>

        PUBLIC_DEPENDENCIES
                SFML::Graphics
                SFML::System
)

#add_rengine_library(Core-Editor)
#       SOURCES
#)
