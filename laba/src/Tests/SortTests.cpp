//
// Created by kmv026 on 10.10.2021.
//

//
// Created by lokt0 on 13.09.2021.
//
#include "gtest/gtest.h"
#include "../ListSequence.hpp"
#include "../ArraySequence.hpp"

TEST(BubbleSort, IntegerArray){
    auto arr = new ArraySequence<int>({5, 2, 3, 6, 1, 4});
    arr = (ArraySequence<int>*)SequenceSorter<int>::BubbleSort(arr, [](int a, int b){ return a > b; });
    EXPECT_EQ (1, arr->Get(0));
    EXPECT_EQ (2, arr->Get(1));
    EXPECT_EQ (3, arr->Get(2));
    EXPECT_EQ (4, arr->Get(3));
    EXPECT_EQ (5, arr->Get(4));
    EXPECT_EQ (6, arr->Get(5));
}
TEST(BubbleSort, FloatArray){
    auto arr = new ArraySequence<float>({0.5f, 0.2f, 0.3f, 0.6f, 0.1f, 0.4f});
    arr = (ArraySequence<float>*)SequenceSorter<float>::BubbleSort(arr, [](float a, float b){ return a > b; });
    EXPECT_EQ (0.1f, arr->Get(0));
    EXPECT_EQ (0.2f, arr->Get(1));
    EXPECT_EQ (0.3f, arr->Get(2));
    EXPECT_EQ (0.4f, arr->Get(3));
    EXPECT_EQ (0.5f, arr->Get(4));
    EXPECT_EQ (0.6f, arr->Get(5));
}
TEST(BubbleSort, StringArray){
    auto arr = new ArraySequence<string>({"a", "g", "cow", "human", "Sergei", "programming"});
    arr = (ArraySequence<string>*)SequenceSorter<string>::BubbleSort(arr,[](const string& a, const string& b){
        //return a.size() > b.size();
        return a.compare(b);
    });
    EXPECT_EQ ("programming", arr->Get(0));
    EXPECT_EQ ("Sergei", arr->Get(1));
    EXPECT_EQ ("human", arr->Get(2));
    EXPECT_EQ ("cow", arr->Get(3));
    EXPECT_EQ ("g", arr->Get(4));
    EXPECT_EQ ("a", arr->Get(5));
}
TEST(BubbleSort, IntegerList){
    auto arr = new ListSequence<int>({5, 2, 3, 6, 1, 4});
    arr = (ListSequence<int>*)SequenceSorter<int>::BubbleSort(arr, [](int a, int b){ return a > b; });
    EXPECT_EQ (1, arr->Get(0));
    EXPECT_EQ (2, arr->Get(1));
    EXPECT_EQ (3, arr->Get(2));
    EXPECT_EQ (4, arr->Get(3));
    EXPECT_EQ (5, arr->Get(4));
    EXPECT_EQ (6, arr->Get(5));
}
TEST(BubbleSort, FloatList){
    auto arr = new ListSequence<float>({0.5f, 0.2f, 0.3f, 0.6f, 0.1f, 0.4f});
    arr = (ListSequence<float>*)SequenceSorter<float>::BubbleSort(arr, [](float a, float b){ return a > b; });
    EXPECT_EQ (0.1f, arr->Get(0));
    EXPECT_EQ (0.2f, arr->Get(1));
    EXPECT_EQ (0.3f, arr->Get(2));
    EXPECT_EQ (0.4f, arr->Get(3));
    EXPECT_EQ (0.5f, arr->Get(4));
    EXPECT_EQ (0.6f, arr->Get(5));
}
TEST(BubbleSort, StringList){
    auto arr = new ListSequence<string>({"a", "g", "cow", "human", "Sergei", "programming"});
    arr = (ListSequence<string>*)SequenceSorter<string>::BubbleSort(arr,[](const string& a, const string& b){
        //return a.size() > b.size();
        return a.compare(b);
    });
    EXPECT_EQ ("programming", arr->Get(0));
    EXPECT_EQ ("Sergei", arr->Get(1));
    EXPECT_EQ ("human", arr->Get(2));
    EXPECT_EQ ("cow", arr->Get(3));
    EXPECT_EQ ("g", arr->Get(4));
    EXPECT_EQ ("a", arr->Get(5));
}

