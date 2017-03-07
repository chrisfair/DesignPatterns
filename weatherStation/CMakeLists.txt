SET(CMAKE_CXX_FLAGS_INIT   "-Wall -std=c++11")
SET(CMAKE_AR  "/usr/bin/llvm-ar")
SET(CMAKE_LINKER   "/usr/bin/llvm-ld")
SET(CMAKE_NM  "/usr/bin/llvm-nm")
SET(CMAKE_CXX_COMPILER "/usr/bin/clang++")
SET(CMAKE_C_COMPILER "/usr/bin/clang")
SET(CATCH_INCLUDE_DIR) 

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/)

cmake_minimum_required(VERSION 2.5)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} 
                     ${CMAKE_CURRENT_SOURCE_DIR}/include/)

project(WeatherStation)

set (SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/Subject
               ${CMAKE_CURRENT_SOURCE_DIR}/src/Observer
               ${CMAKE_CURRENT_SOURCE_DIR}/src/WeatherData
               ${CMAKE_CURRENT_SOURCE_DIR}/src/CurrentConditionsDisplay
               ${CMAKE_CURRENT_SOURCE_DIR}/src/StatisticsDisplay
               ${CMAKE_CURRENT_SOURCE_DIR}/src/ForcastDisplay
               ${CMAKE_CURRENT_SOURCE_DIR}/src/HeatIndexDisplay
               ${CMAKE_CURRENT_SOURCE_DIR}/src/main )

add_executable(WeatherStation ${SRC_FILES})
add_executable(unit_tests Catch)
target_link_libraries(unit_tests Catch)
enable_testing()
add_test(NAME UnitTests COMMAND unit_tests)
