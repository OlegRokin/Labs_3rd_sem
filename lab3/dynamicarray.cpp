#include <iostream>
#include "dynamicarray.h"

template<typename T>
DynamicArray<T>::DynamicArray() {
    _data = nullptr;
    _length = 0;
}

template<typename T>
DynamicArray<T>::DynamicArray(T *data, int index)
{
    _length = index;
    if (index)
        _data = new T[index];
    else _data = nullptr;
    for (int i = 0; i < _length; i++)
        _data[i] = data[i];
}

template<typename T>
DynamicArray<T>::DynamicArray (int length)
{
    _length = length;
    if (length != 0)
        _data = new T[length];
    else
        _data = nullptr;
}

template<typename T>
DynamicArray<T>::DynamicArray (const DynamicArray<T> &array)
{
    _data = nullptr;
    _length = array._length;
    if (_length != 0)
        _data = new T[_length];
    else
        _data = nullptr;
    for (int i = 0; i < _length; i++)
        _data[i] = array._data[i];
}

template<typename T>
T &DynamicArray<T>::Get(int index)
{
    if (index < 0 || index >= _length)
        throw std::out_of_range ("10");
    return _data[index];
}

template<class T>
T &DynamicArray<T>::operator[](const int index) {
    if (index < 0 || index >= this->GetLength())
        throw std::out_of_range("4");
    return this->Get(index);
}

template<class T>
void DynamicArray<T>::DelByIndex(int index)
{
    if (index >= _length || index < 0)
        throw std::out_of_range ("11");
    for (int i = 0; i < _length - 1; ++i) {
        if (i < index) continue;
        else _data[i] = _data[i + 1];
    }
    this->Resize(_length - 1);
}

template<class T>
void DynamicArray<T>::Clear() {
    for (int i = 0; i < _length; ++i) {
        delete _data[i];
    }
    this->Resize(0);
}

template<typename T>
int DynamicArray<T>::GetLength() const {
    return _length;
}

template<typename T>
void DynamicArray<T>::Set(int index, T value)
{
    if (index < 0 || index >= _length)
        throw std::out_of_range ("set");
    _data[index] = value;
}

template<typename T>
void DynamicArray<T>::Resize(int length)
{
    if (length < 0)
        throw std::out_of_range ("resize");
    if (!length) {
        delete[] _data;
        _data = nullptr;
        _length = 0;
        return;
    }
    T *array = new T [length];
    for (int i = 0; i < std::min(length, _length); ++i) {
        array[i] = this->Get(i);
    }
    delete[] _data;
    _data = array;
    _length = length;
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
    _length = 0;
    delete[] _data;
}
