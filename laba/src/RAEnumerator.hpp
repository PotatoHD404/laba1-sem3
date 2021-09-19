//
// Created by kmv026 on 19.09.2021.
//

#ifndef LABA3_RAENUMERATOR_HPP
#define LABA3_RAENUMERATOR_HPP

#include "IEnumerator.hpp"
#include "Sequence.hpp"

template<typename T>
class RAEnumerator : public IEnumerator<T> {
private:
    size_t pos;
    Sequence<T> &iterable;
    using IEnumerator = IEnumerator<T>;
//    using iterator_category = std::forward_iterator_tag;
//    using difference_type   = std::ptrdiff_t;

public:
    explicit RAEnumerator(Sequence<T> &it) : iterable(it), pos(0) {}

    RAEnumerator(const RAEnumerator &other) : IEnumerator(other.iterable), pos(other.pos) {}

    T &operator*() const override { return iterable[pos]; }

    T *operator->() override { return &iterable[pos]; }

    // Prefix increment
    IEnumerator &operator++() override {
        pos++;
        return *this;
    }

    // Postfix increment
    IEnumerator &operator++(int) override { // NOLINT(cert-dcl21-cpp)
        IEnumerator &tmp = RAEnumerator();
        ++(*this);
        return tmp;
    }

    bool Equals(const IEnumerator &b) const override {}

    IEnumerator &operator-(const IEnumerator &b) const override {}

    IEnumerator &operator-(const size_t &b) const override {}

    IEnumerator &operator/(const IEnumerator &b) const override {}

    IEnumerator &operator/(const size_t &b) const override {}

    IEnumerator &operator+(const IEnumerator &b) const override {}

    IEnumerator &operator+(const size_t &b) const override {}

    friend bool operator==(const IEnumerator &a, const IEnumerator &b) {
        return a.Equals(b);
    }

    friend bool operator!=(const IEnumerator &a, const IEnumerator &b) {
        return !a.Equals(b);
    }


// c++ stuff

    ~RAEnumerator() = default;
};

#endif //LABA3_RAENUMERATOR_HPP
