add_executable(test_building test_building.cpp)
target_link_libraries(test_building PUBLIC class)
add_test(NAME test_building COMMAND test_building)