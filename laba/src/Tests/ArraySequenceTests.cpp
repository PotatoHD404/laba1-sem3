//
// Created by korna on 17.04.2021.
//

#ifndef TEST_DB_ARRAYSEQUENCETESTS_H
#define TEST_DB_ARRAYSEQUENCETESTS_H

#include "gtest/gtest.h"
//#include "../ArraySequence.hpp"

//TEST(ArraySequence_int, InitDefault) {
//    ArraySequence<int> arr = ArraySequence<int>();
//    ASSERT_EQ(0, arr.Count());
//    EXPECT_ANY_THROW(arr.GetFirst());
//    EXPECT_ANY_THROW(arr.GetLast());
//}
//
//TEST(ArraySequence_int, InitCount_Set_Clear) {
//    EXPECT_ANY_THROW(ArraySequence<int>(-1));
//    ArraySequence<int> arr = ArraySequence<int>(2);
//    ASSERT_EQ (2, arr.Count());
//    arr[0] = 1;
//    EXPECT_EQ (1, arr[0]);
//    EXPECT_EQ (0, arr[1]);
//    EXPECT_EQ (1, arr.GetFirst());
//    EXPECT_EQ (0, arr.GetLast());
//    arr = ArraySequence<int>(0);
//    ASSERT_EQ (0, arr.Count());
//    arr = ArraySequence<int>(10);
//    ASSERT_EQ (10, arr.Count());
//    arr.Clear();
//    EXPECT_EQ (0, arr.Count());
//}
//
//
//TEST(ArraySequence_int, Append) {
//    ArraySequence<int> arr = ArraySequence<int>();
//    arr.Append(5);
//    ASSERT_EQ (1, arr.Count());
//    EXPECT_ANY_THROW(arr.At(-1));
//    EXPECT_ANY_THROW(arr.At(1));
//    EXPECT_EQ (5, arr[0]);
//
//    arr[0] = 4;
//    EXPECT_EQ (4, arr[0]);
//    EXPECT_EQ (4, arr.GetFirst());
//    EXPECT_EQ (4, arr.GetLast());
//    EXPECT_ANY_THROW(arr.Set(-1, 1));
//    EXPECT_ANY_THROW(arr.Set(1, 1));
//
//    arr.Append(5);
//    ASSERT_EQ (2, arr.Count());
//    arr.Set(0, 1);
//    EXPECT_EQ (1, arr[0]);
//    EXPECT_EQ (5, arr[1]);
//    EXPECT_EQ (1, arr.GetFirst());
//    EXPECT_EQ (5, arr.GetLast());
//
//    arr.Append(3);
//    ASSERT_EQ (3, arr.Count());
//    EXPECT_EQ (1, arr[0]);
//    EXPECT_EQ (5, arr[1]);
//    EXPECT_EQ (3, arr[2]);
//    EXPECT_EQ (1, arr.GetFirst());
//    EXPECT_EQ (3, arr.GetLast());
//}


#endif //TEST_DB_ARRAYSEQUENCETESTS_H