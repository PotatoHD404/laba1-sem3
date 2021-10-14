//
// Created by kmv026 on 10.10.2021.
//

#ifndef LABA3_SORTTESTS_H
#define LABA3_SORTTESTS_H

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include <array>
#include <algorithm>
#include <random>
#include <type_traits>
#include <limits>
#include <chrono>
#include <gtest/gtest.h>
#include "../ListSequence.hpp"
#include "../ArraySequence.hpp"
#include "../Complex.hpp"

// https://stackoverflow.com/questions/55892577/how-to-test-the-same-behaviour-for-multiple-templated-classes-with-different-tem

// https://github.com/google/googletest/blob/master/docs/advanced.md#type-parameterized-tests

using namespace std;

template<typename T>
T GenRandom(mt19937 &rng) {
    if constexpr(std::is_same<T, string>::value) {
        static string alphanum = "0123456789"
                                 "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                 "abcdefghijklmnopqrstuvwxyz";
        uniform_int_distribution<unsigned> distribution(0, alphanum.length() - 1);
        string res;
        for (int i = 0; i < 5; ++i) {
            res += alphanum[distribution(rng)];
        }
        return res;
    } else if constexpr(std::is_same<T, Complex>::value) {
        uniform_real_distribution<float> distribution(-1, 1);
        return Complex((float) distribution(rng), (float) distribution(rng));
    } else if constexpr(std::is_same<T, int>::value) {
        uniform_int_distribution<int> distribution(-100, 100);
        return (int) distribution(rng);
    } else if constexpr(std::is_same<T, float>::value) {
        uniform_real_distribution<float> distribution(-10, 10);
        return (float) distribution(rng);
    } else {
        throw NotImplemented("", "");
    }
}

template<typename Seq>
class Sorts_Test : public testing::Test {
public:
    using T = typename Seq::type;

    static auto const &test_data() {
        static random_device rd;
        static mt19937::result_type seed = rd() ^ (
                (mt19937::result_type)
                        chrono::duration_cast<chrono::seconds>(
                                chrono::system_clock::now().time_since_epoch()
                        ).count() +
                (mt19937::result_type)
                        chrono::duration_cast<chrono::microseconds>(
                                chrono::high_resolution_clock::now().time_since_epoch()
                        ).count());
        static mt19937 rng = mt19937(seed);
        static array<T, 100> data;
        static bool called;
        if (!called) {
            generate(
                    data.begin(), data.end(), []() { return GenRandom<T>(rng); });
            called = true;
        }
        return data;
    }

    void SetUp() override {


    }

    void TearDown() override {
//        delete globalObject;
//        globalObject = nullptr;
    }


};

TYPED_TEST_SUITE_P(Sorts_Test);

TYPED_TEST_P(Sorts_Test, QuickSort) {
    // Inside a test, refer to TypeParam to get the type parameter.
    using Seq = TypeParam;
    using T = typename Seq::type;
    Enumerable<T> &&seq = Seq();
    array<T, 100> test_data = this->test_data();
    vector<T> data(test_data.begin(), test_data.end());
    for (const T& el: test_data) {
        seq.Add(el);
    }
    seq.Sort(Sorts::QuickSort<T>);
    sort(data.begin(), data.end());
    auto begin = seq.begin();
    for (const T& el: data) {
        EXPECT_EQ(*(begin++), el);
    }

}

TYPED_TEST_P(Sorts_Test, ShellSort) {
    // Inside a test, refer to TypeParam to get the type parameter.
    using Seq = TypeParam;
    using T = typename Seq::type;
    Enumerable<T> &&seq = Seq();
    array<T, 100> test_data = this->test_data();
    vector<T> data(test_data.begin(), test_data.end());
    for (const T& el: test_data) {
        seq.Add(el);
    }
    seq.Sort(Sorts::ShellSort<T>);
    sort(data.begin(), data.end());
    auto begin = seq.begin();
    for (const T& el: data) {
        EXPECT_EQ(*(begin++), el);
    }


}

TYPED_TEST_P(Sorts_Test, InsertionSort) {
    // Inside a test, refer to TypeParam to get the type parameter.
    using Seq = TypeParam;
    using T = typename Seq::type;
    Enumerable<T> &&seq = Seq();
    array<T, 100> test_data = this->test_data();
    vector<T> data(test_data.begin(), test_data.end());
    for (const T& el: test_data) {
        seq.Add(el);
    }
    seq.Sort(Sorts::InsertionSort<T>);
    sort(data.begin(), data.end());
    auto begin = seq.begin();
    for (const T& el: data) {
        EXPECT_EQ(*(begin++), el);
    }


}

template<template<typename> class C, typename ...Ts>
using test_types = ::testing::Types<C<Ts>...>;

using ListSequence_test_types = test_types<ListSequence, int>;
using ArraySequence_test_types = test_types<ArraySequence, int>;


REGISTER_TYPED_TEST_SUITE_P(Sorts_Test,
                            QuickSort, ShellSort, InsertionSort);

INSTANTIATE_TYPED_TEST_SUITE_P(ListSequence, Sorts_Test, ListSequence_test_types);
INSTANTIATE_TYPED_TEST_SUITE_P(ArraySequence, Sorts_Test, ArraySequence_test_types);


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#pragma clang diagnostic pop
#endif //LABA3_SORTTESTS_H
