#include <iostream>
#include <memory>
#include <random>
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

static void testAvlSort() {
  std::cout << __FUNCTION__ << "()\n";

  std::vector<int> elems{5, 2, 1, -100, INT_MAX, 12, 0, 32, 90};

  std::cout << "before: " << elems << '\n';
  algs::avlSort(elems);
  std::cout << "after: " << elems << '\n';
}

static void testQuickSort() {
  std::cout << __FUNCTION__ << "()\n";

  std::vector<int> elems{5, 2, 1, -100, INT_MAX,1,1,1,1, 12, 0, 32, 90};

  std::cout << "before: " << elems << '\n';
  algs::quickSort(elems, 0, elems.size() - 1);
  std::cout << "after: " << elems << '\n';
}

static void testAvlTreeLong(std::vector<int> elems) {
  TIMER_START(timer, tmr::millisecond_t);
  algs::avlSort(elems);
  std::cout << TIMER_GET(timer) << '\n';
}

static void testQuickSortLong(std::vector<int> elems) {
  TIMER_START(timer, tmr::millisecond_t);
  algs::quickSort(elems, 0, elems.size() - 1);
  std::cout << TIMER_GET(timer) << '\n';
}

int main(int argc, char* argv[], char** env) {
  testAvlSort();
  testQuickSort();

  std::random_device rd;
  std::mt19937 gen(rd());

  std::vector<int> elems(1'000'000);
  for (auto& elem : elems) elem = gen();

  testAvlTreeLong(elems);
  testQuickSortLong(elems);

  return 0;
}