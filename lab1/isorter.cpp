#pragma once

#include <iostream>
#include "isorter.h"
#include "sequence.h"
#include "arraysequence.h"
#include "arraysequence.cpp"

template<class T>
void ShakerSort<T>::Sort(Sequence<T>* seq, int (*cmp)(T, T))  {
    int left = 0, right = seq->GetLength() - 1;
    int flag = 1;
    while ((left < right) && flag > 0) {
        flag = 0;
        for (int i = left; i < right; ++i) {
            if (cmp(seq->Get(i), seq->Get(i + 1)) == 1) {
                T tmp = seq->Get(i);
                seq->Set(i, seq->Get(i + 1));
                seq->Set(i + 1, tmp);
                flag = 1;
            }
        }
        --right;
        for(int i = right; i > left; --i) {
            if (cmp(seq->Get(i - 1), seq->Get(i)) == 1) {
                T tmp = seq->Get(i);
                seq->Set(i, seq->Get(i - 1));
                seq->Set(i - 1, tmp);
                flag = 1;
            }
        }
        ++left;
    }
}

template<class T>
void QuickSort<T>::Sort_first(Sequence<T>* seq, int left, int right, int (*cmp)(T, T))  {
    T pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = seq->Get(left);
    while (left < right) {
        while ((cmp(seq->Get(right), pivot) >= 0) && (left < right)) --right;
        if (left != right) {
            seq->Set(left, seq->Get(right));
            ++left;
        }
        while ((cmp(pivot, seq->Get(left)) >= 0) && (left < right)) ++left;
        if (left != right) {
            seq->Set(right, seq->Get(left));
            --right;
        }
    }
    seq->Set(left, pivot);
    int point = left;
    left = l_hold;
    right = r_hold;
    if (left < point) Sort_first(seq, left, point - 1, cmp);
    if (right > point) Sort_first(seq, point + 1, right, cmp);
}

template<class T>
void QuickSort<T>::Sort(Sequence<T>* seq, int (*cmp)(T, T))  {
    Sort_first(seq, 0, seq->GetLength() - 1, cmp);
}

template<class T>
void HeapSort<T>::siftDown(Sequence<T>* seq, int root, int bottom, int (*cmp)(T, T))  {
    int maxChild;
    int done = 0;
    while ((2 * root <= bottom) && (!done)) {
        if (2 * root == bottom) maxChild = 2 * root;
        else if (cmp(seq->Get(2 * root), seq->Get(2 * root + 1)) == 1) maxChild = 2 * root;
        else maxChild = 2 * root + 1;
        if (cmp(seq->Get(maxChild), seq->Get(root)) == 1) {
            T tmp = seq->Get(root);
            seq->Set(root, seq->Get(maxChild));
            seq->Set(maxChild, tmp);
            root = maxChild;
        }
        else done = 1;
    }
}

template<class T>
void HeapSort<T>::Sort(Sequence<T>* seq, int (*cmp)(T, T))  {
    for (int i = seq->GetLength() / 2; i >= 0; --i)
        siftDown(seq, i, seq->GetLength() - 1, cmp);
    for (int i = seq->GetLength() - 1; i >= 1; --i) {
        T tmp = seq->Get(0);
        seq->Set(0, seq->Get(i));
        seq->Set(i, tmp);
        siftDown(seq, 0, i - 1, cmp);
    }
}

template<class T>
void ShellSort<T>::Sort(Sequence<T>* seq, int (*cmp)(T, T))  {
    int step = seq->GetLength() / 2;
    while (step > 0) {
        for (int i = 0; i < seq->GetLength(); ++i) {
            int j = i;
            T tmp = seq->Get(i);
            while ((j >= step) && cmp(seq->Get(j - step), tmp) == 1) {
                seq->Set(j, seq->Get(j - step));
                j = j - step;
            }
            seq->Set(j, tmp);
        }
        if (step > 1) step /= 2;
        else if (step == 1) break;
    }
}
