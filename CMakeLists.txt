cmake_minimum_required(VERSION 3.2)

project(regexEngine)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}) 

set(REGEXENGINE_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(REGEXENGINE_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin) 
set(REGEXENGINE_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

set(ENGINE_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/engine)
set(MAIN_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src)

include_directories(${REGEXENGINE_INSTALL_INCLUDE_DIR})
include_directories(${ENGINE_HEADERS_DIR})
include_directories(${MAIN_HEADERS_DIR})

add_subdirectory(src)
add_subdirectory(test)


