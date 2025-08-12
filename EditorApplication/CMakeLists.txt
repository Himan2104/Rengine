add_executable(editor
    Source/Main.cxx
    Source/EditorApplication.cxx)

target_include_directories(editor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Include ${RENGINE_INCLUDE_DIRS} ${IMGUI_SFML_INC_DIR})
target_link_libraries(editor PRIVATE rengine-af rengine-core rengine-gfx rengine-editor ImGui-SFML::ImGui-SFML)

if(WIN32)
  if (BUILD_SHARED_LIBS)
        add_custom_command(TARGET editor POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
          $<TARGET_FILE:sfml-graphics>
          $<TARGET_FILE:sfml-window>
          $<TARGET_FILE:sfml-system>
          $<TARGET_FILE:sfml-audio>
          $<TARGET_FILE:sfml-network>
          $<TARGET_FILE:ImGui-SFML::ImGui-SFML>
          $<TARGET_FILE_DIR:editor>)
  endif()
endif()

