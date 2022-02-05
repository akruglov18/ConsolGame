set(ProjectId Tests)
project(${ProjectId})

file(GLOB_RECURSE ALL_SOURCE_FILES *.cpp *.h *.hpp)

add_executable(${ProjectId} ${ALL_SOURCE_FILES})
target_link_libraries(${ProjectId} sfml-graphics gtest gtest_main items weapon armor_set tiles field creature drawer skills_graph)
