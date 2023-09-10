#ifndef _TESTS_HPP_
#define _TESTS_HPP_

#include <iostream>
#include <memory>
#include <vector>

#include "algorithms.hpp"
#include "timer.hpp"
#include "generator.hpp"

template <typename T, template <typename Elem, typename = std::allocator<Elem>>
                      class Container>
std::ostream& operator<<(std::ostream& out, const Container<T>& cont) {
  auto itBegin = cont.begin();
  auto itEnd = cont.begin() + cont.size() - 1;

  for (; itBegin != itEnd; ++itBegin) out << *itBegin << ' ';
  return out << *itBegin;
}

namespace tests {

std::vector<int> createRandomArray(size_t size, int low = INT_MIN, int max = INT_MAX);

void testAvlSort();
void testQuickSort();

void testAvlTreeLong(std::vector<int>& elems, size_t countTest);
void testQuickSortLong(std::vector<int>& elems, size_t countTest);
}  // namespace tests

#endif  // _TESTS_HPP_