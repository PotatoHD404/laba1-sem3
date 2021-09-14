//
// Created by kmv026 on 14.09.2021.
//

#ifndef LABA3_IENUMERABLE_HPP
#define LABA3_IENUMERABLE_HPP
#include "IEnumerator.hpp"
template<typename T, template<typename> class Iter>
class IEnumerable {
public:
    virtual IEnumerator<T, Iter>& GetEnumerator() = 0;
    virtual ~IEnumerable() = default;
};

#endif //LABA3_IENUMERABLE_HPP
