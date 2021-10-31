#ifndef EXTRA_H
#define EXTRA_H

#pragma once

#include <iostream>
#include <string>
#include "listsequence.h"
#include "arraysequence.h"
#include "isorter.h"
#include <cmath>
#include <ctime>
#include <chrono>
using namespace std;

int cmp(int a, int b) {
    if (a > b) return 1;
    if (a == b) return 0;
    else return -1;
}

void enterInt(int *a) {
    int mode = 0;
    cin >> *a;
    if (!cin) {
        while (getchar() != '\n') {};
        cout << "Something's wrong. Try again.\n\n";
        mode = -1;
    }
    if (mode == 0) while (getchar() != '\n') {};
}

void dialog (string vars[], int vars_size, string request, int* choice) {
    cout << request;
    for(int i = 1; i < vars_size; ++i) cout << i << ". " << vars[i] << endl;

    int error;

    do {
        enterInt(choice);

        if (*choice < vars_size && *choice > 0) {
            cout << "Choice: " << vars[*choice] << endl << endl;
            error = 0;
        }
        else {
            cout << "Something's wrong. Try again." << endl << endl;
            error = 1;
        }
    } while (error);
}

void enterLength(int* length) {
    int error;

    do {
        enterInt(length);

        if (*length > 0) {
            cout << "Length = " << *length << endl << endl;
            error = 0;
        }
        else {
            cout << "Something's wrong. Try again." << endl << endl;
            error = 1;
        }
    } while (error);
}

/*void enterIndex(int* index) {
    int error;

    do {
        enterInt(index);

        if (*index >= 0) {
            cout << "Index = " << *index << endl << endl;
            error = 0;
        }
        else {
            cout << "Something's wrong. Try again." << endl << endl;
            error = 1;
        }
    } while (error);
}*/

template <class T>
void generate_sorted_forward(Sequence<T>* seq, int* length) {
    srand(time(NULL));
    int a = 0;
    for (int i = 0; i < *length; ++i) {
        a += rand() % 6;
        seq->Append(a);
    }
}

template <class T>
void generate_sorted_backwards(Sequence<T>* seq, int* length) {
    srand(time(NULL));
    int a = 5 * *length;
    for (int i = 0; i < *length; ++i) {
        a -= rand() % 6;
        seq->Append(a);
    }
}

template <class T>
void generate_not_sorted(Sequence<T>* seq, int* length) {
    srand(time(NULL));
    for (int i = 0; i < *length; ++i) {
        int a = rand() % (20 * *length);
        seq->Append(a);
    }
}

template <class T>
void fill(Sequence<T>* seq, int* length) {
    for (int i = 0; i < *length; ++i) {
        int a;
        enterInt(&a);
        seq->Append(a);
    }
}

template <class T>
void out(Sequence<T>* seq) {
    for (int i = 0; i < seq->GetLength(); ++i) {
        cout << (*seq)[i];
        if (i == seq->GetLength() - 1)
            break;
        cout << ", ";
    }
    cout << endl << endl;
}

template <class T>
int isSorted(Sequence<T>* seq, int (*cmp)(T, T)) {
    int check = 0;
    for (int i = 0; i < seq->GetLength() - 1; ++i) {
        if (cmp((*seq)[i + 1], (*seq)[i]) >= 0) ++check;
    }
    return check;
}

