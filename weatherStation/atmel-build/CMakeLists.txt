set(PROJECT_NAME_ATMEL "WeatherStationAtmel")
set(CMAKE_CXX_COMPILER "/opt/Programs/buildroot-at91/output/host/usr/bin/arm-linux-c++")
set(CMAKE_AR "/opt/Programs/buildroot-at91/output/host/usr/bin/arm-linux-ar")
set(CMAKE_C_COMPILER "/opt/Programs/buildroot-at91/output/host/usr/bin/arm-linux-cc")
set(CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/..)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(${PROJECT_NAME_ATMEL})

cmake_minimum_required(VERSION 2.8.8)

include_directories( ${CURRENT_SOURCE_DIR} 
                     ${CURRENT_SOURCE_DIR}/include/)

                  add_custom_command(OUTPUT runUnitTest.bc COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/runUnitTest.sh ${CMAKE_CURRENT_SOURCE_DIR}/build)
add_custom_target(tests DEPENDS runUnitTest.bc)

file (GLOB COMMON_FILES ${CURRENT_SOURCE_DIR}/src/*)

              
set (SRC_FILES ${COMMON_FILES} ${CURRENT_SOURCE_DIR}/main )

add_executable(${PROJECT_NAME} ${SRC_FILES})


include(${CURRENT_SOURCE_DIR}/catch-tests/CMakeLists.txt)



