//
// Created by korna on 03.04.2021.
//
#ifndef LABA2_ENUMERABLE_H
#define LABA2_ENUMERABLE_H

#include "Sequence.hpp"
#include "RandomAccessIterator.hpp"
#include "IEnumerable.hpp"
#include "ISorter.hpp"

using namespace std;

template<typename T>
/*abstract*/
class Enumerable : public Sequence<T>, public IEnumerable<T>, public ISorter<T> {
public:
    virtual RandomAccessIterator <T> begin() { return RandomAccessIterator<T>(*this); }
    virtual RandomAccessIterator <T> end() { return RandomAccessIterator<T>(*this, this->Count()); }

    bool Contains(T item) {
        for (size_t i = 0; i < this->Count(); ++i)
            if (this->Get(i) == item)
                return true;
        return false;
    }

//     Shell
    virtual Enumerable<T> &Sort(Sorts::Sort sort) {
        switch (sort) {
            case Sorts::Shell:
                this->ShellSort(*this);
                break;
            case Sorts::Insertion:
                this->InsertionSort(*this);
                break;
            case Sorts::Quick:
                this->QuickSort(*this);
                break;
            default:
                throw invalid_argument("Wrong sort type");
                break;
        }
        return *this;
    }

    virtual T Remove(T item) {

        for (auto ptr = this->begin(); ptr < this->end(); ptr++)
            if (*ptr == item)
                return this->RemoveAt(ptr.GetPos());
        throw invalid_argument("Item was not found");
    }

protected:
    Enumerable<T> &InsertionSort(Enumerable<T> &arr) {

        //TODO: implement
        return arr;
    }

    Enumerable<T> &QuickSort(Enumerable<T> &arr) {
//        auto first = arr.begin();
//        auto last = arr.end();
//        if (first != last) {
//            auto left = first;
//            auto right = last;
//            auto pivot = left++;
//
//            while (left != right) {
//                if (cmp(*left, *pivot)) {
//                    ++left;
//                } else {
//                    while ((left != right) && cmp(*pivot, *right))
//                        --right;
//                    std::iter_swap(left, right);
//                }
//            }
//
//            --left;
//            std::iter_swap(pivot, left);
//
//            quick_sort(first, left);
//            quick_sort(right, last);
//        }
        return arr;
    }

    Enumerable<T> &ShellSort(Enumerable<T> &arr) {
//        auto first = arr.begin();
//        auto last = arr.end();
//        for (auto d = (arr.Count()) / 2; d != 0; d /= 2)
//            //нужен цикл для first = a[0..d-1]
//            for (auto i = first + d; i != last; ++i)
//                for (auto j = i; j - first >= d && comp(*j, *(j - d)); j -= d)
//                    std::swap(*j, *(j - d));
        return arr;
    }


    virtual ~Enumerable() = default;
};


#endif //LABA2_ENUMERABLE_H