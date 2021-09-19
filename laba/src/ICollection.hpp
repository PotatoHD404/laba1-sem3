//
// Created by korna on 03.04.2021.
//

#ifndef LABA2_ICOLLECTION_H
#define LABA2_ICOLLECTION_H

#include "IEnumerable.hpp"

template<typename T>
class ICollection : public IEnumerable<T> {
public:
    //Decomposition

    virtual size_t Count() = 0;

    virtual bool Contains(T item) = 0;

    //Operations
    virtual void Clear() = 0;

    virtual void Add(T item) = 0;

    virtual T RemoveAt(size_t index) = 0;

    T Remove(T index) = 0;

    virtual ~ICollection() = default;
};

#endif //LABA2_ICOLLECTION_H