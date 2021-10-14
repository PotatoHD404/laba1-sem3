//
// Created by kmv026 on 19.09.2021.
//

#ifndef LABA3_RANDOMACCESSITERATOR_HPP
#define LABA3_RANDOMACCESSITERATOR_HPP

using namespace std;

//#include "BidirectionalIterator.hpp"
template<typename T>
class IList;


template<typename T>
class RandomAccessIterator {
protected:
    using Iter = RandomAccessIterator;
    size_t pos;
    IList<T> &iterable;

//    using IEnumerator = IEnumerator<Seq, RandomAccessIterator>;

public:
    using type = T;
    typedef long difference_type; //almost always ptrdiff_t
    typedef T value_type; //almost always Seq
    typedef T &reference; //almost always Seq& or const Seq&
    typedef T *pointer; //almost always Seq* or const Seq*
    typedef std::random_access_iterator_tag iterator_category;  //usually std::forward_iterator_tag or similar


    explicit RandomAccessIterator(IList<T> &it, size_t pos = 0) : pos(pos), iterable(it) {}

    RandomAccessIterator(const Iter &other) : pos(other.pos), iterable(other.iterable) {}




//    explicit IEnumerator(Iter<Seq> &it, size_t pos) = 0;

//    IEnumerator(const IEnumerator &other) = 0;
//    virtual Child<Seq> Init() = 0;


//    virtual Seq *operator->() const = 0;

    // Prefix increment

    // Postfix increment

    [[nodiscard]] size_t GetPos() const {
        return pos;
    }

    friend bool operator==(const Iter &a, const Iter &b) {
        return a.Equals(b);
    }

    friend bool operator!=(const Iter &a, const Iter &b) {
        return !a.Equals(b);
    }


// c++ stuff




    virtual T &operator*() const { return iterable[this->pos]; }

    virtual T *operator->() { return &iterable[this->pos]; }

//    operator int() const
//    {
//        return this->pos;
//    }

    // Prefix increment
    virtual Iter &operator++() {
        ++this->pos;
        return *this;
    }

    virtual Iter &operator--() {
        --this->pos;
        return *this;
    }

    // Postfix increment
    virtual Iter operator++(int) { // NOLINT(cert-dcl21-cpp)
        Iter tmp = Iter(*this);
        ++(*this);
        return Iter(tmp);
    }

    virtual Iter operator--(int) { // NOLINT(cert-dcl21-cpp)
        Iter tmp = Iter(*this);
        --(*this);
        return Iter(tmp);
    }

    virtual bool Equals(const Iter &b) const {
        return (this->iterable == b.iterable) && (this->GetPos() == b.GetPos());
    }

    virtual Iter operator-(const Iter &b) const {
//        IEnumerator &tmp = RandomAccessIterator(*this);
        return Iter(Iter(this->iterable, this->pos - b.GetPos()));
    }

    virtual Iter operator-(const size_t &b) const {
        return Iter(Iter(this->iterable, this->pos - b));
    }

//    IEnumerator &operator/(const IEnumerator *b) const override {
//        return new IEnumerable(this->iterable, this->pos / b);
//    }

    virtual Iter operator/(const size_t &b) const {
        if (b == 0)
            throw invalid_argument("b equals 0");
        return Iter(Iter(this->iterable, this->pos / b));
    }
    virtual Iter& operator-=(const Iter &b) {
        *this - b;
        return *this;
    }
    virtual Iter& operator+=(const Iter &b) {
        *this + b;
        return *this;
    }
    virtual Iter& operator+=(const size_t &b) {
        *this + b;
        return *this;
    }
    virtual Iter& operator-=(const size_t &b) {
        *this - b;
        return *this;
    }

    virtual Iter operator+(const Iter &b) const {
        return Iter(Iter(this->iterable, this->pos + b.GetPos()));
    }

    virtual Iter operator+(const size_t &b) const {
        return Iter(Iter(this->iterable, this->pos + b));
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

    virtual bool operator<(const Iter &b) const {
        return this->GetPos() < b.GetPos();
    }

    virtual bool operator<=(const Iter &b) const {
        return this->GetPos() <= b.GetPos();
    }

    virtual bool operator>(const Iter &b) const {
        return this->GetPos() > b.GetPos();
    }

    virtual bool operator>=(const Iter &b) const {
        return this->GetPos() >= b.GetPos();
    }

    RandomAccessIterator &operator=(const Iter &list) {
        if (this != &list) {
            this->iterable = list.iterable;
            this->pos = list.pos;
        }
        return *this;
    }

// c++ stuff

    virtual ~RandomAccessIterator() {};
};

#endif //LABA3_RANDOMACCESSITERATOR_HPP
