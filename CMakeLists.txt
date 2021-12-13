cmake_minimum_required(VERSION 3.12)

if(WIN32)
    option(gtest_force_shared_crt "" TRUE)
endif(WIN32)
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/Configure.cmake")

project(Consol_Game)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/gtest")
include_directories("${CMAKE_SOURCE_DIR}/3rdparty/gtest/googletest/include")

add_subdirectory(items)
add_subdirectory(armor_set)
add_subdirectory(weapons)
add_subdirectory(tests)
