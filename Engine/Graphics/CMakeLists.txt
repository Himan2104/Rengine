include(${CMAKE_SOURCE_DIR}/Rengine.cmake)

add_rengine_library(GFX
        SOURCES
                Runtime/Source/Graphics.cxx
                Runtime/Source/RenderObject.cxx
                Runtime/Source/Renderer.cxx

        PUBLIC_INCLUDES
                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Runtime/Include>

        PUBLIC_DEPENDENCIES
                Rengine::Core
)

#add_rengine_library(GFX-Editor)
#       SOURCES
#)
