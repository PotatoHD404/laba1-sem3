//
// Created by korna on 03.04.2021.
//
#ifndef LABA2_ENUMERABLE_H
#define LABA2_ENUMERABLE_H

#include "Sequence.hpp"
#include <vector>
#include <tuple>
#include <iostream>
//#include <variant>

using namespace std;

template<typename T>
/*abstract*/
class Enumerable : public Sequence<T> {
protected:
    template<typename T1, template<typename> class ChildClass>
    Enumerable<T1> *Map(T1 (*mapper)(T)) {
        if (mapper == nullptr)
            throw std::invalid_argument("mapper is NULL");
        size_t length = this->Count();
        Enumerable<T1> *res = new ChildClass<T1>(length);
        for (size_t i = 0; i < length; i++)
            res->At(i) = mapper(this->At(i));
        return res;
    }

    template<template<typename> class ChildClass>
    Enumerable<T> *Where(bool(*predicate)(T)) {
        if (predicate == nullptr)
            throw std::invalid_argument("predicate is NULL");
        Enumerable<T> *res = new ChildClass<T>();
        for (size_t i = 0; i < this->Count(); i++)
            if (predicate(this->At(i)))
                res->Append(this->At(i));
        return res;
    }

public:

    auto Split(size_t pos) {
        auto res = make_tuple(this->Subsequence(0, pos), this->Subsequence(pos + 1, this->Count() - 1));
        return res;
    }

    bool Contains(T item) {
        for (size_t i = 0; i < this->Count(); ++i)
            if (this->At(i) == item)
                return true;
        return false;
    }

    virtual Enumerable<T> *Subsequence(size_t begin, size_t end) = 0;

    T Reduce(T(*f)(T, T), T const c) {
        if (f == nullptr)
            throw std::invalid_argument("mapper is NULL");
        T res = c;
        for (size_t i = 0; i < this->Count(); ++i) {
            res = f(this->At(i), res);
        }
        return res;
    }

    virtual ~Enumerable() = default;
};


#endif //LABA2_ENUMERABLE_H