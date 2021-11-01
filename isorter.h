#ifndef ISORTER_H
#define ISORTER_H

#pragma once

#include "sequence.h"

template <class T>
class ISorter {
public:
    virtual void Sort(Sequence<T>* seq, int (*cmp)(T, T)) = 0;
};

template <typename T>
class ShakerSort : public ISorter<T> {
public:
    void Sort(Sequence<T>* seq, int (*cmp)(T, T));
};

template <typename T>
class HeapSort : public ISorter<T> {
public:
    void siftDown(Sequence<T>* seq, int root, int bottom, int (*cmp)(T, T));
    void Sort(Sequence<T>* seq, int (*cmp)(T, T));
};

template <typename T>
class QuickSort : public ISorter<T> {
public:
    void Sort_first(Sequence<T>* seq, int left, int right, int (*cmp)(T, T));
    void Sort(Sequence<T>* seq, int (*cmp)(T, T));
};

template <typename T>
class ShellSort : public ISorter<T> {
public:
    void Sort(Sequence<T>* seq, int (*cmp)(T, T));
};



#endif // ISORTER_H
