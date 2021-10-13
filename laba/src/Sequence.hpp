//
// Created by korna on 20.03.2021.
//
#ifndef LABA3_SEQUENCE_HPP
#define LABA3_SEQUENCE_HPP

#include "IList.hpp"
#include "ISortable.hpp"
#include <iostream>
#include <memory>

using namespace std;

template<typename T>
class Sequence : public IList<T>, public ISortable<T> {
public:
    Sequence() = default;


    friend ostream &operator<<(ostream &out, const Sequence<T> &x) {
        out << "[";
        size_t length = x.Count();
        for (size_t i = 0; i < length; ++i) {
            if constexpr(std::is_same<T, string>::value) {
                out << "\'" << x[i] << "\'";
            } else {
                out << x[i];
            }
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
//    virtual shared_ptr<Sequence<Seq>> Copy() = 0;

    virtual Sequence &AddFirst(T item) = 0;

    virtual Sequence &Insert(size_t index, T item) = 0;

    virtual T RemoveFirst() = 0;

    virtual T RemoveLast() = 0;

    //Decomposition
    virtual T &First() { return this->Get(0); }

    virtual T &Last() { return this->Get(this->Count() - 1); }

    virtual Sequence<T> &Concat(Sequence<T> &list) = 0;

    virtual Sequence<T> &Concat(const unique_ptr<Sequence<T>> &list) {
        return Concat(*list);
    }

    virtual ~Sequence() = default;
};

#endif //LABA3_SEQUENCE_HPP