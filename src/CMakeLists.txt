cmake_minimum_required(VERSION 3.2)
project(regexEngine)

add_subdirectory(engine)
set(SOURCE_FILES main.cpp)

add_executable(regexEngine ${SOURCE_FILES})
target_link_libraries(regexEngine engine)
install(TARGETS regexEngine DESTINATION ${REGEXENGINE_INSTALL_BIN_DIR})
