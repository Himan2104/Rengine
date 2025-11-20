#add_library(rengine)


set(RENGINE_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/Include)
#target_include_directories(rengine PUBLIC ${RENGINE_INCLUDE_DIRS} ${SFML_INCLUDE_DIR})
#target_link_libraries(rengine PRIVATE sfml-graphics sfml-audio sfml-network)

add_library(rengine-core
        Source/Core/Color.cxx
        Source/Core/Log.cxx
        Source/Core/EventSystem.cxx)

set_target_properties(rengine-core PROPERTIES PREFIX "")
target_include_directories(rengine-core PUBLIC ${RENGINE_INCLUDE_DIRS} ${SFML_INCLUDE_DIR})
target_link_libraries(rengine-core PRIVATE sfml-graphics sfml-network sfml-audio sfml-window sfml-system sfml-main)

add_library(rengine-input
        Source/Input/Devices/Keyboard.cxx)

set_target_properties(rengine-input PROPERTIES PREFIX "")
target_include_directories(rengine-input PUBLIC ${RENGINE_INCLUDE_DIRS} ${SFML_INCLUDE_DIR})
target_link_libraries(rengine-input PRIVATE sfml-window)


add_library(rengine-af
        Source/Application/Bootstrapper.cxx
        Source/Application/Resolution.cxx
        Source/Application/Window.cxx)

set_target_properties(rengine-af PROPERTIES PREFIX "")
target_include_directories(rengine-af PUBLIC ${RENGINE_INCLUDE_DIRS} ${SFML_INCLUDE_DIR} ${IMGUI_DIR} ${IMGUI_SFML_INC_DIR})
target_link_libraries(rengine-af PRIVATE rengine-core sfml-graphics ImGui-SFML::ImGui-SFML)

add_library(rengine-mt
        Source/Multithreading/JobSystem.cxx)

set_target_properties(rengine-mt PROPERTIES PREFIX "")
target_include_directories(rengine-mt PUBLIC ${RENGINE_INCLUDE_DIRS} ${SFML_INCLUDE_DIR})

add_library(rengine-gfx
        Source/Graphics/Graphics.cxx)

set_target_properties(rengine-gfx PROPERTIES PREFIX "")
target_include_directories(rengine-gfx PUBLIC ${RENGINE_INCLUDE_DIRS} ${SFML_INCLUDE_DIR})
target_link_libraries(rengine-gfx PRIVATE rengine-core sfml-graphics)

add_library(rengine-editor
        Source/Editor/EditorUI.cxx)

set_target_properties(rengine-editor PROPERTIES PREFIX "")
target_include_directories(rengine-editor PUBLIC ${RENGINE_INCLUDE_DIRS} ${SFML_INCLUDE_DIR} ${IMGUI_DIR})
target_link_libraries(rengine-editor PRIVATE rengine-core sfml-graphics ImGui-SFML::ImGui-SFML)
