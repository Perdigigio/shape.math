cmake_minimum_required(VERSION 3.8)

project(shape.math.test)

if (NOT DEFINED GTest_FOUND)
    #
    # STANDALONE COMPILE
    #

    find_package(GTest REQUIRED)
endif()

#
# UNIT TESTS
#

add_executable(shape.math.vector vector.cc)
add_executable(shape.math.matrix matrix.cc)
target_link_libraries(shape.math.vector GTest::GTest GTest::Main)
target_link_libraries(shape.math.matrix GTest::GTest GTest::Main)