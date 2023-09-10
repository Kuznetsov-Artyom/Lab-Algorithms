#ifndef _TESTS_HPP_
#define _TESTS_HPP_

#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

#include "algorithms.hpp"
#include "generator.hpp"
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
enum class Layout { NO_SORT, INC_SORT, DEC_SORT };

std::vector<int> createRandomArray(size_t size, Layout layout = Layout::NO_SORT,
                                   int minValue = INT_MIN,
                                   int maxValue = INT_MAX);

void testAvlSort();
void testQuickSort();

void testAvlTreeLong(size_t sizeArr, size_t countTest, Layout layout,
                     int minValue = INT_MIN, int maxValue = INT_MAX);
void testQuickSortLong(size_t sizeArr, size_t countTest, Layout layout,
                       int minValue = INT_MIN, int maxValue = INT_MAX);
}  // namespace tests

#endif  // _TESTS_HPP_