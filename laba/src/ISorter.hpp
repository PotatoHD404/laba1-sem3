

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
            quick_sort(arr.begin(), arr.end(), [](T a, T b) { return a < b; });
            return arr;
        }

    private:
        /// Quick Sort, allow user-defined less-than operator
        template<typename RandomIt, typename Compare>
        RandomIt Partition(RandomIt first, RandomIt last, Compare compare) const {
            auto pivot = std::prev(last, 1);
            auto i = first;
            for (auto j = first; j != pivot; ++j) {
                // bool format
                if (compare(*j, *pivot)) {
                    std::swap(*i++, *j);
                }
            }
            std::swap(*i, *pivot);
            return i;
        }

        template<typename RandomIt, typename Compare>
        void quick_sort(RandomIt first, RandomIt last, Compare compare) const {
            if (std::distance(first, last) > 1) {
                RandomIt bound = Partition(first, last, compare);
                quick_sort(first, bound, compare);
                quick_sort(bound + 1, last, compare);
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
            iter_swap(begin, min_element(begin, end));
            for (RandomAccessIterator<T> b = begin; ++b < end; begin = b)
                for (RandomAccessIterator<T> c = b; *c < *begin; --c, --begin)
                    iter_swap(begin, c);
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
