include(${CMAKE_SOURCE_DIR}/Rengine.cmake)

add_rengine_library(MT
        SOURCES
                Runtime/Source/JobSystem.cxx

        PUBLIC_INCLUDES
                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Runtime/Include>

        PUBLIC_DEPENDENCIES
                rengine-core
)

#add_rengine_library(MT-Editor)
#       SOURCES
#)
