set(ProjectId Tests)
project(${ProjectId})

file(GLOB ALL_SOURCE_FILES *.cpp *.h *.hpp)

add_executable(${ProjectId} ${ALL_SOURCE_FILES})
target_link_libraries(${ProjectId} gtest gtest_main Items Weapon)
