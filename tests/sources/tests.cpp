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

std::string tests::createPath(std::string testName, FuncSort func,
                              Layout layout) {
  std::string path{"..\\..\\res\\"};

  if (func == FuncSort::AVL)
    path += "AvlTest";
  else
    path += "QuickTest";

  path += testName;

  if (layout == Layout::INC_SORT)
    path += "IncSort.txt";
  else if (layout == Layout::DEC_SORT)
    path += "DecSort.txt";
  else
    path += "NoSort.txt";

  return path;
}

void tests::testAvlSort() {
  std::cout << __FUNCTION__ << "()\n";

  std::vector<int64_t> elems{5, 2, 1, 1, 1, 1, -100, INT_MAX, 12, 0, 32, 90};

  std::cout << "before: " << elems << '\n';
  algs::avlSort(elems);
  std::cout << "after: " << elems << '\n';
}

void tests::testQuickSort() {
  std::cout << __FUNCTION__ << "()\n";

  std::vector<int64_t> elems{5, 2, 1, 1, 1, 1, -100, INT_MAX, 12, 0, 32, 90};

  std::cout << "before: " << elems << '\n';
  algs::quickSort(elems, 0, elems.size() - 1);
  std::cout << "after: " << elems << '\n';
}

int64_t tests::testSort(FuncSort func, Layout layout, size_t sizeArr,
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
  std::cout << "minV:\t\t" << minValue << '\n';
  std::cout << "maxV:\t\t" << maxValue << '\n';
  std::cout << "tests:\t\t" << countTest << '\n';
  std::cout << "avg time:\t" << total / countTest << " ms\n\n";

  return total / countTest;
}

void tests::autoTestSortChangeSize(FuncSort func, Layout layout,
                                   size_t countTest, size_t maxSize,
                                   size_t step, int64_t minValue,
                                   int64_t maxValue) {
  // std::fstream fout(createPath("ChangeSize", func, layout),
  //                   std::fstream::out | std::fstream::app);

  std::fstream fout(createPath("ChangeSize", func, layout), std::fstream::out);

  for (size_t sizeArr = 1; sizeArr <= maxSize; sizeArr += step) {
    fout << sizeArr << ' ';
    int64_t resTime =
        testSort(func, layout, sizeArr, countTest, minValue, maxValue);
    fout << resTime << '\n';
  }

  fout.close();
}

void tests::autoTestSortChangeRangeValue(FuncSort func, Layout layout,
                                         size_t countTest, size_t sizeArr,
                                         int64_t minValue, int64_t maxValue,
                                         size_t step) {
  std::fstream fout(createPath("ChangeRangeValue", func, layout),
                    std::fstream::out | std::fstream::app);

  for (int64_t value = minValue; value <= maxValue; value += step) {
    fout << value << ' ';
    int64_t resTime =
        testSort(func, layout, sizeArr, countTest, minValue, value);
    fout << resTime << '\n';
  }

  fout.close();
}
