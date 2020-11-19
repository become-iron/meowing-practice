#include "helpers.h"
#include <utility>

namespace meowing {
template <class Iter, class Comp = DefaultComparator<typename Iter::value_type>>
void selectionSort(Iter begin, Iter end, const Comp &comp = Comp()) {
  Iter start = begin;
  while (start != end) {
    Iter min = start;
    for (Iter iter = start; iter != end; ++iter) {
      if (comp(*min, *iter) > 0) {
        min = iter;
      }
    }
    std::swap(*min, *start);
    ++start;
  }
}
} // namespace meowing
