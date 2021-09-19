//
// Created by kmv026 on 14.09.2021.
//
//#include <iterator> // For std::forward_iterator_tag
//#include <cstddef>  // For std::ptrdiff_t

#ifndef LABA3_IENUMERATOR_H
#define LABA3_IENUMERATOR_H

template<typename T>
class IEnumerator {
private:
    size_t pos;
//    using iterator_category = std::forward_iterator_tag;
//    using difference_type   = std::ptrdiff_t;

public:
//    explicit IEnumerator(Iter<T> &it, size_t pos) = 0;

    IEnumerator(const IEnumerator &other) = 0;

    virtual T &operator*() const = 0;

    virtual T *operator->() const = 0;

    // Prefix increment
    virtual IEnumerator &operator++() = 0;

    // Postfix increment
    virtual IEnumerator &operator++(int) = 0; // NOLINT(cert-dcl21-cpp)

    virtual bool Equals(const IEnumerator &b) const = 0;

    virtual IEnumerator &operator-(const IEnumerator &b) const = 0;

    virtual IEnumerator &operator-(const size_t &b) const = 0;

    virtual IEnumerator &operator/(const IEnumerator &b) const = 0;

    virtual IEnumerator &operator/(const size_t &b) const = 0;

    virtual IEnumerator &operator+(const IEnumerator &b) const = 0;

    virtual IEnumerator &operator+(const size_t &b) const = 0;

    friend bool operator==(const IEnumerator &a, const IEnumerator &b) {
        return a.Equals(b);
    }

    friend bool operator!=(const IEnumerator &a, const IEnumerator &b) {
        return !a.Equals(b);
    }


// c++ stuff

    virtual ~IEnumerator() = default;
};

#endif //LABA3_IENUMERATOR_H
