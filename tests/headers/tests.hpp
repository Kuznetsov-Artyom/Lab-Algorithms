#ifndef _TESTS_HPP_
#define _TESTS_HPP_

#include <algorithm>
#include <fstream>
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
enum class FuncSort { QUICK, AVL };

std::vector<int64_t> createRandomArray(size_t size,
                                       Layout layout = Layout::NO_SORT,
                                       int64_t minValue = INT64_MIN,
                                       int64_t maxValue = INT64_MAX);

std::string createPath(std::string testName, FuncSort func, Layout layout);

void testAvlSort();
void testQuickSort();

int64_t testSort(FuncSort func, Layout layout, size_t sizeArr, size_t countTest,
                 int64_t minValue = INT64_MIN, int64_t maxValue = INT64_MAX);

void autoTestSortChangeSize(FuncSort func, Layout layout, size_t countTest,
                            size_t maxSize, size_t step,
                            int64_t minValue = INT64_MIN,
                            int64_t maxValue = INT64_MAX);

void autoTestSortChangeRangeValue(FuncSort func, Layout layout,
                                  size_t countTest, size_t sizeArr,
                                  int64_t minValue, int64_t maxValue,
                                  size_t step);
}  // namespace tests

#endif  // _TESTS_HPP_