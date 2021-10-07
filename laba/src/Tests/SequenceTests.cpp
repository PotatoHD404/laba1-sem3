//
// Created by korna on 17.04.2021.
//


#ifndef TEST_DB_SEQUENCETESTS_H
#define TEST_DB_SEQUENCETESTS_H

#include "gtest/gtest.h"
#include <iostream>
#include "../ListSequence.hpp"
#include "../ArraySequence.hpp"

using namespace std;

//TEST(Sequence, ListSequence_Concat) {
//    int a[] = {1, 2, 3, 4, 5};
//    unique_ptr<Sequence<int>> arr1 = unique_ptr<Sequence<int>>(new ListSequence<int>(a, 5));
//    unique_ptr<Sequence<int>> arr2 = unique_ptr<Sequence<int>>(new ListSequence<int>(arr1));
//    unique_ptr<Sequence<int>> arr3 = unique_ptr<Sequence<int>>(arr1->Concat(arr2));
//    ASSERT_EQ (arr1->Count() + arr2->Count(), arr3->Count());
//    EXPECT_EQ (arr1->Get(0), arr3->Get(0));
//    EXPECT_EQ (arr1->Get(1), arr3->Get(1));
//    EXPECT_EQ (arr1->Get(2), arr3->Get(2));
//    EXPECT_EQ (arr1->Get(3), arr3->Get(3));
//    EXPECT_EQ (arr1->Get(4), arr3->Get(4));
//    EXPECT_EQ (arr2->Get(0), arr3->Get(5));
//    EXPECT_EQ (arr2->Get(1), arr3->Get(6));
//    EXPECT_EQ (arr2->Get(2), arr3->Get(7));
//    EXPECT_EQ (arr2->Get(3), arr3->Get(8));
//    EXPECT_EQ (arr2->Get(4), arr3->Get(9));
//
//    unique_ptr<Sequence<int>> arr4 = unique_ptr<Sequence<int>>(new ListSequence<int>());
//    arr3 = unique_ptr<Sequence<int>>(arr1->Concat(arr4));
//    ASSERT_EQ (arr1->Count() + arr4->Count(), arr3->Count());
//    EXPECT_EQ (arr1->Get(0), arr3->Get(0));
//    EXPECT_EQ (arr1->Get(1), arr3->Get(1));
//    EXPECT_EQ (arr1->Get(2), arr3->Get(2));
//    EXPECT_EQ (arr1->Get(3), arr3->Get(3));
//    EXPECT_EQ (arr1->Get(4), arr3->Get(4));
//}

//TEST(Sequence, ListSequence_Subsequence) {
//    int a[] = {1, 2, 3, 4, 5};
//    unique_ptr<Sequence<int>> arr1 = unique_ptr<Sequence<int>>(
//            dynamic_cast<Sequence<int> *>(new ListSequence<int>(a, 5)));
//    unique_ptr<Sequence<int>>
//            arr2 = unique_ptr<Sequence<int>>(dynamic_cast<Sequence<int> *>(arr1->Subsequence(0, 0)));
//    ASSERT_EQ(arr2->Count(), 1);
//    EXPECT_EQ (arr1->Get(0), 1);
//    EXPECT_ANY_THROW(arr2->Get(1));
//    EXPECT_ANY_THROW(arr1->Subsequence(-1, 0));
//    EXPECT_ANY_THROW(arr1->Subsequence(1, 0));
//    EXPECT_ANY_THROW(arr1->Subsequence(1, 5));
//    arr2 = unique_ptr<Sequence<int>>(dynamic_cast<Sequence<int> *>(arr1->Subsequence(0, 4)));
//    ASSERT_EQ(arr2->Count(), 5);
//    EXPECT_EQ (arr1->Get(0), arr2->Get(0));
//    EXPECT_EQ (arr1->Get(1), arr2->Get(1));
//    EXPECT_EQ (arr1->Get(2), arr2->Get(2));
//    EXPECT_EQ (arr1->Get(3), arr2->Get(3));
//    EXPECT_EQ (arr1->Get(4), arr2->Get(4));
//    arr2 = unique_ptr<Sequence<int>>(dynamic_cast<Sequence<int> *>(arr1->Subsequence(2, 3)));
//    ASSERT_EQ(arr2->Count(), 2);
//    EXPECT_EQ (arr1->Get(2), arr2->Get(0));
//    EXPECT_EQ (arr1->Get(3), arr2->Get(1));
//}


