#include "tests.hpp"

std::vector<int64_t> tests::createRandomArray(size_t size, Layout layout,
                                              int64_t minValue,
                                              int64_t maxValue) {
  gen::Generator<int64_t> generator(minValue, maxValue);

  std::vector<int64_t> elems(size);
  for (auto& elem : elems) elem = generator();

  if (layout == Layout::INC_SORT)
    std::sort(elems.begin(), elems.end());
  else if (layout == Layout::DEC_SORT)
    std::sort(elems.rbegin(), elems.rend());

  return elems;
}

void tests::testAvlSort() {
  std::cout << __FUNCTION__ << "()\n";

  std::vector<int64_t> elems{5, 2, 1, -100, INT_MAX, 12, 0, 32, 90};

  std::cout << "before: " << elems << '\n';
  algs::avlSort(elems);
  std::cout << "after: " << elems << '\n';
}

void tests::testQuickSort() {
  std::cout << __FUNCTION__ << "()\n";

  std::vector<int64_t> elems{5, 2, 1, -100, INT_MAX, 12, 0, 32, 90};

  std::cout << "before: " << elems << '\n';
  algs::quickSort(elems, 0, elems.size() - 1);
  std::cout << "after: " << elems << '\n';
}

void tests::testSort(FuncSort func, Layout layout, size_t sizeArr,
                     size_t countTest, int64_t minValue, int64_t maxValue) {
  std::vector<int64_t> elems =
      createRandomArray(sizeArr, layout, minValue, maxValue);
  long long total = 0;

  if (func == FuncSort::AVL) {
    for (size_t i = 0; i < countTest; ++i) {
      std::vector<int64_t> arr(elems);

      TIMER_START(timer, tmr::millisecond_t);
      algs::avlSort(elems);
      total += TIMER_GET(timer);
    }
  } else {
    for (size_t i = 0; i < countTest; ++i) {
      std::vector<int64_t> arr(elems);

      TIMER_START(timer, tmr::millisecond_t);
      algs::quickSort(elems, 0, elems.size() - 1);
      total += TIMER_GET(timer);
    }
  }

  std::cout << "sort:\t\t";
  if (func == FuncSort::QUICK)
    std::cout << "QUICK\n";
  else
    std::cout << "AVL\n";

  std::cout << "layout\t\t";
  if (layout == Layout::INC_SORT)
    std::cout << "INC_SORT\n";
  else if (layout == Layout::DEC_SORT)
    std::cout << "DEC_SORT\n";
  else
    std::cout << "NO_SORT\n";

  std::cout << "size:\t\t" << sizeArr << '\n';
  std::cout << "tests:\t\t" << countTest << '\n';
  std::cout << "avg time:\t" << total / countTest << " ms\n\n";
}

void tests::autoTestSort(FuncSort func, Layout layout, size_t countTest,
                         size_t maxSize, size_t step, int64_t minValue,
                         int64_t maxValue) {
  for (size_t sizeArr = 1; sizeArr <= maxSize; sizeArr += step)
    tests::testSort(func, layout, sizeArr, countTest, minValue, maxValue);
}