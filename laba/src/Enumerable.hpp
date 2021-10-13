//
// Created by korna on 03.04.2021.
//
#ifndef LABA2_ENUMERABLE_H
#define LABA2_ENUMERABLE_H

#include "Sequence.hpp"
#include "IEnumerable.hpp"
#include "ISortable.hpp"

using namespace std;

template<typename T>
/*abstract*/
class Enumerable : public Sequence<T> {
public:
//    using Sequence<Seq>::operator<<;
//    using Sequence<Seq>::operator>>;

    virtual Iter<T> begin() const {
        return Iter<T>(new RandomAccessIterator<T>(*this));
    }

    virtual Iter<T> end() const {
        return Iter<T>(new RandomAccessIterator<T>(*this, this->Count() > 0 ? this->Count() : 0));
    }

    bool Contains(T item) {
        for (size_t i = 0; i < this->Count(); ++i)
            if (this->Get(i) == item)
                return true;
        return false;
    }

//     Shell
    virtual Enumerable<T> &Sort() { return this->Sort(Sorts::QuickSort<T>); }

    virtual Enumerable<T> &Sort(const ISort<T> &sort) {
        return (Enumerable<T> &) sort(*this);
    }

    virtual T Remove(T item) {
        for (auto ptr = this->begin(); ptr < this->end(); ptr++)
            if (*ptr == item)
                return this->RemoveAt(ptr.GetPos());
        throw invalid_argument("Item was not found");
    }

    virtual ~Enumerable() = default;
};


#endif //LABA2_ENUMERABLE_H