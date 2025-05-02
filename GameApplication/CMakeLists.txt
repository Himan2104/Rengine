add_executable(game
    Source/Main.cxx
    Source/GameApplication.cxx)

target_include_directories(game PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Include ${RENGINE_INCLUDE_DIRS})
target_link_libraries(game PRIVATE rengine-af rengine-core)
