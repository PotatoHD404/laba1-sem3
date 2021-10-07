//
// Created by korna on 03.04.2021.
//

#ifndef LABA2_ICOLLECTION_H
#define LABA2_ICOLLECTION_H




template<typename T>
class ICollection {
public:
    //Decomposition

    [[nodiscard]] virtual size_t Count() const = 0;

    virtual bool Contains(T item) = 0;

    //Operations
    virtual ICollection<T> &Clear() = 0;

    virtual ICollection<T> &Add(T item) = 0;

    virtual T Remove(T item) = 0;

    virtual ~ICollection() = default;
};

#endif //LABA2_ICOLLECTION_H