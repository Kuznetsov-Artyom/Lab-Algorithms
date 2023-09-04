#ifndef _ALGORITHMS_HPP_
#define _ALGORITHMS_HPP_

#include <vector>

namespace algs {
using pos_t = int64_t;

template <typename T>
void quickSort(std::vector<T>& arr, pos_t left, pos_t right) {
  if (left > right) return;
  int value = arr[(left + right) >> 1];
  pos_t l = left;
  pos_t r = right;

  while (l <= r) {
    while (arr[l] < value) ++l;
    while (arr[r] > value) --r;

    if (l <= r) {
      std::swap(arr[l], arr[r]);
      ++l;
      --r;
    }
  }

  quickSort(arr, left, r);
  quickSort(arr, l, right);
}
}  // namespace algs

#endif  // _ALGORITHMS_HPP_