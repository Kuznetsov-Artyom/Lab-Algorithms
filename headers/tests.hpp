#ifndef _TESTS_HPP_
#define _TESTS_HPP_

#include <iostream>
#include <memory>
#include <vector>

#include "algorithms.hpp"
#include "timer.hpp"

template <typename T, template <typename Elem, typename = std::allocator<Elem>>
                      class Container>
std::ostream& operator<<(std::ostream& out, const Container<T>& cont) {
  auto itBegin = cont.begin();
  auto itEnd = cont.begin() + cont.size() - 1;

  for (; itBegin != itEnd; ++itBegin) out << *itBegin << ' ';
  return out << *itBegin;
}

namespace tests {
void testAvlSort() {
  std::cout << __FUNCTION__ << "()\n";

  std::vector<int> elems{5, 2, 1, -100, INT_MAX, 12, 0, 32, 90};

  std::cout << "before: " << elems << '\n';
  algs::avlSort(elems);
  std::cout << "after: " << elems << '\n';
}

void testQuickSort() {
  std::cout << __FUNCTION__ << "()\n";

  std::vector<int> elems{5, 2, 1, -100, INT_MAX, 1, 1, 1, 1, 12, 0, 32, 90};

  std::cout << "before: " << elems << '\n';
  algs::quickSort(elems, 0, elems.size() - 1);
  std::cout << "after: " << elems << '\n';
}

void testAvlTreeLong(std::vector<int>& elems, size_t countTest) {
  std::cout << __FUNCTION__ << "()\n";

  long long total = 0;

  for (size_t i = 0; i < countTest; ++i) {
    std::vector<int> arr(elems);

    TIMER_START(timer, tmr::millisecond_t);
    algs::avlSort(elems);
    total += TIMER_GET(timer);
  }

  std::cout << "tests:\t\t" << countTest << '\n';
  std::cout << "avg time:\t" << total / countTest << " ms\n";
}

void testQuickSortLong(std::vector<int>& elems, size_t countTest) {
  std::cout << __FUNCTION__ << "()\n";

  long long total = 0;

  for (size_t i = 0; i < countTest; ++i) {
    std::vector<int> arr(elems);

    TIMER_START(timer, tmr::millisecond_t);
    algs::quickSort(elems, 0, elems.size() - 1);
    total += TIMER_GET(timer);
  }

  std::cout << "tests:\t\t" << countTest << '\n';
  std::cout << "avg time:\t" << total / countTest << " ms\n";
}
}  // namespace tests

#endif  // _TESTS_HPP_