//
// Created by korna on 20.03.2021.
//
#ifndef LABA2_ARRAYSEQUENCE_H
#define LABA2_ARRAYSEQUENCE_H

#include "Enumerable.hpp"
#include "DynamicArray.hpp"
#include "RandomAccessIterator.hpp"
#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

template<typename T>
class ArraySequence : public Enumerable<T> {
private:
    mutable DynamicArray<T> items;

public:
    ArraySequence Copy() {
        return ArraySequence<T>(*this);
    }

    //Creation of the object
    ArraySequence() : items() {}

    explicit ArraySequence(int count) : ArraySequence((size_t) count) {
    }

    explicit ArraySequence(size_t count) : items(count) {
    }

    ArraySequence(T *items, size_t count) : items(items, count) {
    }

    template<size_t N>
    explicit ArraySequence(T (&items)[N]) : ArraySequence(items, N) {}

    ArraySequence(initializer_list<T> items) : ArraySequence() {
        for (T item: items)
            this->Add(item);
    }

    ArraySequence(ArraySequence<T> const &list) : items(list.items) {
    }

    explicit ArraySequence(Sequence<T> &list) : ArraySequence((*dynamic_cast<ArraySequence<T> *>(&list))) {}

    explicit ArraySequence(Sequence<T> *list) : ArraySequence(*list) {}

    explicit ArraySequence(const ArraySequence<T> *list) : ArraySequence(*list) {}

    explicit ArraySequence(const unique_ptr<Sequence<T>> &list) : ArraySequence(list.get()) {}

    explicit ArraySequence(const unique_ptr<ArraySequence<T>> &list) : ArraySequence(*list) {}

    //Decomposition



    virtual T &Get(size_t index) const {
        return items.Get(index);
    }

    ArraySequence<T> *GetSubsequence(size_t startIndex, size_t endIndex) {
        if (startIndex < 0 || startIndex >= items.Count())
            throw range_error("index < 0 or index >= length");
        if (startIndex > endIndex)
            throw range_error("startIndex > endIndex");
        if (endIndex >= items.Count())
            throw range_error("endIndex >= length");
        auto *res = new ArraySequence<T>();
        for (size_t i = startIndex; i < endIndex + 1; ++i) {
            res->Add(items.Get(i));
        }
        return res;
    }

    [[nodiscard]] size_t Count() const {
        return items.Count();
    }

    virtual bool operator==(const Sequence<T> &list) {
        if(this == &list)
            return true;
        size_t len = list.Count();
        if (len != this->Count())
            return false;
        for (size_t i = 0; i < len; ++i)
            if (this->Get(i) != list.Get(i))
                return false;

        return true;
    }


    ArraySequence<T> *Subsequence(size_t startIndex, size_t endIndex) {
        if (startIndex < 0 || startIndex >= items.Count())
            throw range_error("index < 0 or index >= length");
        if (startIndex > endIndex)
            throw range_error("startIndex > endIndex");
        if (endIndex >= items.Count())
            throw range_error("endIndex >= length");
        auto *res = new ArraySequence<T>();
        res->items = items.GetSubArray(startIndex, endIndex);
        return res;
    }

//    bool operator==(ArraySequence<T> &&list) {
//        size_t len = list.Count();
//        if (len != this->items.Count())
//            return false;
//        for (size_t i = 0; i < len; ++i)
//            if (this->Get(i) != list.Get(i))
//                return false;
//
//        return true;
//    }

//    virtual bool operator==(ArraySequence<T> &list) {
//        size_t len = list.Count();
//        if (len != this->items.Count())
//            return false;
//        for (size_t i = 0; i < len; ++i)
//            if (this->Get(i) != list.Get(i))
//                return false;
//
//        return true;
//    }

    //Operations
    template<typename T1>
    ArraySequence<T1> *Init() const {
        return new ArraySequence<T1>();
    }

    template<typename T1>
    ArraySequence<T1> *Init(size_t count) const {
        return new ArraySequence<T1>(count);
    }

    ArraySequence<T> &Resize(size_t count) {
        items.Resize(count);
        return *this;
    }

    ArraySequence<T> &Add(T item) {
        items.Resize(items.Count() + 1);
        items.Set(items.Count() - 1, item);
        return *this;
    }

    virtual ArraySequence<T> &AddFirst(T item) {
        items.Resize(items.Count() + 1);
        for (size_t i = items.Count() - 1; i > 0; --i) {
            items.Set(i, items.Get(i - 1));
        }
        items.Set(0, item);
        return *this;
    }

    ArraySequence<T> &Insert(size_t index, T item) {
        if (index == 0)
            return AddFirst(item);
        items.Resize(items.Count() + 1);

        for (size_t i = items.Count() - 1; i > index; --i) {
            items.Set(i, items[i - 1]);
        }
        if (items.Count() - 2 != index)
            items.Set(index, item);
        else
            items.Set(items.Count() - 1, item);
        return *this;
    }

    virtual ArraySequence<T> &Concat(Sequence<T> &list) {
//        ArraySequence<T> *res = new ArraySequence<T>();
        for (size_t i = 0; i < items.Count(); ++i) {
            this->Add(items[i]);
        }
        for (size_t i = 0; i < list.Count(); ++i) {
            this->Add(list[i]);
        }
        return *this;
    }

    T RemoveFirst() {
        T res = items.Get(0);
        for (size_t i = 0; i < items.Count() - 1; ++i) {
            items.Set(i, items[i + 1]);
        }
        items.Resize(items.Count() - 1);
        return res;
    }

    T RemoveLast() {
        T res = items.Get(items.Count() - 1);
        items.Resize(items.Count() - 1);
        return res;
    }

    T RemoveAt(size_t index) {

        if (index < 0 || index >= items.Count())
            throw range_error("index < 0 or index >= length");
        T res = items[index];
        for (size_t i = index; i < items.Count() - 1; ++i) {
            items.Set(i, items[i + 1]);
        }
        items.Resize(items.Count() - 1);
        return res;
    }

    T &operator[](size_t index) const {
        return items[index];
    }

    ArraySequence<T> &Clear() {
        items.Resize(0);
        return *this;
    }

//    ArraySequence<T> *Concat(const ArraySequence<T> *list) {
//        return Concat(*list);
//    }

    ArraySequence<T> &operator=(const ArraySequence<T> &list) = default;
};

#endif //LABA2_ARRAYSEQUENCE_H