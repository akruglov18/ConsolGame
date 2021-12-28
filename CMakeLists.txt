cmake_minimum_required(VERSION 3.12)

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/Configure.cmake")

project(Consol_Game)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/gtest")
include_directories("${CMAKE_SOURCE_DIR}/3rdparty/gtest/googletest/include")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/sfml")
include_directories("${CMAKE_SOURCE_DIR}/3rdparty/sfml/include")

add_subdirectory(resource_holder)
add_subdirectory(items)
add_subdirectory(armor_set)
add_subdirectory(weapons)
add_subdirectory(creature)
add_subdirectory(action)
add_subdirectory(tiles)
add_subdirectory(field)
add_subdirectory(tests)
add_subdirectory(game)
add_subdirectory(main)