#include <iostream>
#include <memory>
#include <vector>

#include "benchmark/benchmark.hpp"
#include "headers/algorithms.hpp"
#include "headers/avltree.hpp"


template <typename T, template <typename Elem, typename = std::allocator<Elem>>
                      class Container>
std::ostream& operator<<(std::ostream& out, const Container<T>& cont) {
  auto itBegin = cont.begin();
  auto itEnd = cont.begin() + cont.size() - 1;

  for (; itBegin != itEnd; ++itBegin) out << *itBegin << ' ';
  return out << *itBegin;
}

void testEmplaceBack() {
  std::vector<int> vec;
  for (int j = 0; j < 1'000'000; ++j) vec.emplace_back(j + 1);
}

void testPushBack() {
  std::vector<int> vec;
  for (int j = 0; j < 1'000'000; ++j) vec.push_back(j + 1);
}

void testOperatorInd() {
  std::vector<int> vec(1'000'000);
  for (int j = 0; j < 1'000'000; ++j) vec[j] = j + 1;
}

int main(int argc, char* argv[], char** env) {
  bmk::count_t count = 300;
  BENCHMARK_CREATE(test1, tmr::millisecond_t, testPushBack, count);
  BENCHMARK_CREATE(test2, tmr::millisecond_t, testEmplaceBack, count);
  BENCHMARK_CREATE(test3, tmr::millisecond_t, testOperatorInd, count);

  std::cout << BENCHMARK_START(test1) << '\n';
  std::cout << BENCHMARK_START(test2) << '\n';
  std::cout << BENCHMARK_START(test3) << '\n';

  return 0;
}