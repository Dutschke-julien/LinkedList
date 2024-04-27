template <typename T>
LinkedList<T>::Iterator::Iterator(Node<T>* ptr) : pointer(ptr) {}

template <typename T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++() 
{
    if (pointer)
        pointer = pointer->next;
    return *this;
}


template <typename T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator--()
{
    if (pointer)
        pointer = pointer->prev;
    return *this;
}

template <typename T>
Node<T>* LinkedList<T>::Iterator::operator*()
{
    return pointer;
}

template <typename T>
bool LinkedList<T>::Iterator::operator!=(const Iterator& other)
{
    if (pointer != other.pointer)
        return true;
    return false;
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin()
{
    return Iterator(head);
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end()
{
    return Iterator(tail);
}