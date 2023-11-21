find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main
add_executable(tests shortest_path_test.cpp shortest_path.cpp graph.cpp)
add_executable(tests2 main.cpp shortest_path.cpp graph.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)