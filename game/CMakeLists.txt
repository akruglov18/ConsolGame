set(ProjectId super_game)
project(${ProjectId})

file(GLOB ALL_SOURCE_FILES *.cpp *.h *.hpp)

add_executable(${ProjectId} ${ALL_SOURCE_FILES})
target_link_libraries(${ProjectId} player)