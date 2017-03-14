set(PROJECT_NAME "WeatherStation")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(${PROJECT_NAME})

cmake_minimum_required(VERSION 2.8.8)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} 
                     ${CMAKE_CURRENT_SOURCE_DIR}/include/)



file (GLOB COMMON_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*)

              
set (SRC_FILES ${COMMON_FILES} ${CMAKE_CURRENT_SOURCE_DIR}/main )

add_executable(${PROJECT_NAME} ${SRC_FILES})


enable_testing(true)
include(${CMAKE_CURRENT_SOURCE_DIR}/catch-tests/CMakeLists.txt)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/googletest)
include(${CMAKE_CURRENT_SOURCE_DIR}/google-tests/CMakeLists.txt)

