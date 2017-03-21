set(LCOV_REMOVE_EXTRA "'catch/*'")
set(CATCH_TEST_NAME "CatchUnitTests")
add_library(Catch INTERFACE)

target_include_directories(Catch INTERFACE ${CURRENT_SOURCE_DIR}/catch)




file (GLOB TEST_SOURCES_INITIAL ${CURRENT_SOURCE_DIR}/catch-tests/*.cpp) 

set (TEST_SOURCES ${TEST_SOURCES_INITIAL} ${COMMON_FILES}) 

add_executable(${CATCH_TEST_NAME} ${TEST_SOURCES})

add_test (NAME CatchUnitTests COMMAND ${CATCH_TEST_NAME})
set_target_properties(${CATCH_TEST_NAME} PROPERTIES COMPILE_FLAGS
   " -g -O0 -fprofile-arcs -ftest-coverage ")
set_target_properties(${CATCH_TEST_NAME} PROPERTIES LINKER_FLAGS
   " -g -O0 -fprofile-arcs -ftest-coverage ")

target_link_libraries(${CATCH_TEST_NAME} Catch gcov)



