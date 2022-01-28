#ifndef GRAPH_H
#define GRAPH_H

#include "arraysequence.cpp"
using namespace std;

template <typename T>
class Graph
{
private:
    Sequence<Sequence<T>*>* _data;  // матрица весов
    int _size;  // число вершин
    bool _mode; // true - ориентированный граф; false - неориентированный

public:
    Graph();
    Graph(int size, bool mode);
    Graph(Sequence<Sequence<T>*>* data);

    int GetSize();
    int GetMode();
    int Get(int i, int j);
    void Set(int i, int j, T value);
    void ShowMatrix();

    Sequence<T>* FindShortest(int st);

    bool IsConnected();

    Sequence<Sequence<T>*>* FindSkeleton();
    T Cost();

    ~Graph();
};

#endif // GRAPH_H
