cmake_minimum_required(VERSION 3.14)  # CMake version check

project(cpp_playground LANGUAGES CXX) # Create project "cpp_playground"

set(CMAKE_CXX_STANDARD 17)            # Enable C++14 standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch Google Benchmark
include(FetchContent)

# Google benchmark requires GoogleTest for some configurations
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "" FORCE)
set(BENCHMARK_DOWNLOAD_DEPENDENCIES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
        benchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG v1.9.4
)

FetchContent_MakeAvailable(benchmark)

# Define the benchmark executable
add_executable(cpp_playground bench.cpp)

# Include headers
target_include_directories(cpp_playground PRIVATE include)

# Link Google Benchmark
target_link_libraries(cpp_playground
        PRIVATE
            benchmark::benchmark
            benchmark::benchmark_main
)