TEST(InsertionSort, IntegerArray){
    auto arr = new ArraySequence<int>({5, 2, 3, 6, 1, 4});
    arr = (ArraySequence<int>*)SequenceSorter<int>::InsertionSort(arr, [](int a, int b){ return a > b; });
    EXPECT_EQ (1, arr->Get(0));
    EXPECT_EQ (2, arr->Get(1));
    EXPECT_EQ (3, arr->Get(2));
    EXPECT_EQ (4, arr->Get(3));
    EXPECT_EQ (5, arr->Get(4));
    EXPECT_EQ (6, arr->Get(5));
}
TEST(InsertionSort, FloatArray){
    auto arr = new ArraySequence<float>({0.5f, 0.2f, 0.3f, 0.6f, 0.1f, 0.4f});
    arr = (ArraySequence<float>*)SequenceSorter<float>::InsertionSort(arr, [](float a, float b){ return a > b; });
    EXPECT_EQ (0.1f, arr->Get(0));
    EXPECT_EQ (0.2f, arr->Get(1));
    EXPECT_EQ (0.3f, arr->Get(2));
    EXPECT_EQ (0.4f, arr->Get(3));
    EXPECT_EQ (0.5f, arr->Get(4));
    EXPECT_EQ (0.6f, arr->Get(5));
}
TEST(InsertionSort, StringArray){
    auto arr = new ArraySequence<string>({"a", "g", "cow", "human", "Sergei", "programming"});
    arr = (ArraySequence<string>*)SequenceSorter<string>::InsertionSort(arr,[](const string& a, const string& b){
        //return a.size() > b.size();
        return a.compare(b);
    });
    EXPECT_EQ ("programming", arr->Get(0));
    EXPECT_EQ ("Sergei", arr->Get(1));
    EXPECT_EQ ("human", arr->Get(2));
    EXPECT_EQ ("cow", arr->Get(3));
    EXPECT_EQ ("g", arr->Get(4));
    EXPECT_EQ ("a", arr->Get(5));
}
TEST(InsertionSort, IntegerList){
    auto arr = new ListSequence<int>({5, 2, 3, 6, 1, 4});
    arr = (ListSequence<int>*)SequenceSorter<int>::InsertionSort(arr, [](int a, int b){ return a > b; });
    EXPECT_EQ (1, arr->Get(0));
    EXPECT_EQ (2, arr->Get(1));
    EXPECT_EQ (3, arr->Get(2));
    EXPECT_EQ (4, arr->Get(3));
    EXPECT_EQ (5, arr->Get(4));
    EXPECT_EQ (6, arr->Get(5));
}
TEST(InsertionSort, FloatList){
    auto arr = new ListSequence<float>({0.5f, 0.2f, 0.3f, 0.6f, 0.1f, 0.4f});
    arr = (ListSequence<float>*)SequenceSorter<float>::InsertionSort(arr, [](float a, float b){ return a > b; });
    EXPECT_EQ (0.1f, arr->Get(0));
    EXPECT_EQ (0.2f, arr->Get(1));
    EXPECT_EQ (0.3f, arr->Get(2));
    EXPECT_EQ (0.4f, arr->Get(3));
    EXPECT_EQ (0.5f, arr->Get(4));
    EXPECT_EQ (0.6f, arr->Get(5));
}
TEST(InsertionSort, StringList){
    auto arr = new ListSequence<string>({"a", "g", "cow", "human", "Sergei", "programming"});
    arr = (ListSequence<string>*)SequenceSorter<string>::InsertionSort(arr,[](const string& a, const string& b){
        //return a.size() > b.size();
        return a.compare(b);
    });
    EXPECT_EQ ("programming", arr->Get(0));
    EXPECT_EQ ("Sergei", arr->Get(1));
    EXPECT_EQ ("human", arr->Get(2));
    EXPECT_EQ ("cow", arr->Get(3));
    EXPECT_EQ ("g", arr->Get(4));
    EXPECT_EQ ("a", arr->Get(5));
}

