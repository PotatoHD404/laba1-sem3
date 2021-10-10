//
// Created by kmv026 on 14.09.2021.
//
//#include <iterator> // For std::forward_iterator_tag
//#include <cstddef>  // For std::ptrdiff_t

#ifndef LABA3_IENUMERATOR_H
#define LABA3_IENUMERATOR_H

// https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern
// Derived
template<typename T, template<typename> class Child>
class IEnumerator {
protected:
    size_t pos;
//    using iterator_category = std::forward_iterator_tag;
//    using difference_type   = std::ptrdiff_t;

public:
    typedef long difference_type; //almost always ptrdiff_t
    typedef T value_type; //almost always Seq
    typedef T &reference; //almost always Seq& or const Seq&
    typedef T *pointer; //almost always Seq* or const Seq*
    typedef std::random_access_iterator_tag iterator_category;  //usually std::forward_iterator_tag or similar
    explicit IEnumerator(size_t pos) : pos(pos) {}
//    explicit IEnumerator(Iter<Seq> &it, size_t pos) = 0;

//    IEnumerator(const IEnumerator &other) = 0;
//    virtual Child<Seq> Init() = 0;

    virtual T &operator*() const = 0;

//    virtual Seq *operator->() const = 0;

    // Prefix increment
    virtual Child<T> &operator++() = 0;

    // Postfix increment
    virtual Child<T> operator++(int) = 0; // NOLINT(cert-dcl21-cpp)

    virtual bool Equals(const Child<T> &b) const = 0;

    [[nodiscard]] size_t GetPos() const {
        return pos;
    }

    friend bool operator==(const Child<T> &a, const Child<T> &b) {
        return a.Equals(b);
    }

    friend bool operator!=(const Child<T> &a, const Child<T> &b) {
        return !a.Equals(b);
    }


// c++ stuff

    virtual ~IEnumerator() = default;
};

#endif //LABA3_IENUMERATOR_H
