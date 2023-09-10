#include <iostream>
#include <random>

#include "headers/tests.hpp"

int main(int argc, char* argv[], char** env) {
  // size_t sizeArr = 1'000'000;
  // size_t countTest = 1;

  // tests::testAvlSort();
  // tests::testQuickSort();

  // tests::testAvlTreeLong(sizeArr, countTest);
  // tests::testQuickSortLong(sizeArr, countTest);

  size_t size = 10;
  std::vector<int> vecOne = tests::createRandomArray(size, tests::Layout::NO_SORT, -10, 10);
  std::vector<int> vecTwo = tests::createRandomArray(size, tests::Layout::INC_SORT, -10, 10);
  std::vector<int> vecThree = tests::createRandomArray(size, tests::Layout::DEC_SORT, -10, 10);

  std::cout << vecOne << '\n' << vecTwo << '\n' << vecThree << '\n';

  return 0;
}