cmake_minimum_required(VERSION 3.22)
find_package(Catch2 3 REQUIRED)

# These tests can use the Catch2-provided main
# find_package( tsp_hard.cpp )
add_executable(main main.cpp tsp.cpp graph.cpp)
add_executable(mainfast main_fast.cpp tsp_fast.cpp graph.cpp)
add_executable(mainhard main_hard.cpp tsp_hard.cpp graph.cpp)

add_executable(test1 tsp.cpp tsp_test.cpp graph.cpp)
add_executable(test2 tsp_fast.cpp tsp_test.cpp graph.cpp)
add_executable(test3 tsp_hard.cpp tsp_test.cpp graph.cpp)
target_link_libraries(test1 PRIVATE Catch2::Catch2WithMain)
target_link_libraries(test2 PRIVATE Catch2::Catch2WithMain)
target_link_libraries(test3 PRIVATE Catch2::Catch2WithMain)