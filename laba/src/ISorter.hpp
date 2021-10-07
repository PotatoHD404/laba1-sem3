//
// Created by kmv026 on 07.10.2021.
//

#ifndef LABA3_ISORTER_HPP
#define LABA3_ISORTER_HPP

template<typename T>
class Enumerable;

namespace Sorts {
    enum Sort {
        Shell, Insertion, Quick
    };
}
//using namespace Sorts;
template<typename T>
class ISorter {
    virtual Enumerable<T> &Sort(Sorts::Sort sort) = 0;
};

#endif //LABA3_ISORTER_HPP
