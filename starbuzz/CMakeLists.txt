SET(CMAKE_CXX_FLAGS_INIT   "-Wall -std=c++11")
SET(CMAKE_AR  "/usr/bin/llvm-ar")
SET(CMAKE_LINKER   "/usr/bin/llvm-ld")
SET(CMAKE_NM  "/usr/bin/llvm-nm")
SET(CMAKE_CXX_COMPILER "/usr/bin/clang++")
SET(CMAKE_C_COMPILER "/bin/clang")

cmake_minimum_required(VERSION 3.7)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} 
                     ${CMAKE_CURRENT_SOURCE_DIR}/include/beverages
                     ${CMAKE_CURRENT_SOURCE_DIR}/include/condiments
                     ${CMAKE_CURRENT_SOURCE_DIR}/include/)

project(starbuzz)

set (SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/main 
               ${CMAKE_CURRENT_SOURCE_DIR}/src/beverages/Espresso)

add_executable(starbuzz ${SRC_FILES})
