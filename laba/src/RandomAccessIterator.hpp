//
// Created by kmv026 on 19.09.2021.
//

#ifndef LABA3_RANDOMACCESSITERATOR_HPP
#define LABA3_RANDOMACCESSITERATOR_HPP

#include "Sequence.hpp"
#include "IEnumerator.hpp"

using namespace std;

//#include "BidirectionalIterator.hpp"


template<typename T>
class RandomAccessIterator : public IEnumerator<T, RandomAccessIterator> {
private:
    Sequence<T> &iterable;
//    using IEnumerator = IEnumerator<T, RandomAccessIterator>;

public:
    explicit RandomAccessIterator(Sequence<T> &it, size_t pos = 0) : IEnumerator<T, RandomAccessIterator>(pos),
                                                                     iterable(it) {}

    RandomAccessIterator(const RandomAccessIterator &other) : IEnumerator<T, RandomAccessIterator>(other.pos),
                                                              iterable(other.iterable) {}

    virtual T &operator*() const { return iterable[this->pos]; }

    virtual T *operator->() { return &iterable[this->pos]; }

//    operator int() const
//    {
//        return this->pos;
//    }

    // Prefix increment
    virtual RandomAccessIterator &operator++() {
        ++this->pos;
        return *this;
    }

    virtual RandomAccessIterator &operator--() {
        --this->pos;
        return *this;
    }

    // Postfix increment
    virtual RandomAccessIterator operator++(int) { // NOLINT(cert-dcl21-cpp)
        RandomAccessIterator tmp = RandomAccessIterator(*this);
        ++(*this);
        return tmp;
    }

    virtual RandomAccessIterator operator--(int) { // NOLINT(cert-dcl21-cpp)
        RandomAccessIterator tmp = RandomAccessIterator(*this);
        --(*this);
        return tmp;
    }

    virtual RandomAccessIterator &operator-=(size_t num) {
        *this = *this - num;
        return *this;
    };

    virtual bool Equals(const RandomAccessIterator &b) const {
        return (this->iterable == b.iterable) && (this->GetPos() == b.GetPos());
    }

    virtual RandomAccessIterator operator-(const RandomAccessIterator &b) const {
//        IEnumerator &tmp = RandomAccessIterator(*this);
        return RandomAccessIterator(this->iterable, this->pos - b.GetPos());
    }

    virtual RandomAccessIterator operator-(const size_t &b) const {
        return RandomAccessIterator(this->iterable, this->pos - b);
    }

//    IEnumerator &operator/(const IEnumerator *b) const override {
//        return new IEnumerable(this->iterable, this->pos / b);
//    }

    virtual RandomAccessIterator operator/(const size_t &b) const {
        if (b == 0)
            throw invalid_argument("b equals 0");
        return RandomAccessIterator(this->iterable, this->pos / b);
    }

    virtual RandomAccessIterator operator+(const RandomAccessIterator &b) const {
        return RandomAccessIterator(this->iterable, this->pos + b.GetPos());
    }

    virtual RandomAccessIterator operator+(const size_t &b) const {
        return RandomAccessIterator(this->iterable, this->pos + b);
    }

    virtual bool operator<(const size_t &b) const {
        return this->GetPos() < b;
    }

    virtual bool operator<=(const size_t &b) const {
        return this->GetPos() <= b;
    }

    virtual bool operator>(const size_t &b) const {
        return this->GetPos() > b;
    }

    virtual bool operator>=(const size_t &b) const {
        return this->GetPos() >= b;
    }

    virtual bool operator<(const RandomAccessIterator<T> &b) const {
        return this->GetPos() < b.GetPos();
    }

    virtual bool operator<=(const RandomAccessIterator<T> &b) const {
        return this->GetPos() <= b.GetPos();
    }

    virtual bool operator>(const RandomAccessIterator<T> &b) const {
        return this->GetPos() > b.GetPos();
    }

    virtual bool operator>=(const RandomAccessIterator<T> &b) const {
        return this->GetPos() >= b.GetPos();
    }

    RandomAccessIterator<T> &operator=(const RandomAccessIterator<T> &list) {
        this->iterable = list.iterable;
        this->pos = list.pos;
        return *this;
    }

// c++ stuff

    ~RandomAccessIterator() = default;
};

#endif //LABA3_RANDOMACCESSITERATOR_HPP
