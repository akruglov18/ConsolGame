set(ProjectId screen)
project(${ProjectId})

file(GLOB ALL_SOURCE_FILES *.cpp *.h *.hpp)

add_library(${ProjectId} STATIC ${ALL_SOURCE_FILES})
target_include_directories(${ProjectId} PUBLIC .)
target_link_libraries(${ProjectId} sfml-graphics items creature tiles field drawer game skills_graph)