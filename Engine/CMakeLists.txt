add_library(rengine
        Source/Application/Bootstrapper.cpp
        Source/Application/Resolution.cpp
        Source/Application/Window.cpp
        Source/Core/Color.cpp
        Source/Core/Log.cpp
        Source/Core/EventSystem.cpp)


set(RENGINE_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/Include)
target_include_directories(rengine PUBLIC ${RENGINE_INCLUDE_DIRS} ${SFML_INCLUDE_DIR})
target_link_libraries(rengine PRIVATE sfml-graphics sfml-audio sfml-network)
