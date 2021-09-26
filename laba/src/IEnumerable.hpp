//
// Created by kmv026 on 14.09.2021.
//

#ifndef LABA3_IENUMERABLE_HPP
#define LABA3_IENUMERABLE_HPP
#include "IEnumerator.hpp"
using namespace std;

class IEnumerable {
public:
    virtual Enumerator begin() = 0;
    virtual Enumerator end() = 0;
    virtual ~IEnumerable() = default;
};

#endif //LABA3_IENUMERABLE_HPP
