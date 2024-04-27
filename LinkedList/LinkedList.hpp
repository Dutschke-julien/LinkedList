#ifndef __LINKEDLIST_HPP__
# define __LINKEDLIST_HPP__

#include "Node.hpp"
#include <iostream>

template<typename T>
class LinkedList 
{
    public:
    Node<T>* head;
    Node<T>* tail;

    LinkedList();
    ~LinkedList();

    void add_back(T data);
    int size();
    Node<T>* findSmallest();
    Node<T>* findLargest();
    void add_front(T data);
    void pop_front();
    void pop_back();
    void remove(Node<T>* node);
    void print();

    class Iterator
    {
        private:
            Node<T>* pointer;

        public:
            Iterator(Node<T>* ptr);
            Iterator& operator++();
            Iterator& operator--();
            Node<T>* operator*();
            bool operator!=(const Iterator& other);
            friend std::ostream& operator<<(std::ostream& os, const typename LinkedList<T>::Iterator& it)
            {
            if (it.pointer)
                os << *(it.pointer);
            else
                os << "null";
            return os;
          }

    };
        Iterator begin();
        Iterator end();
        void remove(Iterator it);
};


#include "LinkedList.tpp"
#include "Iterator.tpp"

#endif


