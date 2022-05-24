set(ProjectId armor_set)
project(${ProjectId})

file(GLOB_RECURSE ALL_SOURCE_FILES *.cpp *.h *.hpp)

add_library(${ProjectId} STATIC ${ALL_SOURCE_FILES})
target_include_directories(${ProjectId} PUBLIC .)
target_link_libraries(${ProjectId} resource_holder items damage)
