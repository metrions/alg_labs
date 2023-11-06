find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main
add_executable(tests min_spanning_tree_test.cpp min_spanning_tree.cpp graph.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)