void testArraySeq_ShakerSort_sorted_forward() {
    for (int  i = 0; i <= 20000; i += 1000) {
        Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
        generate_sorted_forward(seq, &i);
        ShakerSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "ARRAY Shaker sort (sorted forward) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testArraySeq_ShakerSort_sorted_backwards() {
    for (int  i = 0; i <= 20000; i += 1000) {
        Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
        generate_sorted_backwards(seq, &i);
        ShakerSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "ARRAY Shaker sort (sorted backwards) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testArraySeq_ShakerSort_not_sorted() {
    for (int  i = 0; i <= 20000; i += 1000) {
        Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
        generate_not_sorted(seq, &i);
        ShakerSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "ARRAY Shaker sort (not sorted) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testArraySeq_HeapSort_sorted_forward() {
    for (int  i = 1000; i <= 20000; i += 1000) {
        Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
        generate_sorted_forward(seq, &i);
        HeapSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "ARRAY Heap sort (sorted forward) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testArraySeq_HeapSort_sorted_backwards() {
    for (int  i = 1000; i <= 20000; i += 1000) {
        Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
        generate_sorted_backwards(seq, &i);
        HeapSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "ARRAY Heap sort (sorted backwards) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testArraySeq_HeapSort_not_sorted() {
    for (int  i = 1000; i <= 20000; i += 1000) {
        Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
        generate_not_sorted(seq, &i);
        HeapSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "ARRAY Heap sort (not sorted) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testArraySeq_QuickSort_sorted_forward() {
    for (int  i = 1000; i <= 20000; i += 1000) {
        Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
        generate_sorted_forward(seq, &i);
        QuickSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "ARRAY Quick sort (sorted forward) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testArraySeq_QuickSort_sorted_backwards() {
    for (int  i = 1000; i <= 20000; i += 1000) {
        Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
        generate_sorted_backwards(seq, &i);
        QuickSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "ARRAY Quick sort (sorted backwards) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testArraySeq_QuickSort_not_sorted() {
    for (int  i = 1000; i <= 20000; i += 1000) {
        Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
        generate_not_sorted(seq, &i);
        QuickSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "ARRAY Quick sort (not sorted) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testArraySeq_ShellSort_sorted_forward() {
    for (int  i = 1000; i <= 20000; i += 1000) {
        Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
        generate_sorted_forward(seq, &i);
        ShellSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "ARRAY Shell sort (sorted forward) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testArraySeq_ShellSort_sorted_backwards() {
    for (int  i = 1000; i <= 20000; i += 1000) {
        Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
        generate_sorted_backwards(seq, &i);
        ShellSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "ARRAY Shell sort (sorted backwards) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testArraySeq_ShellSort_not_sorted() {
    for (int  i = 1000; i <= 20000; i += 1000) {
        Sequence<int>* seq = (Sequence<int>*) new ArraySequence<int>;
        generate_not_sorted(seq, &i);
        ShellSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "ARRAY Shell sort (not sorted) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testListSeq_ShakerSort_sorted_forward() {
    for (int  i = 0; i <= 2000; i += 100) {
        Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
        generate_sorted_forward(seq, &i);
        ShakerSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "LIST Shaker sort (sorted forward) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testListSeq_ShakerSort_sorted_backwards() {
    for (int  i = 0; i <= 2000; i += 100) {
        Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
        generate_sorted_backwards(seq, &i);
        ShakerSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "LIST Shaker sort (sorted backwards) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testListSeq_ShakerSort_not_sorted() {
    for (int  i = 1; i <= 2000; i += 100) {
        Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
        generate_not_sorted(seq, &i);
        ShakerSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "LIST Shaker sort (not sorted) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testListSeq_HeapSort_sorted_forward() {
    for (int  i = 100; i <= 2000; i += 100) {
        Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
        generate_sorted_forward(seq, &i);
        HeapSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "LIST Heap sort (sorted forward) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testListSeq_HeapSort_sorted_backwards() {
    for (int  i = 100; i <= 2000; i += 100) {
        Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
        generate_sorted_backwards(seq, &i);
        HeapSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "LIST Heap sort (sorted backwards) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testListSeq_HeapSort_not_sorted() {
    for (int  i = 100; i <= 2000; i += 100) {
        Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
        generate_not_sorted(seq, &i);
        HeapSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "LIST Heap sort (not sorted) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testListSeq_QuickSort_sorted_forward() {
    for (int  i = 100; i <= 2000; i += 100) {
        Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
        generate_sorted_forward(seq, &i);
        QuickSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "LIST Quick sort (sorted forward) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testListSeq_QuickSort_sorted_backwards() {
    for (int  i = 100; i <= 2000; i += 100) {
        Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
        generate_sorted_backwards(seq, &i);
        QuickSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "LIST Quick sort (sorted backwards) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testListSeq_QuickSort_not_sorted() {
    for (int  i = 100; i <= 2000; i += 100) {
        Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
        generate_not_sorted(seq, &i);
        QuickSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "LIST Quick sort (not sorted) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testListSeq_ShellSort_sorted_forward() {
    for (int  i = 100; i <= 2000; i += 100) {
        Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
        generate_sorted_forward(seq, &i);
        ShellSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "LIST Shell sort (sorted forward) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testListSeq_ShellSort_sorted_backwards() {
    for (int  i = 100; i <= 2000; i += 100) {
        Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
        generate_sorted_backwards(seq, &i);
        ShellSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "LIST Shell sort (sorted backwards) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

void testListSeq_ShellSort_not_sorted() {
    for (int  i = 100; i <= 2000; i += 100) {
        Sequence<int>* seq = (Sequence<int>*) new ListSequence<int>;
        generate_not_sorted(seq, &i);
        ShellSort<int> Sorter;
        auto t_1 = std::chrono::high_resolution_clock::now();
        Sorter.Sort(seq, cmp);
        auto t_2 = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
        cout << "LIST Shell sort (not sorted) " << i << " elements: " << time << " microseconds" << endl;
    }
    cout << endl;
}

#endif // EXTRA_H
