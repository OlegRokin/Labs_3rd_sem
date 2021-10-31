#include <iostream>
#include "sequence.h"
#include "listsequence.h"
#include "listsequence.cpp"
#include "arraysequence.h"
#include "arraysequence.cpp"
#include "isorter.h"
#include "isorter.cpp"
#include "extra.h"
#include <string>
#include <chrono>
#include <gtest/gtest.h>

TEST (ArraySeq_ShakerSort, sorted_forward) {
    int length = 10000;
    Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
    generate_sorted_forward(seq, &length);
    ShakerSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 9999);
}

TEST (ArraySeq_ShakerSort, sorted_backwards) {
    int length = 10000;
    Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
    generate_sorted_backwards(seq, &length);
    ShakerSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 9999);
}

TEST (ArraySeq_ShakerSort, not_sorted) {
    int length = 10000;
    Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
    generate_not_sorted(seq, &length);
    ShakerSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 9999);
}

TEST (ListSeq_ShakerSort, sorted_forward) {
    int length = 1000;
    Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
    generate_sorted_forward(seq, &length);
    ShakerSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 999);
}

TEST (ListSeq_ShakerSort, sorted_backwards) {
    int length = 1000;
    Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
    generate_sorted_backwards(seq, &length);
    ShakerSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 999);
}

TEST (ListSeq_ShakerSort, not_sorted) {
    int length = 1000;
    Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
    generate_not_sorted(seq, &length);
    ShakerSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 999);
}

TEST (ArraySeq_HeapSort, sorted_forward) {
    int length = 10000;
    Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
    generate_sorted_forward(seq, &length);
    HeapSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 9999);
}

TEST (ArraySeq_HeapSort, sorted_backwards) {
    int length = 10000;
    Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
    generate_sorted_backwards(seq, &length);
    HeapSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 9999);
}

TEST (ArraySeq_HeapSort, not_sorted) {
    int length = 10000;
    Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
    generate_not_sorted(seq, &length);
    HeapSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 9999);
}

TEST (ListSeq_HeapSort, sorted_forward) {
    int length = 1000;
    Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
    generate_sorted_forward(seq, &length);
    HeapSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 999);
}

TEST (ListSeq_HeapSort, sorted_backwards) {
    int length = 1000;
    Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
    generate_sorted_backwards(seq, &length);
    HeapSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 999);
}

TEST (ListSeq_HeapSort, not_sorted) {
    int length = 1000;
    Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
    generate_not_sorted(seq, &length);
    HeapSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 999);
}

TEST (ArraySeq_QuickSort, sorted_forward) {
    int length = 10000;
    Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
    generate_sorted_forward(seq, &length);
    QuickSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 9999);
}

TEST (ArraySeq_QuickSort, sorted_backwards) {
    int length = 10000;
    Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
    generate_sorted_backwards(seq, &length);
    QuickSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 9999);
}

TEST (ArraySeq_QuickSort, not_sorted) {
    int length = 10000;
    Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
    generate_not_sorted(seq, &length);
    QuickSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 9999);
}

TEST (ListSeq_QuickSort, sorted_forward) {
    int length = 1000;
    Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
    generate_sorted_forward(seq, &length);
    QuickSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 999);
}

TEST (ListSeq_QuickSort, sorted_backwards) {
    int length = 1000;
    Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
    generate_sorted_backwards(seq, &length);
    QuickSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 999);
}

TEST (ListSeq_QuickSort, not_sorted) {
    int length = 1000;
    Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
    generate_not_sorted(seq, &length);
    QuickSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 999);
}

TEST (ArraySeq_ShellSort, sorted_forward) {
    int length = 10000;
    Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
    generate_sorted_forward(seq, &length);
    ShellSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 9999);
}

TEST (ArraySeq_ShellSort, sorted_backwards) {
    int length = 10000;
    Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
    generate_sorted_backwards(seq, &length);
    ShellSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 9999);
}

TEST (ArraySeq_ShellSort, not_sorted) {
    int length = 10000;
    Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
    generate_not_sorted(seq, &length);
    ShellSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 9999);
}

TEST (ListSeq_ShellSort, sorted_forward) {
    int length = 1000;
    Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
    generate_sorted_forward(seq, &length);
    ShellSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 999);
}

TEST (ListSeq_ShellSort, sorted_backwards) {
    int length = 1000;
    Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
    generate_sorted_backwards(seq, &length);
    ShellSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 999);
}

TEST (ListSeq_ShellSort, not_sorted) {
    int length = 1000;
    Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
    generate_not_sorted(seq, &length);
    ShellSort<int> Sorter;
    Sorter.Sort(seq, cmp);
    ASSERT_TRUE(isSorted(seq, cmp) == 999);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
