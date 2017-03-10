set(GOOGLE_TEST_NAME "Google_Unit_Tests")

add_library(GoogleTest INTERFACE)
set(LIB_G_TEST ${CMAKE_CURRENT_SOURCE_DIR}/googletest/build/googlemock/gtest/libgtest.a)
set(LIB_G_MOCK ${CMAKE_CURRENT_SOURCE_DIR}/googletest/build/googlemock/libgmock.a)

target_include_directories(GoogleTest INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include" 
                                                "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googlemock/include")


file (GLOB GOOGLE_SOURCES_INITIAL ${CMAKE_CURRENT_SOURCE_DIR}/google-tests/*.cpp) 

set (GOOGLE_TEST_SOURCES ${GOOGLE_SOURCES_INITIAL} ${COMMON_FILES}) 


add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)

add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)


add_executable(${GOOGLE_TEST_NAME} ${GOOGLE_TEST_SOURCES})

add_test(NAME GoogleUnitTests COMMAND ${GOOGLE_TEST_NAME})

set_target_properties(${GOOGLE_TEST_NAME} PROPERTIES COMPILE_FLAGS
    " -g -O0 -fprofile-arcs -ftest-coverage ")
set_target_properties(${GOOGLE_TEST_NAME} PROPERTIES LINKER_FLAGS
    " -g -O0 -fprofile-arcs -ftest-coverage ")

set_target_properties(libgtest PROPERTIES
    "IMPORTED_LOCATION" "${LIB_G_TEST}"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    )

set_target_properties(libgmock PROPERTIES
    "IMPORTED_LOCATION" "${LIB_G_MOCK}"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    )
target_link_libraries(${GOOGLE_TEST_NAME} gcov pthread)


include(CodeCoverage)
setup_target_for_coverage(google-coverage ${GOOGLE_TEST_NAME} google-coverage)

