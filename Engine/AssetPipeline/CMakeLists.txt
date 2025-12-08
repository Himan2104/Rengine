include(${CMAKE_SOURCE_DIR}/Rengine.cmake)

add_rengine_library(AP
        SOURCES
                Runtime/Source/AssetBank.cxx

        PUBLIC_INCLUDES
                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Runtime/Include>

        PUBLIC_DEPENDENCIES
                Rengine::Core
)

#add_rengine_library(AP-Editor)
#       SOURCES
#)
