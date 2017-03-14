set(PROJECT_NAME_ATMEL "WeatherStation-Atmel")
set(CMAKE_CXX_COMPILER "/opt/Programs/buildroot-at91/output/host/usr/bin/arm-linux-c++")
set(CMAKE_AR "/opt/Programs/buildroot-at91/output/host/usr/bin/arm-linux-ar")
set(CMAKE_C_COMPILER "/opt/Programs/buildroot-at91/output/host/usr/bin/arm-linux-cc")
set(ATMEL_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/..)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

cmake_minimum_required(VERSION 2.8.8)

include_directories( ${ATMEL_CURRENT_SOURCE_DIR} 
                     ${ATMEL_CURRENT_SOURCE_DIR}/include/)



file (GLOB COMMON_FILES ${ATMEL_CURRENT_SOURCE_DIR}/src/*)

              
set (SRC_FILES ${COMMON_FILES} ${ATMEL_CURRENT_SOURCE_DIR}/main )

add_executable(${PROJECT_NAME} ${SRC_FILES})

include(${ATMEL_CURRENT_SOURCE_DIR}/atmel-build/CMakeLists.txt)

enable_testing(true)
include(${ATMEL_CURRENT_SOURCE_DIR}/catch-tests/CMakeLists.txt)
add_subdirectory(${ATMEL_CURRENT_SOURCE_DIR}/googletest)
include(${ATMEL_CURRENT_SOURCE_DIR}/google-tests/CMakeLists.txt)

project(${PROJECT_NAME_ATMEL})

add_executable(${PROJECT_NAME_ATMEL} ${SRC_FILES})


