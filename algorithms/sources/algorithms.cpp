#include "algorithms.hpp"

void algs::quickSort(std::vector<int64_t>& arr, pos_t left, pos_t right) {
  if (left > right) return;
  int64_t value = arr[(left + right) >> 1];
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

void algs::avlSort(std::vector<int64_t>& arr){
  tree::avlTree<int64_t> tree(arr);
  arr = tree.getElems();
}