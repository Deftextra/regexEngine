cmake_minimum_required(VERSION 3.2)

project(engine)

set(SOURCE_FILES
  transitions/transition.cpp
  transitions/transition.h
  states/state.cpp
  states/state.h
  automata.cpp
  automata.h
  parser.cpp
  parser.h

)

set(HEADER_FILES
  states/state.h
  automata.h
  parser.h
)

add_library(engine STATIC ${SOURCE_FILES})

install(TARGETS engine DESTINATION ${REGEXENGINE_INSTALL_LIB_DIR})

install(FILES ${HEADER_FILES} DESTINATION ${REGEXENGINE_INSTALL_INCLUDE_DIR})
