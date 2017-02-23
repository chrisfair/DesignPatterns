SET(CMAKE_CXX_FLAGS_INIT   "-Wall")
SET(CMAKE_AR  "/usr/bin/llvm-ar")
SET(CMAKE_LINKER   "/usr/bin/llvm-ld")
SET(CMAKE_NM  "/usr/bin/llvm-nm")
SET(CMAKE_CXX_COMPILER "/usr/bin/clang++")
SET(CMAKE_C_COMPILER "/bin/clang")

SET(CMAKE_CXX_FLAGS_INIT   "-Wall")

cmake_minimum_required(VERSION 3.7)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} 
                     ${CMAKE_CURRENT_SOURCE_DIR}/include/)

project(WeatherStation)

set (SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/WeatherData.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/src/CurrentConditionDisplay.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

add_executable(WeatherStation ${SRC_FILES})
