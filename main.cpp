#include <iostream>
#include <random>

#include "tests.hpp"

int main(int argc, char* argv[], char** env) {
  tests::autoTestSortChangeRangeValue(
      tests::FuncSort::QUICK, tests::Layout::DEC_SORT, 1, 1'000'000, 1, 100, 1);

  tests::autoTestSortChangeSize(tests::FuncSort::QUICK, tests::Layout::NO_SORT, 1, 1'000'001, 100'000);

  return 0;
}