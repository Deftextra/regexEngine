cmake_minimum_required(VERSION 3.2)
project(regexEngine_tests)

add_subdirectory(lib/googletest)

include_directories(${ENGINE_HEADERS_DIR})
include_directories(lib/googletest/googletest/include)

set(SOURCE_FILES
 main.cpp
 src/State_tests.cpp
 )

add_executable(regexEngine_tests ${SOURCE_FILES})
target_link_libraries(regexEngine_tests engine gtest)
install(TARGETS regexEngine_tests DESTINATION bin)

