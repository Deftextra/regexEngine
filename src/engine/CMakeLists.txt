cmake_minimum_required(VERSION 3.2)

project(engine)

set(SOURCE_FILES
  transition.cpp
)

set(HEADER_FILES
  transition.h
)
  


add_library(engine SHARED STATIC ${SOURCE_FILES})

install(TARGETS engine DESTINATION ${REGEXENGINE_INSTALL_LIB_DIR})

install(FILES ${HEADER_FILES} DESTINATION ${REGEXENGINE_INSTALL_INCLUDE_DIR})
