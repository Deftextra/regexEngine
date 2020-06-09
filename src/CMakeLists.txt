cmake_minimum_required(VERSION 3.2)
project(regexEngine)

set(SOURCE_FILES main.cpp)

include_directories(engine)
link_directories(engine)

add_subdirectory(engine)

add_executable(regexEngine ${SOURCE_FILES})

target_link_libraries(regexEngine engine)

install(TARGETS regexEngine DESTINATION ${REGEXENGINE_INSTALL_BIN_DIR})
