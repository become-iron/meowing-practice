#include "qsort.h"
#include "bubble.h"
#include "selection.h"
#include "merge.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstdlib>

template <class T>
bool isEqual(const std::vector<T>& first, const std::vector<T>& second) {
    if (first.size() != second.size())
        return false;

    for (auto firstIter = first.begin(), secondIter = second.begin(); firstIter != first.end(); ++firstIter, ++secondIter) {
        if (*firstIter != *secondIter)
            return false;
    }

    return true;
}

void test() {
    std::srand(std::chrono::steady_clock::now().time_since_epoch().count());
    const size_t size = 100000;

    std::vector<int> v1;
    for (size_t i = 0; i < size; ++i) {
        v1.push_back(rand());
    }

    std::vector<int> v2(v1);
    std::sort(v1.begin(), v1.end());
    qsort(v2.begin(), v2.end());

    std::cout << "Arrays are " << (isEqual(v1, v2) ? "equal" : "unequal");
}

int main() {
    test();
}
