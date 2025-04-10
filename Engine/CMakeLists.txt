#add_library(rengine)


set(RENGINE_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/Include)
#target_include_directories(rengine PUBLIC ${RENGINE_INCLUDE_DIRS} ${SFML_INCLUDE_DIR})
#target_link_libraries(rengine PRIVATE sfml-graphics sfml-audio sfml-network)

add_library(rengine-core
        Source/Core/Color.cpp
        Source/Core/Log.cpp
        Source/Core/EventSystem.cpp)

set_target_properties(rengine-core PROPERTIES PREFIX "")
target_include_directories(rengine-core PUBLIC ${RENGINE_INCLUDE_DIRS} ${SFML_INCLUDE_DIR})
target_link_libraries(rengine-core PRIVATE sfml-graphics)

add_library(rengine-input
        Source/Input/Devices/Keyboard.cpp)

set_target_properties(rengine-input PROPERTIES PREFIX "")
target_include_directories(rengine-input PUBLIC ${RENGINE_INCLUDE_DIRS} ${SFML_INCLUDE_DIR})
target_link_libraries(rengine-input PRIVATE sfml-window)


add_library(rengine-af
        Source/Application/Bootstrapper.cpp
        Source/Application/Resolution.cpp
        Source/Application/Window.cpp)

set_target_properties(rengine-af PROPERTIES PREFIX "")
target_include_directories(rengine-af PUBLIC ${RENGINE_INCLUDE_DIRS} ${SFML_INCLUDE_DIR})
target_link_libraries(rengine-af PRIVATE rengine-core sfml-graphics)
