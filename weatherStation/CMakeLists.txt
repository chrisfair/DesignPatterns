set(CMAKE_AR  "/usr/bin/llvm-ar")
set(CMAKE_LINKER   "/usr/bin/llvm-ld")
set(CMAKE_NM  "/usr/bin/llvm-nm")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(PROJECT_NAME "WeatherStation")
set(PROJECT_TEST_NAME "Unit_Tests")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(LCOV_REMOVE_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/catch/")

add_library(Catch INTERFACE)

target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/catch/)

cmake_minimum_required(VERSION 2.8.8)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} 
                     ${CMAKE_CURRENT_SOURCE_DIR}/include/)

project(${PROJECT_NAME})


list (APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)

include(CodeCoverage)
include(UseBackportedModules)

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


add_executable(${PROJECT_TEST_NAME} ${TEST_SOURCES})
add_executable(${PROJECT_NAME} ${SRC_FILES})

enable_testing(true)
add_test (NAME UnitTests COMMAND ${PROJECT_TEST_NAME})

target_link_libraries(${PROJECT_TEST_NAME} Catch)
target_link_libraries(${PROJECT_TEST_NAME} gcov)

SETUP_TARGET_FOR_COVERAGE(${PROJECT_TEST_NAME}_coverage ${PROJECT_TEST_NAME} coverage)


