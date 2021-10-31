#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#pragma once

template <typename T>
class LinkedList
{

private:
    class Node
    {
    public:
        T data;
        Node *pNext;
        Node(T data = T(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    Node *_head;
    int _length;

public:
    LinkedList();
    LinkedList(T* data, int count);
    LinkedList(const LinkedList <T>& list);

    T& front() const;
    T& back() const;
    T& Get(int index) const;
    T& operator[] (const int index);
    void pop_front();
    void pop_back();
    void delete_by_index(int index);
    void clear();
    LinkedList<T>* GetSubList (int start_index, int end_index) const;
    int GetLength () const;

    void push_front(const T& data);
    void push_back(const T& data);
    void InsertAt(const T& data, int index);
    void Set(int index, const T& data);
    LinkedList<T>* Concat(LinkedList<T> *list) const;


    ~LinkedList();
};

#endif // LINKEDLIST_H
