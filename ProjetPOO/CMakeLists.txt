cmake_minimum_required(VERSION 3.12)
project(Simulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(simulator main.cpp problem.cpp equation.cpp variable.cpp uniformmesh.cpp timer.cpp)

enable_testing()
add_test(NAME structure_test COMMAND simulator)

enable_testing()

add_test(NAME simulator_run_test COMMAND simulator)


include(GoogleTest)

add_executable(tests tests.cpp problem.cpp equation.cpp variable.cpp uniformmesh.cpp timer.cpp)

target_link_libraries(tests gtest gtest_main)

gtest_discover_tests(tests)

