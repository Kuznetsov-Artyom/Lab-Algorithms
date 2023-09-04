#include <iostream>
#include <vector>

#include "headers/algorithms.hpp"
#include "headers/timer.hpp"

template <typename Period>
void func() {
  tmr::Timer<Period> timer;
}

int main(int argc, char* argv[], char** env) {
  std::vector<int> values{3, 5, 7, 2, 1, -2, 5, 7};
  tmr::Timer<tmr::nanosecond_t> timer;

  func<tmr::second_t>();

  algs::quickSort(values, 0, values.size() - 1);

  std::cout << timer() << '\n';

  return 0;
}