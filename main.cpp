#include <iostream>
#include <vector>

#include "headers/algorithms.hpp"
#include "headers/timer.hpp"
#include "headers/avltree.hpp"

int main(int argc, char* argv[], char** env) {
  // std::vector<int> values{3, 5, 7, 2, 1, -2, 5, 7};
  // tmr::Timer<tmr::nanosecond_t> timer;

  // algs::quickSort(values, 0, values.size() - 1);

  // std::cout << timer() << '\n';

  std::vector<int> elems{ 10, 30, 20, 40, 15 };
	tree::avlTree<int> tree(elems);

	tree.print();
	for (const auto& elem : tree.getElems())
		std::cout << elem << ' ';
	std::cout << '\n';

  return 0;
}