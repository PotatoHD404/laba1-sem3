#include <utility>

//
// Created by kmv026 on 07.10.2021.
//

#ifndef LABA3_ISORTER_HPP
#define LABA3_ISORTER_HPP

template<typename T>
class Enumerable;

namespace Sorts {
    template<typename T>
    class ISort {
    public:
        virtual Enumerable<T> &Sort(Enumerable<T> &arr) = 0;
    };

    template<typename T>
    class QuickSort : public ISort<T> {
    public:
        Enumerable<T> &Sort(Enumerable<T> &arr) final {
            return arr;
        }
    };

    static QuickSort<int> quickSort;

//    class Status {
//    private:
//        int code;
//        string remark;
//    public:
//        Status(int code, string remark): code(code), remark(std::move(remark)) {
//        }
//    };
//
//    static Map CODES = new std::map();
//
//    static Status create(final int code, final String remark) {
//        final Integer key = new Integer(code);
//        final Status status;
//
//        if (!CODES.containsKey(key))
//            CODES.put(key, status = new Status(code, remark));
//        else
//            status = (Status) CODES.get(key);
//
//        return status;
//    }




    enum Sort {
        Shell, Insertion, Quick
    };
}
//using namespace Sorts;
template<typename T>
class ISorter {
public:
    virtual Enumerable<T> &Sort(Sorts::ISort<T> &sort) = 0;
};

#endif //LABA3_ISORTER_HPP
