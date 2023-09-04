#include <iostream>
#include <vector>

#include "headers/timer.hpp"

int main(int argc, char* argv[], char** env) {
  tmr::Timer<tmr::millisecond_t> timer;

  std::vector<int> values;

  for (int i = 0; i < 1'000'000; ++i) values.push_back(i + 1);

  std::cout << timer() << '\n';

  return 0;
}