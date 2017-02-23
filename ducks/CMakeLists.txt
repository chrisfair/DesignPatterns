SET(CMAKE_CXX_FLAGS_INIT   "-Wall")
SET(CMAKE_AR  "/usr/bin/llvm-ar")
SET(CMAKE_LINKER   "/usr/bin/llvm-ld")
SET(CMAKE_NM  "/usr/bin/llvm-nm")
SET(CMAKE_CXX_COMPILER "/usr/bin/clang++")
SET(CMAKE_C_COMPILER "/bin/clang")


cmake_minimum_required(VERSION 2.8)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} 
                     ${CMAKE_CURRENT_SOURCE_DIR}/include/Ducks
                     ${CMAKE_CURRENT_SOURCE_DIR}/include/FlyBehavior
                     ${CMAKE_CURRENT_SOURCE_DIR}/include/QuackBehavior )

project(Ducks)

set (SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/Ducks/Duck.cpp 
               ${CMAKE_CURRENT_SOURCE_DIR}/src/Ducks/MallardDuck.cpp 
               ${CMAKE_CURRENT_SOURCE_DIR}/src/Ducks/RedHeadDuck.cpp 
               ${CMAKE_CURRENT_SOURCE_DIR}/src/Ducks/RubberDucky.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/src/Ducks/ModelDuck.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/src/FlyBehavior/FlyBehavior.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/src/FlyBehavior/FlyNoWay.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/src/FlyBehavior/FlyWithWings.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/src/FlyBehavior/FlyRocketPowered.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/src/QuackBehavior/QuackBehavior.cpp 
               ${CMAKE_CURRENT_SOURCE_DIR}/src/QuackBehavior/QuackBehavior.cpp 
               ${CMAKE_CURRENT_SOURCE_DIR}/src/QuackBehavior/Quack.cpp 
               ${CMAKE_CURRENT_SOURCE_DIR}/src/QuackBehavior/Squeak.cpp 
               ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp ) 

add_executable(Ducks ${SRC_FILES})
