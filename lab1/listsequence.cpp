#pragma once

#include "listsequence.h"
using namespace std;

template<typename T>
ListSequence<T>::ListSequence(): _list(new LinkedList <T>()) {}

template<typename T>
ListSequence<T>::ListSequence(T *data, int count)
{
    _list = new LinkedList<T>(data, count);
}

template<typename T>
ListSequence<T>::ListSequence(const ListSequence<T> &list)
{
    _list = new LinkedList<T>(list);
}

template<typename T>
T &ListSequence<T>::GetFirst(){
    if (!_list->GetLength())
        throw std::out_of_range ("");
    return _list->front();
}

template<typename T>
T &ListSequence<T>::GetLast(){
    if (!_list->GetLength())
        throw std::out_of_range ("");
    return _list->back();
}

template<typename T>
T &ListSequence<T>::Get(int index)
{
    if (index >= _list->GetLength() || index < 0)
        throw std::out_of_range ("");
    return _list->Get(index);

}

template<class T>
T &ListSequence<T>::operator[](const int index) {
    if (index >= _list->GetLength() || index < 0)
        throw std::out_of_range ("");
    return this->Get(index);
}

template<typename T>
Sequence<T> *ListSequence<T>::GetSubSequence(int start_index, int end_index) const
{
    if (start_index < 0 || start_index >= _list->GetLength() || end_index < 0 || end_index > _list->GetLength())
        throw std::out_of_range ("");
    return (Sequence<T> *) _list->GetSubList(start_index, end_index);
}

template<typename T>
int ListSequence<T>::GetLength() const {
    return _list->GetLength();
}

template<class T>
void ListSequence<T>::DelByIndex(int index) {
    if (index < 0 || index >= this->GetLength())
        throw std::out_of_range ("");
    _list->delete_by_index(index);
}

template<typename T>
void ListSequence<T>::Append(const T &value){
    _list->push_back(value);
}

template<typename T>
void ListSequence<T>::Prepend(const T &value) {
    _list->push_front(value);
}

template<typename T>
void ListSequence<T>::InsertAt(const T &value, int index) {
    if (index < 0 || index > _list->GetLength())
        throw std::out_of_range ("");
    _list->InsertAt(value, index);
}

template<class T>
void ListSequence<T>::Set(int index, const T& item) {
    if (index < 0 || index > _list->GetLength())
        throw std::out_of_range ("");
    _list->Set(index, item);
}

template<typename T>
Sequence<T> *ListSequence<T>::Concat(Sequence<T> *seq) const
{
    if (seq == nullptr)
        throw std::out_of_range ("");
    ListSequence<T> *seq_list = new ListSequence<T>();
    for (int i = 0; i < seq->GetLength(); ++i) {
        seq_list->Append(seq->Get(i));
    }
    return (Sequence<T> *) _list->Concat(seq_list->_list);
}

template<class T>
void ListSequence<T>::ShakerSort() {
    if (!this->GetLength())
        throw std::out_of_range ("");
    int left = 0, right = this->GetLength() - 1;
    int flag = 1;
    while ((left < right) && flag > 0) {
        flag = 0;
        for (int i = left; i < right; ++i) {
            if (this->Get(i) > this->Get(i + 1)) {
                T tmp = this->Get(i);
                this->Set(i, this->Get(i + 1));
                this->Set(i + 1, tmp);
                flag = 1;
            }
        }
        right--;
        for(int i = right; i > left; --i) {
            if (this->Get(i - 1) > this->Get(i)) {
                T tmp = this->Get(i);
                this->Set(i, this->Get(i - 1));
                this->Set(i - 1, tmp);
                flag = 1;
            }
        }
        left++;
    }
}

template<class T>
void ListSequence<T>::ShellSort() {
    int step = this->GetLength() / 2;
    while (step > 0) {
        for (int i = 0; i < this->GetLength(); ++i) {
            int j = i;
            int tmp = this->Get(i);
            while ((j >= step) && (this->Get(j - step) > tmp)) {
                this->Set(j, this->Get(j - step));
                j = j - step;
            }
            this->Set(j, tmp);
        }
        if (step > 1) step /= 2;
        else if (step == 1) break;
    }
}

template<class T>
std::ostream& operator << (std::ostream &out, const ListSequence<T> &seq) {
    for (int i = 0; i < seq.GetLength(); ++i) {
        out << (*seq._list)[i];
        if (i == seq.GetLength() - 1)
            break;
        out << ", ";
    }
    return out;
}

template<typename T>
ListSequence<T>::~ListSequence()
{
    _list->~LinkedList<T>();
    delete _list;
}

