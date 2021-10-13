//
// Created by kmv026 on 06.10.2021.
//

#ifndef LABA3_IENUMERABLE_HPP
#define LABA3_IENUMERABLE_HPP
#include "RandomAccessIterator.hpp"
#include "IterImplementation.hpp"

template<typename T>
class IEnumerable {
public:
    virtual Implementation<RandomAccessIterator<T>> begin() = 0;
    virtual Implementation<RandomAccessIterator<T>> end() = 0;
};
#endif //LABA3_IENUMERABLE_HPP
