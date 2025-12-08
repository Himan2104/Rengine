function(add_rengine_library TARGET_NAME)
  string(TOLOWER "${TARGET_NAME}" TARGET_NAME_LOWER)
  set(LIBRARY_TARGET "rengine-${TARGET_NAME_LOWER}")
  add_library(${LIBRARY_TARGET})
  add_library(Rengine::${TARGET_NAME} ALIAS ${LIBRARY_TARGET})

  cmake_parse_arguments(
        ARG
        ""
        ""
        "SOURCES;PUBLIC_DEPENDENCIES;PRIVATE_DEPENDENCIES;INTERFACE_DEPENDENCIES;PUBLIC_INCLUDES;PRIVATE_INCLUDES;INTERFACE_INCLUDES"
        ${ARGN}
    )
    
  if(ARG_SOURCES)
      target_sources(${LIBRARY_TARGET}
          PRIVATE ${ARG_SOURCES}
      )
  endif()
  
  if(ARG_PUBLIC_INCLUDES)
      target_include_directories(${LIBRARY_TARGET}
          PUBLIC ${ARG_PUBLIC_INCLUDES}
      )
  endif()
  
  if(ARG_PRIVATE_INCLUDES)
      target_include_directories(${LIBRARY_TARGET}
          PRIVATE ${ARG_PRIVATE_INCLUDES}
      )
  endif()
  
  if(ARG_INTERFACE_INCLUDES)
      target_include_directories(${LIBRARY_TARGET}
          INTERFACE ${ARG_INTERFACE_INCLUDES}
      )
  endif()
  
  if(ARG_PUBLIC_DEPENDENCIES)
      target_link_libraries(${LIBRARY_TARGET}
          PUBLIC ${ARG_PUBLIC_DEPENDENCIES}
      )
  endif()
  
  if(ARG_PRIVATE_DEPENDENCIES)
      target_link_libraries(${LIBRARY_TARGET}
          PRIVATE ${ARG_PRIVATE_DEPENDENCIES}
      )
  endif()
  
  if(ARG_INTERFACE_DEPENDENCIES)
      target_link_libraries(${LIBRARY_TARGET}
          INTERFACE ${ARG_INTERFACE_DEPENDENCIES}
      )
  endif()
  
  set_target_properties(${LIBRARY_TARGET} PROPERTIES
      OUTPUT_NAME "rengine-${TARGET_NAME}"
      OUTPUT_NAME_DEBUG "rengine-${TARGET_NAME}-dbg"
      PREFIX ""
  )
endfunction()
