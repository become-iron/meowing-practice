#include <utility>
#include "helpers.h"

template <class Iter, class Comp = DefaultComparator<typename Iter::value_type>>
void bubbleSort(Iter begin, Iter end, const Comp& comp = Comp()) {
    for (Iter last = end; begin != last; --last) {
        Iter prev = begin;
        for (Iter current = prev + 1; current != last; ++current) {
            if (comp(*prev, *current) > 0) {
                std::swap(*prev, *current);
            }
            prev = current;
        }
    }
}

