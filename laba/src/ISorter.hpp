#include <utility>

//
// Created by kmv026 on 07.10.2021.
//

#ifndef LABA3_ISORTER_HPP
#define LABA3_ISORTER_HPP

template<typename T>
class Enumerable;

template<typename T>
class ISort {
public:
    virtual Enumerable<T> &operator()(Enumerable<T> &arr) const = 0;
};

namespace PrivateSorts {
    template<typename T>
    class QuickSort : public ISort<T> {
    public:
        Enumerable<T> &operator()(Enumerable<T> &arr) const final {
            quick_sort(arr.begin(), arr.end());
            return arr;
        }

    private:
        void quick_sort(const RandomAccessIterator<T> &first, const RandomAccessIterator<T> &last) const {

            if (first != last) {
                auto left = first;
                auto right = last;
                auto pivot = left++;

                while (left != right) {
                    if (*left < *pivot) {
                        ++left;
                    } else {
                        while ((left != right) && *pivot < *right)
                            --right;
                        std::iter_swap(left, right);
                    }
                }

                --left;
                std::iter_swap(pivot, left);

                quick_sort(first, left);
                quick_sort(right, last);
            }
        }
    };

    template<typename T>
    class ShellSort : public ISort<T> {
    public:
        Enumerable<T> &operator()(Enumerable<T> &arr) const final {
            shell_sort(arr.begin(), arr.end());
            return arr;
        }

    private:
        void shell_sort(RandomAccessIterator<T> &&first, RandomAccessIterator<T> &&last) const {
            for (auto d = (last.GetPos()) / 2; d != 0; d /= 2)
                for (auto i = first + d; i != last; ++i)
                    for (auto j = i; j - first >= d && *j < *(j - d); j -= d)
                        std::swap(*j, *(j - d));
        }
    };

    template<typename T>
    class InsertionSort : public ISort<T> {
    public:
        Enumerable<T> &operator()(Enumerable<T> &arr) const final {
            insertion_sort(arr.begin(), arr.end());
            return arr;
        }

    private:
        void insertion_sort(RandomAccessIterator<T> &&first, RandomAccessIterator<T> &&last) const {
            std::iter_swap(first, std::min_element(first, last));
            for (RandomAccessIterator<T> b = first; ++b < last; first = b)
                for (RandomAccessIterator<T> c = b; *c < *first; --c, --first)
                    std::iter_swap(first, c);
        }
    };
}
namespace Sorts {

    template<typename T>
    static PrivateSorts::QuickSort<T> QuickSort;

    template<typename T>
    static PrivateSorts::ShellSort<T> ShellSort;

    template<typename T>
    static PrivateSorts::InsertionSort<T> InsertionSort;

//    enum Sort {
//        Shell, Insertion, Quick
//    };
}

template<typename T>
class ISorter {
public:
    virtual Enumerable<T> &Sort(const ISort<T> &sort) = 0;
};

#endif //LABA3_ISORTER_HPP
