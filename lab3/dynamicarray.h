#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template <typename T>
class DynamicArray
{
private:
    T *_data;
    int _length;

public:
    DynamicArray();
    DynamicArray(T *data, int index);
    DynamicArray(int length);
    DynamicArray(const DynamicArray<T>& array);

    T& Get(int index);
    T& operator[] (const int index);
    void DelByIndex(int index);
    void Clear();
    int GetLength() const;

    void Set(int index, T value);
    void Resize(int length);

    ~DynamicArray();
};

#endif // DYNAMICARRAY_H
