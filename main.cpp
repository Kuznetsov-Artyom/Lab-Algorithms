#include <iostream>
#include <random>

#include "headers/tests.hpp"

int main(int argc, char* argv[], char** env) {
  std::vector<int> vec = tests::createRandomArray(10, 1, 100);

  std::cout << vec << '\n';


  return 0;
}