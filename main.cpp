#include <iostream>
#include <memory>
#include <vector>

#include "headers/algorithms.hpp"
#include "headers/avltree.hpp"
#include "headers/timer.hpp"

template <typename T, template <typename Elem, typename = std::allocator<Elem>>
                      class Container>
std::ostream& operator<<(std::ostream& out, const Container<T>& cont) {
  auto itBegin = cont.begin();
  auto itEnd = cont.begin() + cont.size() - 1;

  for (; itBegin != itEnd; ++itBegin) out << *itBegin << ' ';
  return out << *itBegin;
}

int main(int argc, char* argv[], char** env) {
  // std::vector<int> values{3, 5, 7, 2, 1, -2, 5, 7};
  // tmr::Timer<tmr::nanosecond_t> timer;

  // algs::quickSort(values, 0, values.size() - 1);

  // std::cout << timer() << '\n';

  std::vector<int> elems{10, 30, 20, 40, 15};

  std::cout << "No sorted: " << elems << '\n';
  algs::avlSort(elems);
  std::cout << "Sorted: " << elems << '\n';

  return 0;
}