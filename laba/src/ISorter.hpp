

//
// Created by kmv026 on 07.10.2021.
//

#ifndef LABA3_ISORTER_HPP
#define LABA3_ISORTER_HPP

#include <utility>

template<typename T>
class Enumerable;

template<typename T>
class ISort {
public:
    virtual Enumerable<T> &operator()(Enumerable<T> &arr) const = 0;
};

namespace std {
    template<typename T>
    int distance(const RandomAccessIterator<T> &ra1, const RandomAccessIterator<T> &ra2) {
        return abs((long) (ra1 - ra2).GetPos());
    }
}
namespace PrivateSorts {
    template<typename T>
    class QuickSort : public ISort<T> {
    private:
    public:

        Enumerable<T> &operator()(Enumerable<T> &arr) const final {
            quick_sort(arr.begin(), arr.end());
            return arr;
        }

    private:
        RandomAccessIterator<T>
        partition(const RandomAccessIterator<T> &start, const RandomAccessIterator<T> &end) const {
            auto partition_idx = start;
            for (auto i = start; i != end; i++) {
                if (*i <= *end) {
                    iter_swap(i, partition_idx);
                    partition_idx++;
                }
            }
            iter_swap(partition_idx, end);
            return partition_idx;
        }

        void quick_sort(const RandomAccessIterator<T> &start, const RandomAccessIterator<T> &end) const {
            int size = distance(start, end - 1);
            if (size <= 1) return;
            auto partition_idx = partition(start, end - 1);
            quick_sort(start, partition_idx - 1);
            quick_sort(partition_idx, end - 1);
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
                        iter_swap(j, (j - d));
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
        void insertion_sort(RandomAccessIterator<T> &&begin, RandomAccessIterator<T> &&end) const {
            if (begin == end) return; //If the range is empty, abort

            for (auto i = begin + 1; i < end; ++i) {
                auto j = i - 1;
                bool flag = false; //Used to abort the loop after j == begin case
                while (!flag && (j != begin || (flag = j == begin)) && *j > *i) {
                    *(j + 1) = *j;
                    j -= !flag; //If j == begin, don't decrement (Without branch)
                }
                *(j + 1) = *i;
            }
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
