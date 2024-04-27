#ifndef __NODE_HPP__
# define __NODE_HPP__

#include <iostream>

template<typename T>
class Node
{
    public:
    T _data;
    Node<T>* prev;
    Node<T>* next;

    Node() : _data(0), prev(nullptr), next(nullptr) {}
    Node(T data) : _data(data), prev(nullptr), next(nullptr) {}
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Node<T>* node)
{
    if (node != nullptr)
        os << node->_data;
    else
        os << "null";
    return os;
}

#endif // __NODE_HPP__