#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template<class T>
class DynamicArray {

private:
    T *_data;
    int _length;

public:
    DynamicArray();
    DynamicArray(T *data, int index);
    DynamicArray(int length);
    DynamicArray(const DynamicArray<T>& array);

    T& Get(int index);
    T& Get(int index, const T &error);
    void DelByIndex(int index);
    int GetLength() const;

    void Set(const T &value, int index);
    void Resize(int length);

    ~DynamicArray();
};

#endif // DYNAMICARRAY_H
