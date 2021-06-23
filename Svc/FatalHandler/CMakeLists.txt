####
# F prime CMakeLists.txt:
#
# SOURCE_FILES: combined list of source and autocoding diles
# MOD_DEPS: (optional) module dependencies
#
# Note: using PROJECT_NAME as EXECUTABLE_NAME
####
if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux" OR ${CMAKE_SYSTEM_NAME} STREQUAL "arm-linux-gnueabihf")
  set(SOURCE_FILES
    "${CMAKE_CURRENT_LIST_DIR}/FatalHandlerComponentAi.xml"
    "${CMAKE_CURRENT_LIST_DIR}/FatalHandlerComponentCommonImpl.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/FatalHandlerComponentLinuxImpl.cpp"
  )
elseif (FPRIME_USE_BAREMETAL)
  set(SOURCE_FILES
    "${CMAKE_CURRENT_LIST_DIR}/FatalHandlerComponentAi.xml"
    "${CMAKE_CURRENT_LIST_DIR}/FatalHandlerComponentCommonImpl.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/FatalHandlerComponentBaremetalImpl.cpp"
  )
else ()
  message(FATAL_ERROR "Missing FatalHandler implementation")
endif()

set(MOD_DEPS
  Os
  Fw/Logger
)
register_fprime_module()
