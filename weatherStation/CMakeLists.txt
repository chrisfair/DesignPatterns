SET(CMAKE_CXX_FLAGS_INIT   "-Wall")
SET(CMAKE_AR  "/usr/bin/llvm-ar")
SET(CMAKE_LINKER   "/usr/bin/llvm-ld")
SET(CMAKE_NM  "/usr/bin/llvm-nm")
SET(CMAKE_CXX_COMPILER "/usr/bin/clang++")
SET(CMAKE_C_COMPILER "/usr/bin/clang")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                                           ${CMAKE_CURRENT_SOURCE_DIR}/include/)

cmake_minimum_required(VERSION 2.8.8)

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
                  ${CMAKE_CURRENT_SOURCE_DIR}/tests/unitTestMain.cpp 
                  ${CMAKE_CURRENT_SOURCE_DIR}/tests/unitTestForcastDisplay.cpp )


add_executable(Unit_Tests ${TEST_SOURCES})
add_executable(WeatherStation ${SRC_FILES})

target_link_libraries(Unit_Tests Catch)

enable_testing(true)
add_test (NAME UnitTests COMMAND Unit_Tests)
