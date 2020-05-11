cmake_minimum_required(VERSION 3.2)

project(engine C CXX)

set(SOURCE_FILES
    engine.h
    engine.cpp
)
#add all dependecies for engine here
add_library(engine SHARED STATIC ${SOURCE_FILES}) 

install(TARGETS engine DESTINATION ${REGEXENGINE_INSTALL_LIB_DIR})
install(FILES engine.h DESTINATION ${REGEXENGINE_INSTALL_INCLUDE_DIR})
