//
// Created by kmv026 on 19.09.2021.
//

#ifndef LABA3_BIDIRECTIONALITERATOR_HPP
#define LABA3_BIDIRECTIONALITERATOR_HPP

#include "IEnumerator.hpp"
#include "Sequence.hpp"

template<typename T>
class BidirectionalIterator : public IEnumerator<T, BidirectionalIterator> {
private:
    size_t pos;
    Sequence<T> &iterable;
    using IEnumerator = IEnumerator<T, BidirectionalIterator>;
//    using iterator_category = std::forward_iterator_tag;
//    using difference_type   = std::ptrdiff_t;

public:
    explicit BidirectionalIterator(const Sequence<T> &it, size_t pos = 0) : iterable(it), pos(pos) {}

    BidirectionalIterator(const BidirectionalIterator &other) : IEnumerator(other.iterable), pos(other.pos) {}

    T &operator*() const override { return iterable[pos]; }

    T *operator->() override { return &iterable[pos]; }

    // Prefix increment
    BidirectionalIterator& operator++() override {
        pos++;
        return *this;
    }

    BidirectionalIterator& operator--() override {
        pos--;
        return *this;
    }

    // Postfix increment
    BidirectionalIterator& operator++(int) override { // NOLINT(cert-dcl21-cpp)
        IEnumerator *tmp = new BidirectionalIterator(*this);
        ++(*this);
        return tmp;
    }

    BidirectionalIterator& operator--(int) override { // NOLINT(cert-dcl21-cpp)
        IEnumerator *tmp = new BidirectionalIterator(*this);
        --(*this);
        return tmp;
    }

    bool Equals(const IEnumerator& b) const override { return (*this)->iterable == b->iterable; }

    BidirectionalIterator operator-(const IEnumerator *b) const override {
//        IEnumerator &tmp = BidirectionalIterator(*this);
        return new BidirectionalIterator(this->iterable, this->pos - b->GetPos());
    }

    BidirectionalIterator operator-(const size_t &b) const override {
        return new BidirectionalIterator(this->iterable, this->pos - b);
    }

//    IEnumerator &operator/(const IEnumerator *b) const override {
//        return new IEnumerable(this->iterable, this->pos / b);
//    }

    BidirectionalIterator operator/(const size_t &b) const override {
        if (b == 0)
            throw invalid_argument("b equals 0");
        return BidirectionalIterator(this->iterable, this->pos / b);
    }

    BidirectionalIterator operator+(const IEnumerator *b) const override {
        return BidirectionalIterator(this->iterable, this->pos + b->GetPos());
    }

    BidirectionalIterator operator+(const size_t &b) const override {
        return BidirectionalIterator(this->iterable, this->pos + b);
    }




// c++ stuff

    ~BidirectionalIterator() = default;
};

#endif //LABA3_BIDIRECTIONALITERATOR_HPP
