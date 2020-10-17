#include "helpers.h"
#include <algorithm>
#include <iterator>
#include <vector>

namespace meowing {
template <class Iter, class Comp = DefaultComparator<typename Iter::value_type>>
void mergeSort(Iter begin, Iter end, const Comp &comp = Comp()) {
  size_t length = std::distance(begin, end);

  if (length <= 1) {
    return;
  }

  Iter middle = begin;
  std::advance(middle, length >> 1);

  mergeSort(begin, middle);
  mergeSort(middle, end);

  std::vector<typename Iter::value_type> buff;
  buff.reserve(length);
  Iter left = begin, right = middle;
  while (left < middle || right < end) {
    if (right >= end || left < middle && comp(*left, *right) <= 0) {
      buff.push_back(std::move(*left));
      ++left;
    } else {
      buff.push_back(std::move(*right));
      ++right;
    }
  }

  std::copy(std::make_move_iterator(buff.begin()),
            std::make_move_iterator(buff.end()), begin);
}
}; // namespace meowing
