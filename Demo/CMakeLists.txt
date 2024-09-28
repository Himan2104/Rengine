add_executable(demo Source/TestState.cpp Source/main.cpp)

target_include_directories(demo PRIVATE Include ${RENGINE_INCLUDE_DIRS} ${SFML_INCLUDE_DIR})
target_link_libraries(demo PRIVATE rengine-lib sfml-graphics sfml-audio sfml-network)