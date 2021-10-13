//
// Created by korna on 20.03.2021.
//
#ifndef LABA2_LISTSEQUENCE_H
#define LABA2_LISTSEQUENCE_H

#include "LinkedList.hpp"
#include <iostream>
#include <cstring>
#include <memory>
#include "Enumerable.hpp"


using namespace std;

template<typename T>
class ListSequence : public Enumerable<T> {
private:
    mutable LinkedList<T> items;

public:
    virtual Iter<T> begin() const { return items.begin(); }

    virtual Iter<T> end() const { return items.end(); }

    ListSequence Copy() {
        return ListSequence<T>(*this);
    }

    //Creation of the object
    ListSequence() : items() {}

    explicit ListSequence(int count) : ListSequence((size_t) count) {
    }

    explicit ListSequence(size_t count) : items(count) {}

    ListSequence(T *items, size_t count) : items(items, count) {
    }

    ListSequence(const ListSequence<T> &list) : items(list.items) {
    }

    template<size_t N>
    explicit ListSequence(T (&items)[N]) : ListSequence(items, N) {}

    ListSequence(initializer_list<T> items) : ListSequence() {
        for (T item: items)
            this->Add(item);
    }

    explicit ListSequence(const LinkedList<T> &list) : items(list) {
    }

    explicit ListSequence(Sequence<T> &list) : ListSequence((*dynamic_cast<ListSequence<T> *>(&list))) {
    }

    explicit ListSequence(Sequence<T> *list) : ListSequence(*list) {
    }

    explicit ListSequence(const ListSequence<T> *list) : ListSequence(*list) {
    }

    explicit ListSequence(const unique_ptr<Sequence<T>> &list) : ListSequence(list.get()) {
    }

    explicit ListSequence(const unique_ptr<ListSequence<T>> &list) : ListSequence(*list) {
    }

    //Decomposition

    virtual T &Get(size_t index) const {
        return items.Get(index);
    }

    using Enumerable<T>::Sort;

    virtual Enumerable<T> &Sort() { return this->Enumerable<T>::Sort(Sorts::InsertionSort<T>); }

    ListSequence<T> *Subsequence(size_t startIndex, size_t endIndex) {
        if (startIndex < 0 || startIndex >= items.Count())
            throw range_error("index < 0 or index >= length");
        if (startIndex > endIndex)
            throw range_error("startIndex > endIndex");
        if (endIndex >= items.Count())
            throw range_error("endIndex >= length");
        auto *res = new ListSequence<T>();
        res->items = items.GetSubList(startIndex, endIndex);
        return res;
    }

    [[nodiscard]] size_t Count() const {
        return items.Count();
    }

    T &operator[](size_t index) const {
        return items[index];
    }
//    virtual bool operator==(const Sequence<Seq> &list) = 0;

    virtual bool operator==(const IList<T> &list) {
        return items == list;
    }

    //Operations
    ListSequence<T> &Clear() {
        while (items.Count()) items.RemoveFirst();
        return *this;
    }

//    ListSequence<Seq> Copy() const {
//        return ListSequence<Seq>(this->items);
//    }

    ListSequence<T> &Add(T item) {
        items.Add(item);
        return *this;
    }

    ListSequence<T> &AddFirst(T item) {
        items.AddFirst(item);
        return *this;
    }

    ListSequence<T> &Insert(size_t index, T item) {
        items.Insert(index, item);
        return *this;
    }

    T RemoveFirst() {
        return items.RemoveFirst();
    }

    T RemoveLast() {
        return items.RemoveLast();
    }

    T RemoveAt(size_t index) {
        if (index < 0 || index >= items.Count())
            throw range_error("index < 0 or index >= length");
        return items.RemoveAt(index);
    }

    ListSequence<T> &Concat(Sequence<T> &list) {
        for (size_t i = 0; i < items.Count(); ++i) {
            this->Add(items.Get(i));
        }
        for (size_t i = 0; i < list.Count(); ++i) {
            this->Add(list[i]);
        }
        return *this;
    }

    ListSequence<T> &operator=(const ListSequence<T> &list) = default;
};


#endif //LABA2_LISTSEQUENCE_H