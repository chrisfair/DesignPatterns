SET(CMAKE_CXX_FLAGS_INIT   "-Wall")

cmake_minimum_required(VERSION 3.7)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} 
                     ${CMAKE_CURRENT_SOURCE_DIR}/include/Ducks
                     ${CMAKE_CURRENT_SOURCE_DIR}/include/FlyBehavior
                     ${CMAKE_CURRENT_SOURCE_DIR}/include/QuackBehavior )

project(Ducks)

set (SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/Ducks/Duck.cpp 
               ${CMAKE_CURRENT_SOURCE_DIR}/src/Ducks/MallardDuck.cpp 
               ${CMAKE_CURRENT_SOURCE_DIR}/src/Ducks/RedHeadDuck.cpp 
               ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/src/FlyBehavior/FlyBehavior.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/src/FlyBehavior/FlyNoWay.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/src/FlyBehavior/FlyWithWings.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/src/QuackBehavior/QuackBehavior.cpp 
               ${CMAKE_CURRENT_SOURCE_DIR}/src/QuackBehavior/QuackBehavior.cpp 
               ${CMAKE_CURRENT_SOURCE_DIR}/src/QuackBehavior/Quack.cpp 
               ${CMAKE_CURRENT_SOURCE_DIR}/src/QuackBehavior/Squeak.cpp ) 

add_executable(Ducks ${SRC_FILES})
