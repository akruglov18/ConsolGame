set(ProjectId main)
project(${ProjectId})

file(GLOB ALL_SOURCE_FILES *.cpp *.h *.hpp)

add_executable(${ProjectId} ${ALL_SOURCE_FILES})
target_include_directories(${ProjectId} PUBLIC .)
target_link_libraries(${ProjectId} sfml-graphics sfml-audio items creature tiles field game screen)
