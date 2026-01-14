/*
* Created by Oghenemarho Orukele on 02/01/2026.
* A script to benchmark the arena allocation for STL vs malloc.
*/

#include <random>
#include <unordered_map>
#include <benchmark/benchmark.h>
#include "include/arena_allocator.h"

static void BM_UnorderedMap_Insert(benchmark::State& state)
{
    std::size_t num_elements = state.range(0);

    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(1, 1'000'000);

    for (auto _ : state)
    {
        std::unordered_map<int, long long> map;
        for (std::size_t i = 0; i < num_elements; ++i)
        {
            int key = dist(rng);
            map[key] = i;
        }

        benchmark::DoNotOptimize(map);
    }
}

static void BM_ArenaUnorderedMap_Insert(benchmark::State& state)
{
    std::size_t num_elements = state.range(0);

    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(1, 1'000'000);

    for (auto _ : state)
    {
        Arena arena(1024 * 1024);
        ArenaAllocator<std::pair<const int, long long>> alloc(&arena);
        std::unordered_map<int, long long,
            std::hash<int>,
            std::equal_to<int>,
            ArenaAllocator<std::pair<const int, long long>>
        >map(
            0,
            std::hash<int>{},
            std::equal_to<int>{},
            alloc
        );

        for (std::size_t i = 0; i < num_elements; ++i)
        {
            int key = dist(rng);
            map[key] = i;
        }

        benchmark::DoNotOptimize(map);
    }
}

BENCHMARK(BM_UnorderedMap_Insert)
    ->Arg(100)
    ->Arg(1'000)
    ->Arg(10'000);

BENCHMARK(BM_ArenaUnorderedMap_Insert)
    ->Arg(100)
    ->Arg(1'000)
    ->Arg(10'000);

BENCHMARK_MAIN();