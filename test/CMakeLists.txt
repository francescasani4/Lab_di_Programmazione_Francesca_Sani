cmake_minimum_required(VERSION 3.25)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTest.cpp ArticoloTest.cpp ListaTest.cpp UtenteTest.cpp)
add_executable(runTest ${TEST_SOURCE_FILES})
target_link_libraries(runTest gtest gtest_main core)