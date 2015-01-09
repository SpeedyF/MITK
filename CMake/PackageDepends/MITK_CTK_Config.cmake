# message("In package CTK config")
find_package(CTK REQUIRED)

if(CTK_qRestAPI_DIR)
  find_package(qRestAPI PATHS ${CTK_qRestAPI_DIR})
endif()

if(CTK_REQUIRED_COMPONENTS_BY_MODULE)
  foreach(_ctk_component ${CTK_REQUIRED_COMPONENTS_BY_MODULE})
    list(APPEND ALL_INCLUDE_DIRECTORIES ${${_ctk_component}_INCLUDE_DIRS})
    list(APPEND ALL_LIBRARIES ${_ctk_component})
  endforeach()
else()
  list(APPEND ALL_INCLUDE_DIRECTORIES ${CTK_INCLUDE_DIRS})
  list(APPEND ALL_LIBRARIES ${CTK_LIBRARIES})
endif()
