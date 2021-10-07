//
// Created by korna on 20.03.2021.
//
#ifndef LABA3_SEQUENCE_HPP
#define LABA3_SEQUENCE_HPP

#include "ICollection.hpp"
#include <iostream>
#include <memory>

using namespace std;

template<typename T>
class Sequence : public ICollection<T> {
public:
    Sequence() = default;

    virtual T &Get(size_t index) = 0;

    virtual T GetConst(size_t index) const = 0;

    //Decomposition
    virtual T &First() { return Get(0); }

    virtual T &Last() { return Get(this->Count() - 1); }

    void Set(size_t index, T value) {
        Get(index) = value;
    }

    virtual bool operator==(const Sequence<T> &list) = 0;

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
            x.Add(t);
        }
        return in;
    }

    //Operations
//    virtual shared_ptr<Sequence<T>> Copy() = 0;

    virtual Sequence &AddFirst(T item) = 0;

    virtual Sequence &Insert(size_t index, T item) = 0;

    virtual T RemoveFirst() = 0;

    virtual T RemoveLast() = 0;

    virtual T RemoveAt(size_t index) = 0;

    virtual T Remove(T item) = 0;

    virtual Sequence<T> &Concat(Sequence<T> &list) = 0;

    virtual Sequence<T> &Concat(const unique_ptr<Sequence<T>> &list) {
        return Concat(*list);
    }

    virtual ~Sequence() = default;
};

#endif //LABA3_SEQUENCE_HPP