//TEST(HeapSort, IntegerArray){
//    auto arr = new ArraySequence<int>({5, 2, 3, 6, 1, 4});
//    arr = (ArraySequence<int>*)SequenceSorter<int>::HeapSort(arr, [](int a, int b){ return a > b; });
//    EXPECT_EQ (1, arr->Get(0));
//    EXPECT_EQ (2, arr->Get(1));
//    EXPECT_EQ (3, arr->Get(2));
//    EXPECT_EQ (4, arr->Get(3));
//    EXPECT_EQ (5, arr->Get(4));
//    EXPECT_EQ (6, arr->Get(5));
//}
//TEST(HeapSort, FloatArray){
//    auto arr = new ArraySequence<float>({0.5f, 0.2f, 0.3f, 0.6f, 0.1f, 0.4f});
//    arr = (ArraySequence<float>*)SequenceSorter<float>::HeapSort(arr, [](float a, float b){ return a > b; });
//    EXPECT_EQ (0.1f, arr->Get(0));
//    EXPECT_EQ (0.2f, arr->Get(1));
//    EXPECT_EQ (0.3f, arr->Get(2));
//    EXPECT_EQ (0.4f, arr->Get(3));
//    EXPECT_EQ (0.5f, arr->Get(4));
//    EXPECT_EQ (0.6f, arr->Get(5));
//}
//TEST(HeapSort, StringArray){
//    auto arr = new ArraySequence<string>({"a", "g", "cow", "human", "Sergei", "programming"});
//    arr = (ArraySequence<string>*)SequenceSorter<string>::HeapSort(arr,[](const string& a, const string& b){
//        //return a.size() > b.size();
//        return a.compare(b);
//    });
//    EXPECT_EQ ("human", arr->Get(0));
//    EXPECT_EQ ("Sergei", arr->Get(1));
//    EXPECT_EQ ("g", arr->Get(2));
//    EXPECT_EQ ("cow", arr->Get(3));
//    EXPECT_EQ ("a", arr->Get(4));
//    EXPECT_EQ ("programming", arr->Get(5));
//}
//TEST(HeapSort, IntegerList){
//    auto arr = new ListSequence<int>({5, 2, 3, 6, 1, 4});
//    arr = (ListSequence<int>*)SequenceSorter<int>::HeapSort(arr, [](int a, int b){ return a > b; });
//    EXPECT_EQ (1, arr->Get(0));
//    EXPECT_EQ (2, arr->Get(1));
//    EXPECT_EQ (3, arr->Get(2));
//    EXPECT_EQ (4, arr->Get(3));
//    EXPECT_EQ (5, arr->Get(4));
//    EXPECT_EQ (6, arr->Get(5));
//}
//TEST(HeapSort, FloatList){
//    auto arr = new ListSequence<float>({0.5f, 0.2f, 0.3f, 0.6f, 0.1f, 0.4f});
//    arr = (ListSequence<float>*)SequenceSorter<float>::HeapSort(arr, [](float a, float b){ return a > b; });
//    EXPECT_EQ (0.1f, arr->Get(0));
//    EXPECT_EQ (0.2f, arr->Get(1));
//    EXPECT_EQ (0.3f, arr->Get(2));
//    EXPECT_EQ (0.4f, arr->Get(3));
//    EXPECT_EQ (0.5f, arr->Get(4));
//    EXPECT_EQ (0.6f, arr->Get(5));
//}
//TEST(HeapSort, StringList){
//    auto arr = new ListSequence<string>({"a", "g", "cow", "human", "Sergei", "programming"});
//    arr = (ListSequence<string>*)SequenceSorter<string>::HeapSort(arr,[](const string& a, const string& b){
//        //return a.size() > b.size();
//        return a.compare(b);
//    });
//    EXPECT_EQ ("human", arr->Get(0));
//    EXPECT_EQ ("Sergei", arr->Get(1));
//    EXPECT_EQ ("g", arr->Get(2));
//    EXPECT_EQ ("cow", arr->Get(3));
//    EXPECT_EQ ("a", arr->Get(4));
//    EXPECT_EQ ("programming", arr->Get(5));
//}

