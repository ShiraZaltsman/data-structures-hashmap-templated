//
// Created by shira on 12/16/19.
//

#ifndef DATA_STRUCTURES_SINGLY_LINKED_LIST_TEMPLATED_SHIRAZALTSMAN_LINKEDLIST_H
#define DATA_STRUCTURES_SINGLY_LINKED_LIST_TEMPLATED_SHIRAZALTSMAN_LINKEDLIST_H

#include <clocale>
#include <iostream>

template<class T>
class LinkedList {
private:

    struct Node {
        explicit Node(T value);
        Node *next;
        T value;
    };

    Node* m_head;
public:
    LinkedList();
    ~LinkedList(){clear();}

    // Iterator class can be used to
    // sequentially access nodes of linked list
    class Iterator
    {
    public:
        Iterator();

        Iterator(const Node* pNode);

        Iterator& operator=(Node* pNode){
            this->m_CurrentNode = pNode;
            return *this;
        }

        // Prefix ++ overload
        Iterator& operator++(){
            if (m_CurrentNode)
                m_CurrentNode = m_CurrentNode->next;
            return *this;
        }

        // Postfix ++ overload
        Iterator operator++(int){
            Iterator iterator = *this;
            ++*this;
            return iterator;
        }

        bool operator!=(const Iterator& iterator);

        T operator*();


    private:
        const Node* m_CurrentNode;
    };

    Iterator begin()
    {
        return Iterator(m_head);
    }

    Iterator end()
    {
        return Iterator(NULL);
    }

    // operations
    void add(T value);

    bool search(const T &value) const;

    bool isEmpty() const;

    void clear();

    void remove(T key);

    void push(T value);


    //oprators

  //  friend std::ostream & operator<< (std::ostream & os, const LinkedList<T> & B);//prints values of lists


};
template<class T>
inline LinkedList<T>::Node::Node(T value) : value(value), next(NULL) {

}
template<class T>
inline LinkedList<T>::LinkedList(): m_head(NULL) {

}

template<class T>
inline bool LinkedList<T>::isEmpty() const {
    return m_head == NULL;
}

template<class T>
inline void LinkedList<T>::add(T value) {
    Node *newNode = new Node(value);
    if (m_head == NULL) {
        m_head =  newNode;
    } else {
        Node *current = m_head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

template<class T>
inline bool LinkedList<T>::search(const T &value) const {
    if (m_head == NULL) {
        return false;
    } else {
        Node *next = m_head;
        while (next) {
            if(next->value == value){
                return true;
            } else {
                next = next->next;
            }
        }
        return false;
    }
}

template<class T>
inline void LinkedList<T>::clear() {
    Node* current;
    Node* next;
    current = m_head;
    while (current){
        next = current->next;
        delete current;
        current = next;
    }
    m_head = NULL;

}

template<class T>
inline void LinkedList<T>::remove(T key) {
    if (m_head == NULL) {
        return;
    } else {
        Node *current = m_head;
        Node *next = current->next;
        while (next) {
            if(next->value == key){
                current->next = next -> next;
                delete next;
                return;
            } else {
                current = current->next;
                next = next->next;
            }
        }
    }
}

template<class T>
inline void LinkedList<T>::push(T value) {
    Node *newNode = new Node(value);
    if (m_head == NULL) {
        m_head = newNode;
    } else {
        Node *tmp = m_head;
        m_head= newNode;
        newNode->next = tmp;
    }
}


template<class T>
inline LinkedList<T>::Iterator::Iterator() : m_CurrentNode(this->m_head) {}

template<class T>
inline LinkedList<T>::Iterator::Iterator(const LinkedList::Node *pNode) : m_CurrentNode(pNode) {}

template<class T>
inline bool LinkedList<T>::Iterator::operator!=(const LinkedList::Iterator &iterator) {
    return m_CurrentNode != iterator.m_CurrentNode;
}

template<class T>
inline T LinkedList<T>::Iterator::operator*() {
    return m_CurrentNode->value;
}

#endif //DATA_STRUCTURES_SINGLY_LINKED_LIST_TEMPLATED_SHIRAZALTSMAN_LINKEDLIST_H
