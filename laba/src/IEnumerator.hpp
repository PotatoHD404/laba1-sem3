//
// Created by kmv026 on 14.09.2021.
//

#ifndef LABA3_IENUMERATOR_H
#define LABA3_IENUMERATOR_H

template<typename T>
class IEnumerator: std::iterator<std::input_iterator_tag, Iter>{
public:
    T current;
    virtual bool MoveNext() = 0;
    virtual void Reset() = 0;

    virtual ~IEnumerator() = default;
};

#endif //LABA3_IENUMERATOR_H
