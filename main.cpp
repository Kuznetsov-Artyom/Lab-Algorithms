#include <iostream>
#include <random>

#include "tests.hpp"

/*
Create a folder "res" in the root of the project
*/

int main(int argc, char* argv[], char** env) {
  // Tests quickSort (ChangeValue)
  tests::autoTestSortChangeRangeValue(
      tests::FuncSort::QUICK, tests::Layout::NO_SORT, 10, 1'000'000, 1, 100, 1);

  tests::autoTestSortChangeRangeValue(
      tests::FuncSort::QUICK, tests::Layout::INC_SORT, 10, 1'000'000, 1, 100, 1);

  tests::autoTestSortChangeRangeValue(
      tests::FuncSort::QUICK, tests::Layout::DEC_SORT, 10, 1'000'000, 1, 100, 1);


  // Tests avlSort (ChangeValue)
  tests::autoTestSortChangeRangeValue(
      tests::FuncSort::AVL, tests::Layout::NO_SORT, 10, 1'000'000, 1, 100, 1);

  tests::autoTestSortChangeRangeValue(
      tests::FuncSort::AVL, tests::Layout::INC_SORT, 10, 1'000'000, 1, 100, 1);

  tests::autoTestSortChangeRangeValue(
      tests::FuncSort::AVL, tests::Layout::DEC_SORT, 10, 1'000'000, 1, 100, 1);


  // Tests quickSort (ChangeSize)
  tests::autoTestSortChangeSize(
      tests::FuncSort::QUICK, tests::Layout::NO_SORT, 10, 1'000'001, 100'000);

  tests::autoTestSortChangeSize(
      tests::FuncSort::QUICK, tests::Layout::INC_SORT, 10, 1'000'001, 100'000);

  tests::autoTestSortChangeSize(
      tests::FuncSort::QUICK, tests::Layout::DEC_SORT, 10, 1'000'001, 100'000);


  // Tests avlSort (ChangeSize)
  tests::autoTestSortChangeSize(
      tests::FuncSort::AVL, tests::Layout::NO_SORT, 10, 1'000'001, 100'000);

  tests::autoTestSortChangeSize(
      tests::FuncSort::AVL, tests::Layout::INC_SORT, 10, 1'000'001, 100'000);

  tests::autoTestSortChangeSize(
      tests::FuncSort::AVL, tests::Layout::DEC_SORT, 10, 1'000'001, 100'000);

  return 0;
}