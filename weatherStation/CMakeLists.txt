set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "-g -O0 -Wall -W -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
set(CMAKE_AR  "/usr/bin/llvm-ar")
set(CMAKE_LINKER   "/usr/bin/llvm-ld")
set(CMAKE_NM  "/usr/bin/llvm-nm")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                                           ${CMAKE_CURRENT_SOURCE_DIR}/include/)

cmake_minimum_required(VERSION 3.0)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} 
                     ${CMAKE_CURRENT_SOURCE_DIR}/include/)

project(WeatherStation)


set (COMMON_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/Subject
                  ${CMAKE_CURRENT_SOURCE_DIR}/src/Observer
                  ${CMAKE_CURRENT_SOURCE_DIR}/src/WeatherData
                  ${CMAKE_CURRENT_SOURCE_DIR}/src/CurrentConditionsDisplay
                  ${CMAKE_CURRENT_SOURCE_DIR}/src/StatisticsDisplay
                  ${CMAKE_CURRENT_SOURCE_DIR}/src/ForcastDisplay
                  ${CMAKE_CURRENT_SOURCE_DIR}/src/HeatIndexDisplay )
 
              
set (SRC_FILES ${COMMON_FILES}
               ${CMAKE_CURRENT_SOURCE_DIR}/src/main )

set (TEST_SOURCES ${COMMON_FILES}
                  ${CMAKE_CURRENT_SOURCE_DIR}/tests/mainUnitTest.cpp 
                  ${CMAKE_CURRENT_SOURCE_DIR}/tests/forcastDisplayUnitTest.cpp )

add_executable(WeatherStation ${SRC_FILES})


add_executable(Unit_Tests ${TEST_SOURCES})
target_link_libraries(Unit_Tests Catch)

enable_testing(true)
add_test (NAME UnitTests COMMAND Unit_Tests)
