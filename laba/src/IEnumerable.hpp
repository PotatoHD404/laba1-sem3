//
// Created by kmv026 on 06.10.2021.
//

#ifndef LABA3_IENUMERABLE_HPP
#define LABA3_IENUMERABLE_HPP

#include "RandomAccessIterator.hpp"

template<typename T>
using Iter = RandomAccessIterator<T>;

template<typename T>
class IEnumerable {
public:
    virtual Iter<T> begin() = 0;

    virtual Iter<T> end() = 0;
};

#endif //LABA3_IENUMERABLE_HPP
