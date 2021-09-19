//
// Created by korna on 20.03.2021.
//
#ifndef LABA2_SEQUENCE_H
#define LABA2_SEQUENCE_H

#include "ICollection.hpp"
#include <iostream>
#include <memory>

using namespace std;

template<typename T>
class Sequence : public ICollection<T> {
public:
    Sequence() = default;

    virtual T &At(size_t index) = 0;
//    using iterator = SetIterator<typename BinarySearchTree<T>::iterator>;
//
//    iterator begin() const { return this->binary_search_tree.begin(); }
//
//    iterator end() const { return this->binary_search_tree.end(); };

    //Decomposition
    T &First() { return At(0); }

    T &Last() { return At(this->Count() - 1); }

    void Set(size_t index, T value) {
        At(index) = value;
    }

    virtual T &operator[](size_t index) = 0;

    friend ostream &operator<<(ostream &out, Sequence<T> &&x) {
        out << "[";
        size_t length = x.Count();
        for (size_t i = 0; i < length; ++i) {
            out << x[i];
            if (i != length - 1)
                out << ", ";
        }
        out << "]";
//        out << ")" << endl;
        return out;
    }
    friend istream &operator>>(istream &in, Sequence<T> &x) {
        string tmp;
        getline(in, tmp);
        stringstream ss(tmp);
        T t;
        while (ss >> t) {
            x.Append(t);
        }
        return in;
    }

    //Operations
    virtual void Append(T item) = 0;

    virtual void Prepend(T item) = 0;

    virtual void InsertAt(size_t index, T item) = 0;

    virtual T PopFirst() = 0;

    virtual T PopLast() = 0;

    virtual T RemoveAt(size_t index) = 0;

    virtual Sequence<T> *Concat(Sequence<T> &list) = 0;

    virtual Sequence<T> *Concat(const unique_ptr<Sequence<T>> &list) {
        return Concat(*list);
    }

    virtual ~Sequence() = default;
};

#endif //LABA2_SEQUENCE_H