#ifndef HELPERS_H
#define HELPERS_H

template <class T>
class DefaultComparator {
public:
    int operator() (const T& first, const T& second) const {
        return first == second ? 0 :
                                 first < second ? -1 : 1;
    }
};

#endif // HELPERS_H
