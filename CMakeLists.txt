cmake_minimum_required(VERSION 4.0)
project(cpp_playground)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        benchmark
        GIT_REPOSITORY https://github.com/google/benchmark
        GIT_TAG v1.9.4
)

set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(benchmark)

add_executable(bench bench.cpp)

target_link_libraries(bench
    PRIVATE benchmark::benchmark
)
