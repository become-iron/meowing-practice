#include <algorithm>
#include <random>
#include <vector>

#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch2/catch.hpp"

#include "bubble.h"
#include "merge.h"
#include "qsort.h"
#include "selection.h"

int getRandom() {
  static std::random_device randDevice{std::random_device()};
  static std::default_random_engine randEngine{std::default_random_engine()};
  static std::uniform_int_distribution<int> uniformDistribution(0, 1000);

  return uniformDistribution(randEngine);
}

std::vector<int> getRandomVector(const size_t size) {
  std::vector<int> vec;
  for (size_t i = 0; i < size; ++i)
    vec.push_back(getRandom());

  return vec;
}

TEST_CASE("Test correctness of sorts", "[sort]") {
  const size_t count = 10'000;
  std::vector<int> v1 = getRandomVector(count);
  std::vector<int> v2(v1);
  std::sort(v1.begin(), v1.end());

  SECTION("Bubble sort") {
    meowing::bubbleSort(v2.begin(), v2.end());
    REQUIRE(v1 == v2);
  }

  SECTION("Qsort") {
    meowing::qsort(v2.begin(), v2.end());
    REQUIRE(v1 == v2);
  }

  SECTION("Selection sort") {
    meowing::selectionSort(v2.begin(), v2.end());
    REQUIRE(v1 == v2);
  }

  SECTION("Merge sort") {
    meowing::mergeSort(v2.begin(), v2.end());
    REQUIRE(v1 == v2);
  }
}

TEST_CASE("Test performance of sorts (1M elements)", "[sort]") {
  const size_t count = 1'000'000;
  BENCHMARK_ADVANCED("std::sort")(Catch::Benchmark::Chronometer meter) {
    std::vector<int> v1 = getRandomVector(count);
    meter.measure([&v1]() { std::sort(v1.begin(), v1.end()); });
  };

  BENCHMARK_ADVANCED("Qsort")(Catch::Benchmark::Chronometer meter) {
    std::vector<int> v1 = getRandomVector(count);
    meter.measure([&v1]() { meowing::qsort(v1.begin(), v1.end()); });
  };

  BENCHMARK_ADVANCED("Merge sort")(Catch::Benchmark::Chronometer meter) {
    std::vector<int> v1 = getRandomVector(count);
    meter.measure([&v1]() { meowing::mergeSort(v1.begin(), v1.end()); });
  };
}
