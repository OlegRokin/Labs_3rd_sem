#pragma once

#include <iostream>
#include "linkedlist.h"

template<typename T>
LinkedList<T>::LinkedList()
{
    _length = 0;
    _head = nullptr;
}

template<typename T>
LinkedList<T>::LinkedList(T *data, int count) : LinkedList()
{
    for (int i = 0; i < count; i++)
        push_back(data[i]);
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list)
{
    Node *node = list._head->pNext;
    for (int i = 0; i < list._length; i++)
        InsertAt(node->data, i);
}

template<typename T>
T &LinkedList<T>::front() const
{
    if (_length == 0)
    {
        throw std::out_of_range ("from LinkedList<T>::front()");
    }
    return _head->data;
}

template<typename T>
T &LinkedList<T>::back() const
{
    if (_length == 0)
        throw std::out_of_range ("from LinkedList<T>::back()");
    Node *node = this->_head;
    for (int i = 0; i < _length; ++i)
    {
        node = node->pNext;
    }
    return node->data;
}

template<typename T>
T &LinkedList<T>::Get(int index) const
{
    if (index >= _length || index < 0)
    {
        throw std::out_of_range ("from LinkedList<T>::get(int index)");
    }
    Node *node = _head;
    for (int i = 0; i < index; ++i)
    {
        node = node->pNext;
    }
    return node->data;

}

template<class T>
T &LinkedList<T>::operator[](const int index) {
    if (index >= this->GetLength() || index < 0)
        throw std::out_of_range ("");
    return this->Get(index);
}

template<typename T>
void LinkedList<T>::pop_front()
{
    if (_length == 0)
    {
        throw std::out_of_range ("from LinkedList<T>::pop_front()");
    }
    Node* del_node = _head;
    _head = _head->pNext;
    delete del_node;
    --_length;
}

template<typename T>
void LinkedList<T>::pop_back()
{
    if (_length == 0)
    {
        throw std::out_of_range ("from LinkedList<T>::pop_back()");
    }
    Node* node = _head;
    for (int i = 0; i < _length - 1; ++i) node = node->pNext;
    Node* del_node = node->pNext;
    node->pNext = nullptr;
    delete del_node;
    --_length;
}

template<typename T>
void LinkedList<T>::delete_by_index(int index)
{
    if (index < 0 || index >= _length)
    {
        throw std::out_of_range ("from LinkedList<T>::delete_by_index(int index)");
    }
    if (index == 0)
    {
        pop_front();
        return;
    }
    Node *n = _head;
    for (int i = 1; i < index; ++i)
    {
        n = n->pNext;
    }
    Node *n_del = n->pNext;
    n->pNext = n->pNext->pNext;
    delete n_del;
    --_length;
}

template<typename T>
void LinkedList<T>::clear()
{
    while (_length)
        pop_front();
}

template<typename T>
LinkedList<T> *LinkedList<T>::GetSubList(int start_index, int end_index) const
{
    if (start_index < 0 || start_index >= _length || end_index < 0 || end_index > _length || start_index > end_index)
        throw std::out_of_range ("from LinkedList<T>::GetSubList(int start_index, int end_index)");
    LinkedList<T>* list = new LinkedList<T>;
    for (int i = start_index; i < end_index; ++i)
        (*list).push_back(this->Get(i));
    return list;
}

template<typename T>
int LinkedList<T>::GetLength() const
{
    return _length;
}

template<typename T>
void LinkedList<T>::push_front(const T &data)
{
    Node* new_node = new Node(data);
    if (_length == 0) {
        _head = new_node;
        ++_length;
        return;
    }
    new_node->pNext = _head;
    _head = new_node;
}

template<typename T>
void LinkedList<T>::push_back(const T &data)
{
    Node* new_node = new Node(data);
    if (!this->_length) {
        this->_head = new_node;
        ++this->_length;
        return;
    }
    Node *node = this->_head;
    for(int i = 0; i < this->_length - 1; ++i) {
        node = node->pNext;
    }
    node->pNext = new_node;
    ++this->_length;
}

template<typename T>
void LinkedList<T>::InsertAt(const T &data, int index)
{
    if (index < 0 || index > this->_length)
        throw std::out_of_range ("from LinkedList<T>::InsertAt(const T &data, int index)");
    if (!index) {
        this->push_front(data);
        return;
    }
    if (index == this->_length) {
        this->push_back(data);
        return;
    }
    Node* node = this->_head;
    for (int i = 0; i < index - 1; ++i) {
        node = node->pNext;
    }
    Node* new_node = new Node(data, node->pNext);
    node->pNext = new_node;
    ++this->_length;

}

template<typename T>
void LinkedList<T>::Set(int index, const T& data)
{
    if (index < 0 || index > this->_length)
        throw std::out_of_range ("from LinkedList<T>::Set(int index, const T& data)");
    if (index == _length) {
        this->push_back(data);
        return;
    }
    Node* node = this->_head;
    for (int i = 0; i < index; ++i) {
        node = node->pNext;
    }
    node->data = data;
}

template<typename T>
LinkedList<T> *LinkedList<T>::Concat(LinkedList<T> *list) const
{
    if (list == nullptr)
        throw std::out_of_range ("from LinkedList<T>::Concat(LinkedList<T> *list)");
    LinkedList* new_list = new LinkedList;
    for (int i = 0; i < _length; ++i) {
        new_list->push_back(this->Get(i));
    }
    for (int i = 0; i < list->_length; ++i) {
        new_list->push_back(list->Get(i));
    }
    return new_list;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}
