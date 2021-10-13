//
// Created by kmv026 on 06.10.2021.
//

#ifndef LABA3_IENUMERABLE_HPP
#define LABA3_IENUMERABLE_HPP
#include "RandomAccessIterator.hpp"
#include "IterImplementation.hpp"

template<typename T>
using Iter = Implementation<RandomAccessIterator<T>>;

template<typename T>
class IEnumerable {
public:
    virtual Iter<T> begin() const= 0;
    virtual Iter<T> end() const= 0;
};
#endif //LABA3_IENUMERABLE_HPP
