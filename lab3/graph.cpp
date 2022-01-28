#include "graph.h"
#include <climits>
#include <iostream>
#include <chrono>
using namespace std;

template<typename T>
Graph<T>::Graph() {
    _data = new ArraySequence<Sequence<T>*>();
    _size = 0;
    _mode = true;
}

template<typename T>
Graph<T>::Graph(int size, bool mode) {
    _size = size;
    _data = new ArraySequence<Sequence<T>*>(size);
    for(int i = 0; i < size; ++i) {
        _data->Get(i) = new ArraySequence<T>(size);
    }
    _mode = mode;
}

template<typename T>
Graph<T>::Graph(Sequence<Sequence<T>*>* data) {
    _data = new ArraySequence<Sequence<T>*>(data->GetLength());
    bool mode = false;
    for (int i = 0; i < data->GetLength(); ++i) {
        _data->Get(i) = new ArraySequence<T>(data->GetLength());
        for (int j = 0; j < data->GetLength(); ++j) {
            _data->Get(i)->Set(j, data->Get(i)->Get(j));
            if (data->Get(i)->Get(j) != data->Get(j)->Get(i)) mode = true;
        }
    }
    _size = data->GetLength();
    _mode = mode;
}

template<class T>
int Graph<T>::GetSize() {
    return _size;
}

template<class T>
int Graph<T>::GetMode() {
    return _mode;
}

template<class T>
int Graph<T>::Get(int i, int j) {
    return _data->Get(i)->Get(j);
}

template<class T>
void Graph<T>::Set(int i, int j, T value) {
    return _data->Get(i)->Set(j, value);
}

template <class T>
void Graph<T>::ShowMatrix() {
    for (int i = 0; i < this->GetSize(); i++) {
        for (int j = 0; j < this->GetSize(); j++) {
            if (this->Get(i, j) == INT_MAX || this->Get(i, j) == 0) {
                if (i == j) cout << "*" << "\t";
                else cout << "-" << "\t";
                continue;
            }
            cout << this->Get(i, j)<< "\t";
        }
        cout << endl;
    }
}

template<class T>
Sequence<T>* Graph<T>::FindShortest(int st) {   // Алгоритм Дейкстры
    bool visited[_size];

    Sequence<T>* d = new ArraySequence<T>(_size);
    for(int i = 0; i < _size; ++i) {
        (*d)[i] = this->Get(st, i);
        visited[i] = false;
    }
    (*d)[st] = 0;
    visited[st] = true;
    int index = 0;
    int u = 0;

    for (int i = 0; i < _size; ++i) {
        int min = INT_MAX;
        for (int j = 0; j < _size; ++j) {
            if (!visited[j] && (*d)[j] < min) {
                min = (*d)[j];
                index = j;
            }
        }
        u = index;
        visited[u] = true;
        for(int j = 0; j < _size; ++j) {
            if (!visited[j] && this->Get(u, j) != INT_MAX && ((*d)[u] + this->Get(u, j) < (*d)[j])) {
                (*d)[j] = (*d)[u] + this->Get(u, j);
            }
        }
    }

    return d;
}

template<class T>
bool Graph<T>::IsConnected() {
    int st = 0;
        bool visited[_size];

        bool checker = true;    // проверка на наличие путей ко всем вершинам
        Sequence<T>* d = new ArraySequence<T>(_size);
        for(int i = 0; i < _size; ++i) {
            d->Set(i, this->Get(st, i));
            visited[i] = false;
            if ((*d)[i] == INT_MAX) checker = false;
        }
        (*d)[st] = 0;
        visited[st] = true;
        int index = 0;
        int u = 0;

        if (!checker) {
            for (int i = 0; i < _size; ++i) {
                for (int j = 0; j < _size; ++j) {
                    if (!visited[j] && (*d)[j] < INT_MAX) {
                        index = j;
                        break;
                    }
                }
                u = index;
                visited[u] = true;
                for(int j = 0; j < _size; ++j) {
                    if (!visited[j] && this->Get(u, j) != INT_MAX) {
                        (*d)[j] = (*d)[u] + this->Get(u, j);
                    }
                }
            }
            int count = 0;
            for (int i = 0; i < _size; ++i) {
                if ((*d)[i] != INT_MAX) ++count;
            }

            if (count == _size) return true;
            else return false;
        }
    return true;
}

template<class T>
Sequence<Sequence<T>*>* Graph<T>::FindSkeleton() { // Алгоритм Прима
    Sequence<Sequence<T>*>* data = new ArraySequence<Sequence<T>*>(_size);
    for (int i = 0; i < _size; ++i) {
        data->Get(i) = new ArraySequence<T>(_size);
    }
    for (int i = 0; i < _size; ++i) {
        for (int j = 0; j < _size; ++j) {
            data->Get(i)->Set(j, INT_MAX);
        }

    }

    bool selected[_size];
    for(int i = 0; i < _size; ++i) {
        selected[i] = false;
    }
    selected[0] = true;

    for (int edge = 0; edge < _size - 1; ++edge) {
        int min = INT_MAX;
        int x = 0;
        int y = 0;

        for (int i = 0; i < _size; ++i) {
            if (selected[i]) {
                for (int j = 0; j < _size; ++j) {
                    if (!selected[j] && this->Get(i, j) < min) {
                        min = this->Get(i, j);
                        x = i;
                        y = j;
                    }
                }
            }
        }
        selected[y] = true;

        data->Get(x)->Set(y, this->Get(x, y));
        data->Get(y)->Set(x, this->Get(x, y));
    }

    return data;
}

template<class T>
T Graph<T>::Cost() {
    T cost = 0;
    for (int i = 0; i < _size; ++i) {
        for (int j = i; j < _size; ++j) {
            if (this->Get(i, j) != INT_MAX) {
                cost += this->Get(i, j);
            }
        }
    }
    return cost;
}

template<class T>
Graph<T>::~Graph() {
    for (int i = 0; i < _size; ++i) {
            delete[] _data->Get(i);
    }
    delete[] _data;
    _size = 0;
    _mode = true;
}
