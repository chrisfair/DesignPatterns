set(LCOV_REMOVE_EXTRA "'catch/*'")
add_library(Catch INTERFACE)

target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/catch)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)


list (APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)


file (GLOB TEST_SOURCES_INITIAL ${CMAKE_CURRENT_SOURCE_DIR}/tests/*) 

set (TEST_SOURCES ${TEST_SOURCES_INITIAL} ${COMMON_FILES}) 

add_executable(${PROJECT_TEST_NAME} ${TEST_SOURCES})

enable_testing(true)
add_test (NAME UnitTests COMMAND ${PROJECT_TEST_NAME})

set_target_properties(${PROJECT_TEST_NAME} PROPERTIES COMPILE_FLAGS
    " -g -O0 -fprofile-arcs -ftest-coverage ")
set_target_properties(${PROJECT_TEST_NAME} PROPERTIES LINKER_FLAGS
    " -g -O0 -fprofile-arcs -ftest-coverage ")

target_link_libraries(${PROJECT_TEST_NAME} Catch gcov)

include(CodeCoverage)
setup_target_for_coverage(catch-coverage ${PROJECT_TEST_NAME} catch-coverage)

