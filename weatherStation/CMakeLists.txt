cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_C_FLAGS "-Wall")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "WeatherStation")
set(UNIT_TESTS "Unit_Tests")

project(${PROJECT_NAME})
add_library(Catch INTERFACE)

target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/catch/)


include_directories( ${CMAKE_CURRENT_SOURCE_DIR} 
                     ${CMAKE_CURRENT_SOURCE_DIR}/include/)



set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)
include(CodeCoverage)


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

               add_executable(${PROJECT_NAME} ${SRC_FILES})


add_executable(${UNIT_TESTS} ${TEST_SOURCES})
target_link_libraries(${UNIT_TESTS} Catch)

enable_testing(true)
add_test (NAME UnitTests COMMAND Unit_Tests)
setup_target_for_coverage(${PROJECT_NAME}_coverage ${UNIT_TESTS} coverage)
