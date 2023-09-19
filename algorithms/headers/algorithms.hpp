#ifndef _ALGORITHMS_HPP_
#define _ALGORITHMS_HPP_

#include <vector>

#include "avltree.hpp"


namespace algs {
using pos_t = int64_t;

void quickSort(std::vector<int64_t>& arr, pos_t left, pos_t right);
void avlSort(std::vector<int64_t>& arr);
}  // namespace algs

#endif  // _ALGORITHMS_HPP_