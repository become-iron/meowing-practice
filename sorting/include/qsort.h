#include "helpers.h"
#include <iterator>

namespace meowing {
template <class Iter, class Comp = DefaultComparator<typename Iter::value_type>>
void qsort(Iter begin, Iter end, const Comp &comp = Comp()) {
  if (std::distance(begin, end) <= 1)
    return;

  auto splitValue = *begin;
  auto _begin = begin, _end = end - 1;
  while (_begin <= _end) {

    while (comp(*_begin, splitValue) < 0) {
      ++_begin;
    }

    while (comp(splitValue, *_end) < 0) {
      --_end;
    }

    if (_end <= _begin) {
      break;
    }

    std::swap(*_begin, *_end);
    ++_begin;
    --_end;
  }

  auto middle = _end + 1;
  qsort(begin, middle, comp);
  qsort(middle, end, comp);
}
} // namespace meowing
