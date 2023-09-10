#include "tests.hpp"

std::vector<int> tests::createRandomArray(size_t size, Layout layout,
                                          int minValue, int maxValue) {
  gen::Generator<int> generator(minValue, maxValue);

  std::vector<int> elems(size);
  for (auto& elem : elems) elem = generator();

  if (layout == Layout::INC_SORT)
    std::sort(elems.begin(), elems.end());
  else if (layout == Layout::DEC_SORT)
    std::sort(elems.rbegin(), elems.rend());

  return elems;
}

void tests::testAvlSort() {
  std::cout << __FUNCTION__ << "()\n";

  std::vector<int> elems{5, 2, 1, -100, INT_MAX, 12, 0, 32, 90};

  std::cout << "before: " << elems << '\n';
  algs::avlSort(elems);
  std::cout << "after: " << elems << '\n';
}

void tests::testQuickSort() {
  std::cout << __FUNCTION__ << "()\n";

  std::vector<int> elems{5, 2, 1, -100, INT_MAX, 1, 1, 1, 1, 12, 0, 32, 90};

  std::cout << "before: " << elems << '\n';
  algs::quickSort(elems, 0, elems.size() - 1);
  std::cout << "after: " << elems << '\n';
}

void tests::testAvlTreeLong(size_t sizeArr, size_t countTest, Layout layout, int minValue,
                            int maxValue) {
  std::cout << __FUNCTION__ << "()\n";

  std::vector<int> elems = createRandomArray(sizeArr, layout, minValue, maxValue);
  long long total = 0;

  for (size_t i = 0; i < countTest; ++i) {
    std::vector<int> arr(elems);

    TIMER_START(timer, tmr::millisecond_t);
    algs::avlSort(elems);
    total += TIMER_GET(timer);
  }

  std::cout << "size:\t\t" << sizeArr << '\n';
  std::cout << "tests:\t\t" << countTest << '\n';
  std::cout << "avg time:\t" << total / countTest << " ms\n";
}

void tests::testQuickSortLong(size_t sizeArr, size_t countTest, Layout layout, int minValue,
                              int maxValue) {
  std::cout << __FUNCTION__ << "()\n";

  std::vector<int> elems = createRandomArray(sizeArr, layout, minValue, maxValue);
  long long total = 0;

  for (size_t i = 0; i < countTest; ++i) {
    std::vector<int> arr(elems);

    TIMER_START(timer, tmr::millisecond_t);
    algs::quickSort(elems, 0, elems.size() - 1);
    total += TIMER_GET(timer);
  }
  std::cout << "size:\t\t" << sizeArr << '\n';
  std::cout << "tests:\t\t" << countTest << '\n';
  std::cout << "avg time:\t" << total / countTest << " ms\n";
}