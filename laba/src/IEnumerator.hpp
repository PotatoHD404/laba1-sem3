//
// Created by kmv026 on 14.09.2021.
//
#include <iterator>
#include <algorithm>

#ifndef LABA3_IENUMERATOR_H
#define LABA3_IENUMERATOR_H

template<typename T, template<typename> class Iter>
class IEnumerator : public std::iterator<std::input_iterator_tag, T,                      // value_type
        long,                      // difference_type
        const T *,               // pointer
        T  // reference
> {
private:
    Iter<T> &iterable;
    T *current;

    IEnumerator(const IEnumerator &other) : IEnumerator(other.iterable) {}

public:
    explicit IEnumerator(Iter<T>& it) : iterable(it) {}

    virtual bool MoveNext() = 0;

    virtual void Reset() = 0;

// c++ stuff
    T Current() { return *current; }

    T operator*() const { return current; }

    IEnumerator &operator++() {
        MoveNext();
        return *this;
    }

    IEnumerator &operator++(int) { // NOLINT(cert-dcl21-cpp)
        IEnumerator temp = *this;
        MoveNext();
        return temp;
    }

    bool operator==(IEnumerator &other) const { return *current == *other.current; }

    bool operator!=(IEnumerator &other) const { return iterable != other.iterable; }

    virtual ~IEnumerator() = default;
};

#endif //LABA3_IENUMERATOR_H