//TEST(Sequence, ArraySequence_Concat) {
//    int a[] = {1, 2, 3, 4, 5};
//    unique_ptr<Sequence<int>> arr1 = unique_ptr<Sequence<int>>(new ArraySequence<int>(a, 5));
//    unique_ptr<Sequence<int>> arr2 = unique_ptr<Sequence<int>>(new ArraySequence<int>(arr1));
//    unique_ptr<Sequence<int>> arr3 = unique_ptr<Sequence<int>>(arr1->Concat(arr2));
//    ASSERT_EQ (arr1->Count() + arr2->Count(), arr3->Count());
//    EXPECT_EQ (arr1->Get(0), arr3->Get(0));
//    EXPECT_EQ (arr1->Get(1), arr3->Get(1));
//    EXPECT_EQ (arr1->Get(2), arr3->Get(2));
//    EXPECT_EQ (arr1->Get(3), arr3->Get(3));
//    EXPECT_EQ (arr1->Get(4), arr3->Get(4));
//    EXPECT_EQ (arr2->Get(0), arr3->Get(5));
//    EXPECT_EQ (arr2->Get(1), arr3->Get(6));
//    EXPECT_EQ (arr2->Get(2), arr3->Get(7));
//    EXPECT_EQ (arr2->Get(3), arr3->Get(8));
//    EXPECT_EQ (arr2->Get(4), arr3->Get(9));
//
//    unique_ptr<Sequence<int>> arr4 = unique_ptr<Sequence<int>>(new ArraySequence<int>());
//    arr3 = unique_ptr<Sequence<int>>(arr1->Concat(arr4));
//    ASSERT_EQ (arr1->Count() + arr4->Count(), arr3->Count());
//    EXPECT_EQ (arr1->Get(0), arr3->Get(0));
//    EXPECT_EQ (arr1->Get(1), arr3->Get(1));
//    EXPECT_EQ (arr1->Get(2), arr3->Get(2));
//    EXPECT_EQ (arr1->Get(3), arr3->Get(3));
//    EXPECT_EQ (arr1->Get(4), arr3->Get(4));
//}
//
//TEST(Sequence, ArraySequence_Subsequence) {
//    int a[] = {1, 2, 3, 4, 5};
//    unique_ptr<Sequence<int>> arr1 = unique_ptr<Sequence<int>>(
//            dynamic_cast<Sequence<int> *>(new ArraySequence<int>(a, 5)));
//    unique_ptr<Sequence<int>>
//            arr2 = unique_ptr<Sequence<int>>(dynamic_cast<Sequence<int> *>(arr1->Subsequence(0, 0)));
//    ASSERT_EQ(arr2->Count(), 1);
//    EXPECT_EQ (arr1->Get(0), 1);
//    EXPECT_ANY_THROW(arr2->Get(1));
//    EXPECT_ANY_THROW(arr1->Subsequence(-1, 0));
//    EXPECT_ANY_THROW(arr1->Subsequence(1, 0));
//    EXPECT_ANY_THROW(arr1->Subsequence(1, 5));
//    arr2 = unique_ptr<Sequence<int>>(dynamic_cast<Sequence<int> *>(arr1->Subsequence(0, 4)));
//    ASSERT_EQ(arr2->Count(), 5);
//    EXPECT_EQ (arr1->Get(0), arr2->Get(0));
//    EXPECT_EQ (arr1->Get(1), arr2->Get(1));
//    EXPECT_EQ (arr1->Get(2), arr2->Get(2));
//    EXPECT_EQ (arr1->Get(3), arr2->Get(3));
//    EXPECT_EQ (arr1->Get(4), arr2->Get(4));
//    arr2 = unique_ptr<Sequence<int>>(dynamic_cast<Sequence<int> *>(arr1->Subsequence(2, 3)));
//    ASSERT_EQ(arr2->Count(), 2);
//}
//
//

#endif //TEST_DB_SEQUENCETESTS_H