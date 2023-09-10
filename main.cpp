#include <iostream>
#include <random>

#include "headers/tests.hpp"

int main(int argc, char* argv[], char** env) {
  tests::autoTestSort(tests::FuncSort::AVL, tests::Layout::NO_SORT, 5,
                      1'000'001, 100'000, 1, 1'000'000'000);
  return 0;
}