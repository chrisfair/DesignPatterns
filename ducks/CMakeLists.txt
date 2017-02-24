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

set (SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/Ducks/Duck
               ${CMAKE_CURRENT_SOURCE_DIR}/src/Ducks/MallardDuck
               ${CMAKE_CURRENT_SOURCE_DIR}/src/Ducks/RedHeadDuck
               ${CMAKE_CURRENT_SOURCE_DIR}/src/Ducks/RubberDucky
               ${CMAKE_CURRENT_SOURCE_DIR}/src/Ducks/ModelDuck
               ${CMAKE_CURRENT_SOURCE_DIR}/src/FlyBehavior/FlyBehavior
               ${CMAKE_CURRENT_SOURCE_DIR}/src/FlyBehavior/FlyNoWay
               ${CMAKE_CURRENT_SOURCE_DIR}/src/FlyBehavior/FlyWithWings
               ${CMAKE_CURRENT_SOURCE_DIR}/src/FlyBehavior/FlyRocketPowered
               ${CMAKE_CURRENT_SOURCE_DIR}/src/QuackBehavior/QuackBehavior
               ${CMAKE_CURRENT_SOURCE_DIR}/src/QuackBehavior/QuackBehavior
               ${CMAKE_CURRENT_SOURCE_DIR}/src/QuackBehavior/Quack
               ${CMAKE_CURRENT_SOURCE_DIR}/src/QuackBehavior/Squeak
               ${CMAKE_CURRENT_SOURCE_DIR}/src/main )

add_executable(Ducks ${SRC_FILES})
