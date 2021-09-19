//
// Created by kmv026 on 14.09.2021.
//

#ifndef LABA3_SORT_H
#define LABA3_SORT_H
#include "Sequence.hpp"

enum Sorts { Shell, Insertion, Quick };

template<typename T>
Sequence<T>* Sort(const Sequence<T>& seq, Sorts sort){
    Sequence<T>* res = nullptr;
    switch (sort) {
        case Shell:
            res = ShellSort(seq);
            break;
        case Insertion:
            res = InsertionSort(seq);
            break;
        case Quick:
            res = QuickSort(seq);
            break;
        default:
            std::cout << "Wrong sort type!\n";
            break;
    }
    return res;
}

template<typename T>
Sequence<T>* InsertionSort(const Sequence<T> & seq)
{
    Sequence res = new Sequence(seq);
    //TODO: implement
    return res;
}

template<typename T>
Sequence<T>* QuickSort(const Sequence<T> & seq)
{
    Sequence res = new Sequence(seq);
    //TODO: implement
    return res;
}


template<typename T>
Sequence<T>* ShellSort(const Sequence<T> & seq)
{
    Sequence res = new Sequence(seq);
//    for( auto d = ( res.last - res.first ) / 2; d != 0; d /= 2 )
//        //нужен цикл для first = a[0..d-1]
//        for( auto i = first + d; i != last; ++i )
//            for( auto j = i; j - first >= d && comp( *j, *( j - d ) ); j -= d )
//                std::swap( *j, *( j - d ) );
    return res;
}


#endif //LABA3_SORT_H
