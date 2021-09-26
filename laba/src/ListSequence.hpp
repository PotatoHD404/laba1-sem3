//
// Created by korna on 20.03.2021.
//
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#ifndef LABA2_LISTSEQUENCE_H
#define LABA2_LISTSEQUENCE_H

#include "LinkedList.hpp"
#include <iostream>
#include <cstring>
#include <memory>
#include "Enumerable.hpp"
#include "BidirectionalIterator.hpp"

using namespace std;

template<typename T>
class ListSequence : public Enumerable<T> {
private:
    LinkedList<T> items;


public:
    ListSequence* Copy(){
        return new ListSequence<T>(*this);
    }

    //Creation of the object
    ListSequence() {
        items = LinkedList<T>();
    }

    explicit ListSequence(int count) : ListSequence((size_t) count) {
    }

    explicit ListSequence(size_t count) {
        items = LinkedList<T>(count);
    }

    ListSequence(T *items, size_t count) {
        this->items = LinkedList<T>(items, count);
    }

    ListSequence(const ListSequence<T> &list) {
        items = LinkedList<T>(list.items);
    }

    template<size_t N>
    explicit ListSequence(T (&items)[N]) : ListSequence(items, N) {}

    ListSequence(initializer_list<T> items) : ListSequence() {
        for (T item: items)
            this->Append(item);
    }

    explicit ListSequence(const LinkedList<T> &list) {
        items = LinkedList<T>(list);
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

    T &At(size_t index) {
        return items.At(index);
    }

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

    size_t Count() {
        return items.Count();
    }

    T &operator[](size_t index) {
        return items[index];
    }

    bool operator==(ListSequence<T> list) {
        size_t len = list.Count();
        if (len != this->items.Count())
            return false;
        for (size_t i = 0; i < len; ++i)
            if (this->At(i) != list.At(i))
                return false;

        return true;
    }

    //Operations
    void Clear() {
        while (items.Count()) items.PopFirst();
    }

    ListSequence<T> *Clone() const {
        return new ListSequence<T>(this->items);
    }

    template<typename T1>
    ListSequence<T1> *Init() const {
        return new ListSequence<T1>();
    }

    template<typename T1>
    ListSequence<T1> *Init(size_t count) const {
        return new ListSequence<T1>(count);
    }

#pragma clang diagnostic push
#pragma ide diagnostic ignored "HidingNonVirtualFunction"

    template<typename T1>
    ListSequence<T1> Map(T1 (*mapper)(T)) {
        auto *res = dynamic_cast<ListSequence<T1> *>(Enumerable<T>::template Map<T1, ListSequence>(mapper));
        auto res1 = ListSequence<T1>(res);
        delete res;
        return res1;
    }

#pragma clang diagnostic pop

#pragma clang diagnostic push
#pragma ide diagnostic ignored "HidingNonVirtualFunction"

    ListSequence<T> Where(bool(*predicate)(T)) {
        auto *res = dynamic_cast<ListSequence<T> *>(Enumerable<T>::template Where<ListSequence>(predicate));
        auto res1 = ListSequence<T>(res);
        delete res;
        return res1;
    }

#pragma clang diagnostic pop

    void Append(T item) {
        items.Append(item);
    }

    void Prepend(T item) {
        items.Prepend(item);
    }

    void InsertAt(size_t index, T item) {
        items.InsertAt(index, item);
    }

    T PopFirst() {
        return items.PopFirst();
    }

    T PopLast() {
        return items.PopLast();
    }

    T RemoveAt(size_t index) {
        if (index < 0 || index >= items.Count())
            throw range_error("index < 0 or index >= length");
        return items.RemoveAt(index);
    }

    ListSequence<T> *Concat(Sequence<T> &list) {
        auto *res = new ListSequence<T>();
        for (size_t i = 0; i < items.Count(); ++i) {
            res->Append(items.At(i));
        }
        for (size_t i = 0; i < list.Count(); ++i) {
            res->Append(list[i]);
        }
        return res;
    }

    ListSequence<T> &operator=(const ListSequence<T> &list) {
        items = LinkedList<T>(list.items);
        return *this;
    }
};


#endif //LABA2_LISTSEQUENCE_H
#pragma clang diagnostic pop