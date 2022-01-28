#ifndef EXTRA_H
#define EXTRA_H

#include <iostream>
#include <climits>
#include <ctime>
#include "graph.h"
using namespace std;

void enterInt(int *a) {
    int mode = 0;
    cin >> *a;
    if (!cin) {
        while (getchar() != '\n') {};
        cout << "Something's wrong. Try again." << endl << endl;
        mode = -1;
    }
    if (mode == 0) while (getchar() != '\n') {};
}

void enterDefInt(int *a, int start, int end) {
    int error;

    do {
        enterInt(a);

        if (*a >= start && *a <= end) {
            error = 0;
        }
        else {
            cout << "Something's wrong. Try again." << endl << endl;
            error = 1;
        }
    } while (error);
}

void enterDefInt(int *a, int start) {
    int error;

    do {
        enterInt(a);

        if (*a >= start) {
            error = 0;
        }
        else {
            cout << "Something's wrong. Try again." << endl << endl;
            error = 1;
        }
    } while (error);
}

void dialog (string vars[], int vars_size, string request, int* choice) {
    cout << request;
    for(int i = 1; i < vars_size; ++i) cout << i << ". " << vars[i] << endl;

    int error;

    do {
        enterInt(choice);

        if (*choice < vars_size && *choice > 0) {
            cout << "Choice: " << vars[*choice] << endl << endl;
            error = 0;
        }
        else {
            cout << "Something's wrong. Try again." << endl << endl;
            error = 1;
        }
    } while (error);
}

template <class T>
void ShowShortest(int st, Sequence<T>* d) {
    for (int i = 0; i < d->GetLength(); ++i) {
        if ((*d)[i] != INT_MAX)
            cout << st + 1 << " -> " << i + 1 << " = " << (*d)[i] << endl;
        else
            cout << st + 1 << " -> " << i + 1 << " = " << "No way" << endl;
    }
}

Sequence<Sequence<int>*>* FillGraph(int size, bool mode) {
    Sequence<Sequence<int>*>* data = new ArraySequence<Sequence<int>*>(size);
    for (int i = 0; i < size; ++i) {
        data->Get(i) = new ArraySequence<int>(size);
    }

    if (!mode) {    //неориентированный
        for(int i = 0; i < size; ++i) {
            for(int j = i; j < size; ++j) {
                if(i == j) {
                    data->Get(i)->Set(j, 0);
                    continue;
                }
                int* item = new int;
                cout << i + 1 << " -> "  << j + 1 << " = ";
                //cin >> item;
                enterDefInt(item, 0);
                if(*item == 0) {
                    data->Get(i)->Set(j, INT_MAX);
                    data->Get(j)->Set(i, INT_MAX);
                    continue;
                }
                data->Get(i)->Set(j, *item);
                data->Get(j)->Set(i, *item);

                delete item;
            }
        }
    }

    if (mode) { //ориентированный
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                if(i == j) {
                    data->Get(i)->Set(j, 0);
                    continue;
                }
                int item;
                cout << i + 1 << " -> "  << j + 1 << " = ";
                cin >> item;
                if(item == 0) {
                    data->Get(i)->Set(j, INT_MAX);
                    continue;
                }
                data->Get(i)->Set(j, item);
            }
        }
    }

    return data;
}

Sequence<Sequence<int>*>* GenerateGraphRand(int size, bool mode) {
    srand(time(NULL));

    Sequence<Sequence<int>*>* data = new ArraySequence<Sequence<int>*>(size);
    for (int i = 0; i < size; ++i) {
        data->Get(i) = new ArraySequence<int>(size);
    }

    if (!mode) {    //неориентированный
        for(int i = 0; i < size; ++i) {
            for(int j = i; j < size; ++j) {
                if(i == j) {
                    data->Get(i)->Set(j, INT_MAX);
                    continue;
                }
                int item = (rand() % (2 * size)) * (rand() % 2);
                if(item == 0) {
                    data->Get(i)->Set(j, INT_MAX);
                    data->Get(j)->Set(i, INT_MAX);
                    continue;
                }
                data->Get(i)->Set(j, item);
                data->Get(j)->Set(i, item);
            }
        }
    }

    if (mode) { //ориентированный
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                if(i == j) {
                    data->Get(i)->Set(j, INT_MAX);
                    continue;
                }
                int item = (rand() % (2 * size)) * (rand() % 2);
                if(item == 0) {
                    data->Get(i)->Set(j, INT_MAX);
                    continue;
                }
                data->Get(i)->Set(j, item);
            }
        }
    }

    return data;
}

Sequence<Sequence<int>*>* GenerateGraphDef(int size, bool mode, int weight) {
    srand(time(NULL));

    Sequence<Sequence<int>*>* data = new ArraySequence<Sequence<int>*>(size);
    for (int i = 0; i < size; ++i) {
        data->Get(i) = new ArraySequence<int>(size);
    }

    if (!mode) {    //неориентированный
        for(int i = 0; i < size; ++i) {
            for(int j = i; j < size; ++j) {
                if(i == j) {
                    data->Get(i)->Set(j, INT_MAX);
                    continue;
                }
                int item = weight;
                if(item == 0) {
                    data->Get(i)->Set(j, INT_MAX);
                    data->Get(j)->Set(i, INT_MAX);
                    continue;
                }
                data->Get(i)->Set(j, item);
                data->Get(j)->Set(i, item);
            }
        }
    }

    if (mode) { //ориентированный
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                if(i == j) {
                    data->Get(i)->Set(j, INT_MAX);
                    continue;
                }
                int item = weight;
                if(item == 0) {
                    data->Get(i)->Set(j, INT_MAX);
                    continue;
                }
                data->Get(i)->Set(j, item);
            }
        }
    }

    return data;
}

#endif // EXTRA_H
