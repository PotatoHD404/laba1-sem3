//
// Created by kmv026 on 13.10.2021.
//

#ifndef LABA3_ILIST_HPP
#define LABA3_ILIST_HPP

#include "ICollection.hpp"
#include "IEnumerable.hpp"

template<typename T>
class IList : public ICollection<T>, public IEnumerable<T> {
public:
    virtual T RemoveAt(size_t index) = 0;

    virtual T &Get(size_t index) const = 0;

    virtual T &operator[](size_t index) const = 0;

    virtual bool operator==(const IList<T> &list) = 0;

    void Set(size_t index, T value) {
        Get(index) = value;
    }

    virtual ~IList() = default;
};

#endif //LABA3_ILIST_HPP
