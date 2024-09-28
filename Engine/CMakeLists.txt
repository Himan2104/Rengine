add_library(rengine-lib Source/Core/Application.cpp
        Source/Core/AssetManager.cpp
        Source/Core/Console.cpp
        Source/Core/Level.cpp
        Source/Core/LevelManager.cpp
        Source/ECS/Component.cpp
        Source/ECS/EntityManager.cpp
        Source/ECS/Entity.cpp
        Source/ECS/System.cpp
        Source/UI/Button.cpp
        Source/UI/CheckBox.cpp
        Source/UI/guibase.cpp
        Source/UI/Slider.cpp
        Source/UI/TextBox.cpp
        Source/Utility/Debug.cpp
        Source/Utility/Misc.cpp
        Source/Utility/TimeKeeper.cpp
        Source/Core/Simulation.cpp
        Include/Rengine/Engine.hpp
        Source/Core/EventSystem.cpp
        Include/Rengine/Utility/CommonHelpers.hpp)


set(RENGINE_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/Include)
target_include_directories(rengine-lib PUBLIC ${RENGINE_INCLUDE_DIRS} ${SFML_INCLUDE_DIR})
target_link_libraries(rengine-lib PRIVATE sfml-graphics sfml-audio sfml-network)