set(PROJECT_NAME "WeatherStation")
set(PROJECT_TEST_NAME "Unit_Tests")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(LCOV_REMOVE_EXTRA ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(LCOV_REMOVE_EXTRA ${CMAKE_CURRENT_SOURCE_DIR}/catch)
set(LCOV_REMOVE_EXTRA ${CMAKE_CURRENT_SOURCE_DIR}/tests)

add_library(Catch INTERFACE)

project(${PROJECT_NAME})
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/catch)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)

cmake_minimum_required(VERSION 2.8.8)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} 
                     ${CMAKE_CURRENT_SOURCE_DIR}/include/)


list (APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)

file (GLOB COMMON_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*)

              
set (SRC_FILES ${COMMON_FILES} ${CMAKE_CURRENT_SOURCE_DIR}/main )

file (GLOB TEST_SOURCES_INITIAL ${CMAKE_CURRENT_SOURCE_DIR}/tests/*) 

set (TEST_SOURCES ${TEST_SOURCES_INITIAL} ${COMMON_FILES}) 

add_executable(${PROJECT_TEST_NAME} ${TEST_SOURCES})
add_executable(${PROJECT_NAME} ${SRC_FILES})

include(CppcheckTargets)
add_cppcheck_sources (${SRC_FILES} [STYLE])

enable_testing(true)
add_test (NAME UnitTests COMMAND ${PROJECT_TEST_NAME})

set_target_properties(${PROJECT_TEST_NAME} PROPERTIES COMPILE_FLAGS
    " -g -O0 -fprofile-arcs -ftest-coverage ")
set_target_properties(${PROJECT_TEST_NAME} PROPERTIES LINKER_FLAGS
    " -g -O0 -fprofile-arcs -ftest-coverage ")

target_link_libraries(${PROJECT_TEST_NAME} Catch gcov)

include(CodeCoverage)
setup_target_for_coverage(coverage ${PROJECT_TEST_NAME} coverage_results)

