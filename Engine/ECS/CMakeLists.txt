include(${CMAKE_SOURCE_DIR}/Rengine.cmake)

add_rengine_library(ECS
        SOURCES
                Runtime/Source/Component.cxx
                Runtime/Source/Entity.cxx
                Runtime/Source/EntityManager.cxx
                Runtime/Source/System.cxx

        PUBLIC_INCLUDES
                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Runtime/Include>

        PUBLIC_DEPENDENCIES
                Rengine::Core
)

#add_rengine_library(ECS-Editor)
#       SOURCES
#)
