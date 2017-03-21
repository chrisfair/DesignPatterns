set(PROJECT_NAME "WeatherStation")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

project(${PROJECT_NAME})

set(CMAKE_MODULE_PATH ${CURRENT_SOURCE_DIR}/CMakeModules)
cmake_minimum_required(VERSION 2.8.8)

include_directories( ${CURRENT_SOURCE_DIR} 
                     ${CURRENT_SOURCE_DIR}/include/)



file (GLOB COMMON_FILES ${CURRENT_SOURCE_DIR}/src/*)

              
set (SRC_FILES ${COMMON_FILES} ${CURRENT_SOURCE_DIR}/main )

add_executable(${PROJECT_NAME} ${SRC_FILES})


enable_testing(true)
#enable catch tests
include(${CURRENT_SOURCE_DIR}/catch-tests/CMakeLists.txt)
include(${CURRENT_SOURCE_DIR}/catch-tests-coverage/CMakeLists.txt)

#enable google test
add_subdirectory(${CURRENT_SOURCE_DIR}/googletest)
include(${CURRENT_SOURCE_DIR}/google-tests/CMakeLists.txt)
include(${CURRENT_SOURCE_DIR}/google-tests-coverage/CMakeLists.txt)


