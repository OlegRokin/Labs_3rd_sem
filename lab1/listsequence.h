#ifndef LISTSEQUENCE_H
#define LISTSEQUENCE_H

#pragma once

#include "sequence.h"
#include "linkedlist.h"
#include "linkedlist.cpp"
#include "iostream"

template <typename T>
class ListSequence: public Sequence<T>
{

private:
    LinkedList<T> *_list;

public:
    ListSequence();
    ListSequence(T* data, int count);
    ListSequence(const ListSequence<T>& list);

    T& GetFirst();
    T& GetLast();
    T& Get(int index);
    T& operator[] (const int index);
    Sequence<T>* GetSubSequence(int start_index, int end_index) const;
    int GetLength() const;
    void DelByIndex(int index);

    void Append(const T& value);
    void Prepend(const T& value);
    void InsertAt(const T& value, int index);
    void Set(int index, const T& item);
    Sequence<T>* Concat(Sequence <T> *seq) const;

    void ShakerSort();
    void ShellSort();

    template <class R>
    friend std::ostream& operator << (std::ostream &out, const ListSequence<R> &seq);

    ~ListSequence();
};

#endif // LISTSEQUENCE_H
