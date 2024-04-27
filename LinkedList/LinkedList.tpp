#include "LinkedList.hpp"

template <typename T>
void LinkedList<T>::remove(typename LinkedList<T>::Iterator it)
{
    remove(*it);
}

template <typename T>
void LinkedList<T>::remove(Node<T>* node)
{
    Iterator it = begin();
    for (; it != NULL; ++it)
    {
        if (*it == node)
        {
            if (node->prev != nullptr)
                node->prev->next = node->next;
            if (node->next != nullptr)
                node->next->prev = node->prev;
            delete node;
            return;
        }
    }
}



template <typename T>
void LinkedList<T>::pop_front()
{
    if (head != nullptr)
    {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void LinkedList<T>::pop_back()
{
    if (tail != nullptr)
    {
        Node<T>* temp = tail;
        tail = tail->prev;
        delete temp;
    }
}


template <typename T>
Node<T>* LinkedList<T>::findSmallest()
{ 
    Iterator it = begin();
    Node<T>* smallest = *it;
    for (; it != NULL; ++it)
    {
        if ((*it)->_data < smallest->_data)
            smallest = *it;
    }
    return smallest;
}

template <typename T>
Node<T>* LinkedList<T>::findLargest()
{
    Iterator it = begin();
    Node<T>* largest = *it;
    for (; it != NULL; ++it)
    {
        if ((*it)->_data > largest->_data)
            largest = *it;
    }
    return largest;
}


template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) 
{
}

template <typename T>
LinkedList<T>::~LinkedList() 
{
}

template <typename T>
void LinkedList<T>::add_front(T data)
{
    Node<T>* newNode = new Node<T>(data);
    if (head != nullptr) 
    {
        head->prev = newNode;
        newNode->next = head;
        newNode->prev = nullptr;
        head = newNode;
    }
    else
    {
        head = newNode;
        tail = newNode;
    }
}

template <typename T>
void LinkedList<T>::add_back(T data)
{
    Node<int>* newNode = new Node<int>(data);

    if(tail != nullptr)
    {
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = nullptr;
        tail = newNode;
    }
    else
    {
        head = newNode;
        tail = newNode;
    }
}

template <typename T>
void LinkedList<T>::print()
{
    Iterator it = begin();
    std::cout << "Head -> ";
    for (; it != NULL; ++it)
    {
        std::cout << "["<< *it << "] ";
    }
    std::cout << " <- Tail" << std::endl;
}

template <typename T>
int LinkedList<T>::size()
{
    int count = 0;
    Iterator it = begin();
    for (; it != NULL; ++it)
    {
        count++;
    }
    return count;
}