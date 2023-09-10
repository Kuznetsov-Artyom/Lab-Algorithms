#include <iostream>
#include <random>

#include "headers/tests.hpp"

int main(int argc, char* argv[], char** env) {
  tests::autoTestSortChangeRangeValue(
      tests::FuncSort::QUICK, tests::Layout::DEC_SORT, 100, 1'000'000, 1, 100, 1);

  return 0;
}