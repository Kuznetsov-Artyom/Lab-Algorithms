#include <iostream>
#include <random>

#include "headers/tests.hpp"

int main(int argc, char* argv[], char** env) {
  tests::testAvlSort();
  tests::testQuickSort();

  std::random_device rd;
  std::mt19937 gen(rd());

  std::vector<int> elems(1'000'000);
  for (auto& elem : elems) elem = gen();

  size_t countTest = 10;

  tests::testAvlTreeLong(elems, countTest);
  tests::testQuickSortLong(elems, countTest);

  return 0;
}