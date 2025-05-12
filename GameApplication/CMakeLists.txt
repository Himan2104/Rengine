add_executable(game
    Source/Main.cxx
    Source/GameApplication.cxx)

target_include_directories(game PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Include ${RENGINE_INCLUDE_DIRS})
target_link_libraries(game PRIVATE rengine-af rengine-core)

if(WIN32)
  if (BUILD_SHARED_LIBS)
        add_custom_command(TARGET game POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
          $<TARGET_FILE:sfml-graphics>
          $<TARGET_FILE:sfml-window>
          $<TARGET_FILE:sfml-system>
          $<TARGET_FILE:sfml-audio>
          $<TARGET_FILE:sfml-network>
          $<TARGET_FILE_DIR:game>)
  endif()
endif()

