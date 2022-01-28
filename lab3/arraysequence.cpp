#include "arraysequence.h"
using namespace std;

template<typename T>
ArraySequence<T>::ArraySequence(): _array(new DynamicArray <T>()) {}

template<typename T>
ArraySequence<T>::ArraySequence(T* data, int count) {
    _array = new DynamicArray<T>(data, count);
}

template<typename T>
ArraySequence<T>::ArraySequence(int length) {
    _array = new DynamicArray<T>(length);
}

template<typename T>
ArraySequence<T>::ArraySequence(const ArraySequence<T> &array) {
    _array = new DynamicArray<T>(array.GetLength());
    for (int i = 0; i < _array->GetLength(); ++i) {
        _array->Set(i, array.Get(i));
    }
}

template<typename T>
T &ArraySequence<T>::GetFirst() {
    if (_array->GetLength() <= 0)
        throw std::out_of_range("1");
    return _array->Get(0);
}

template<typename T>
T &ArraySequence<T>::GetLast() {
    if (_array->GetLength() <= 0)
        throw std::out_of_range("2");
    return _array->Get(this->GetLength());
}

template<typename T>
T &ArraySequence<T>::Get(int index)
{
    if (index < 0 || index >= _array->GetLength())
        throw std::out_of_range("3");
    return _array->Get(index);
}

template<class T>
T &ArraySequence<T>::operator[](const int index) {
    if (index < 0 || index >= _array->GetLength())
        throw std::out_of_range("4");
    return this->Get(index);
}

template<typename T>
Sequence<T> *ArraySequence<T>::GetSubSequence(int start_index, int end_index) const
{
    if (start_index > end_index || start_index < 0 || end_index < 0 || start_index >= this->GetLength()
            || end_index > this->GetLength())
        throw std::out_of_range("5");
    Sequence<T> *array = (Sequence<T> *) new DynamicArray<T>(end_index - start_index);
    for (int i = start_index; i < end_index; ++i)
        array->Set(i - start_index, _array->Get(i));
    return array;
}

template<typename T>
int ArraySequence<T>::GetLength() const {
    return _array->GetLength();
}

template<class T>
void ArraySequence<T>::DelByIndex(int index) {
    if (index < 0 || index >= _array->GetLength())
        throw std::out_of_range("6");
    _array->DelByIndex(index);
}

template<class T>
ArraySequence<T> ArraySequence<T>::operator = (const ArraySequence& other) {
    ArraySequence<T> Copy;
    Copy._array = new DynamicArray<T> (other._array, other.GetLength());
    return Copy;
}

template<typename T>
void ArraySequence<T>::Append(const T &value){
    _array->Resize(this->GetLength() + 1);
    _array->Set(this->GetLength() - 1, value);
}

template<typename T>
void ArraySequence<T>::Prepend(const T &value) {
    _array->Resize(this->GetLength()+1);
    _array->Set(0, value);
}

template<typename T>
void ArraySequence<T>::InsertAt(const T &value, int index) {
    if (index > this->GetLength())
        throw std::out_of_range("7");
    _array->Resize(this->GetLength()+1);
    _array->Set(index, value);
    if (index == this->GetLength()) {
        this->Append(value);
        return;
    }
    _array->Resize(this->GetLength() + 1);
    for (int i = this->GetLength() - 1; i > index; --i)
        _array->Set(i, this->Get(i - 1));
    _array->Set(index, value);
}

template<class T>
void ArraySequence<T>::Set(int index, const T &value) {
    if (index >= this->GetLength())
        throw std::out_of_range("8");
    _array->Set(index, value);
}

template<class T>
void ArraySequence<T>::Resize(int length) {
    _array->Resize(length);
}

template<typename T>
Sequence<T> *ArraySequence<T>::Concat(Sequence<T> *seq) const
{
    if (seq == nullptr)
        throw std::out_of_range("9");
    Sequence<T> *array = (Sequence<T> *) new DynamicArray<T>(_array->GetLength() + seq->GetLength());
    for (int i = 0; i < array->GetLength(); ++i)
        array->Append(_array->Get(i));
    for (int i = 0; i < seq->GetLength(); ++i)
        array->Append(seq->Get(i));
    return array;
}

template<class T>
void ArraySequence<T>::ShakerSort() {
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
void ArraySequence<T>::ShellSort() {
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
std::ostream& operator << (std::ostream &out, const ArraySequence<T> &seq) {
    for (int i = 0; i < seq.GetLength(); ++i) {
        out << (*seq._array)[i];
        if (i == seq.GetLength() - 1)
            break;
        out << ", ";
    }
    return out;
}

template<typename T>
ArraySequence<T>::~ArraySequence()
{
    _array->~DynamicArray<T>();
    delete[] _array;
}
