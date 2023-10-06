find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main
add_executable(tests main.cpp closest_pair.cpp point.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)