TEST(QuickSort, IntegerArray){
    auto arr = new ArraySequence<int>({5, 2, 3, 6, 1, 4});
    arr = (ArraySequence<int>*)SequenceSorter<int>::QuickSort(arr, [](int a, int b){ return a > b; });
    EXPECT_EQ (1, arr->Get(0));
    EXPECT_EQ (2, arr->Get(1));
    EXPECT_EQ (3, arr->Get(2));
    EXPECT_EQ (4, arr->Get(3));
    EXPECT_EQ (5, arr->Get(4));
    EXPECT_EQ (6, arr->Get(5));
}
TEST(QuickSort, FloatArray){
    auto arr = new ArraySequence<float>({0.5f, 0.2f, 0.3f, 0.6f, 0.1f, 0.4f});
    arr = (ArraySequence<float>*)SequenceSorter<float>::QuickSort(arr, [](float a, float b){ return a > b; });
    EXPECT_EQ (0.1f, arr->Get(0));
    EXPECT_EQ (0.2f, arr->Get(1));
    EXPECT_EQ (0.3f, arr->Get(2));
    EXPECT_EQ (0.4f, arr->Get(3));
    EXPECT_EQ (0.5f, arr->Get(4));
    EXPECT_EQ (0.6f, arr->Get(5));
}
TEST(QuickSort, StringArray){
    auto arr = new ArraySequence<string>({"Sergei", "cow", "g", "human", "a", "programming"});
    arr = (ArraySequence<string>*)SequenceSorter<string>::QuickSort(arr,[](const string& a, const string& b){
        //return a.size() > b.size();
        return b.size() < a.size();
    });
    EXPECT_EQ ("g", arr->Get(0));
    EXPECT_EQ ("a", arr->Get(1));
    EXPECT_EQ ("cow", arr->Get(2));
    EXPECT_EQ ("human", arr->Get(3));
    EXPECT_EQ ("Sergei", arr->Get(4));
    EXPECT_EQ ("programming", arr->Get(5));
}
TEST(QuickSort, IntegerList){
    auto arr = new ListSequence<int>({5, 2, 3, 6, 1, 4});
    arr = (ListSequence<int>*)SequenceSorter<int>::QuickSort(arr, [](int a, int b){ return a > b; });
    EXPECT_EQ (1, arr->Get(0));
    EXPECT_EQ (2, arr->Get(1));
    EXPECT_EQ (3, arr->Get(2));
    EXPECT_EQ (4, arr->Get(3));
    EXPECT_EQ (5, arr->Get(4));
    EXPECT_EQ (6, arr->Get(5));
}
TEST(QuickSort, FloatList){
    auto arr = new ListSequence<float>({0.5f, 0.2f, 0.3f, 0.6f, 0.1f, 0.4f});
    arr = (ListSequence<float>*)SequenceSorter<float>::QuickSort(arr, [](float a, float b){ return a > b; });
    EXPECT_EQ (0.1f, arr->Get(0));
    EXPECT_EQ (0.2f, arr->Get(1));
    EXPECT_EQ (0.3f, arr->Get(2));
    EXPECT_EQ (0.4f, arr->Get(3));
    EXPECT_EQ (0.5f, arr->Get(4));
    EXPECT_EQ (0.6f, arr->Get(5));
}
TEST(QuickSort, StringList){
    auto arr = new ListSequence<string>({"Sergei", "cow", "g", "human", "a", "programming"});
    arr = (ListSequence<string>*)SequenceSorter<string>::QuickSort(arr,[](const string& a, const string& b){
        //return a.size() > b.size();
        return a.size() > b.size();
    });
    EXPECT_EQ ("g", arr->Get(0));
    EXPECT_EQ ("a", arr->Get(1));
    EXPECT_EQ ("cow", arr->Get(2));
    EXPECT_EQ ("human", arr->Get(3));
    EXPECT_EQ ("Sergei", arr->Get(4));
    EXPECT_EQ ("programming", arr->Get(5));
}