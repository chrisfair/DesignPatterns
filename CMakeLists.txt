SET(CMAKE_CXX_FLAGS_INIT   "-Wall")

cmake_minimum_required(VERSION 3.7)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src)

project(Ducks)

set (SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/Duck.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/MallardDuck.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/RedHeadDuck.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp) 

add_executable(Ducks ${SRC_FILES})
