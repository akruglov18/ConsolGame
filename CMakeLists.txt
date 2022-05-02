cmake_minimum_required(VERSION 3.12)

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/Configure.cmake")

project(Game)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/gtest")
include_directories("${CMAKE_SOURCE_DIR}/3rdparty/gtest/googletest/include")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/sfml")
include_directories("${CMAKE_SOURCE_DIR}/3rdparty/sfml/include")

include_directories("${CMAKE_SOURCE_DIR}/3rdparty/")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/Compiler.cmake")

add_subdirectory(resource_holder)
add_subdirectory(inventory)
add_subdirectory(skills_graph)
add_subdirectory(equipment)
add_subdirectory(creature)
add_subdirectory(action)
add_subdirectory(animation)
add_subdirectory(field)
add_subdirectory(utils)
add_subdirectory(tests)
add_subdirectory(game)
add_subdirectory(interfaces)
add_subdirectory(main)
