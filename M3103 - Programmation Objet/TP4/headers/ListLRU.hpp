//
// Created by Martin Moreira de Jesus on 25/09/2021.
//

#ifndef M3103_LISTLRU_HPP
#define M3103_LISTLRU_HPP

#include "CNode.hpp"
#include <iostream>

template<typename T>
class ListLRU {
private:
    std::shared_ptr<CNode<T>> m_fictionHead;
    std::shared_ptr<CNode<T>> m_fictionTail;

    const int MAX_SIZE = 10;

    int getSize() const;

    void putFront(const std::shared_ptr<CNode<T>> &node);

public:
    ListLRU();

    ~ListLRU() = default;

    void display() const;

    std::shared_ptr<CNode<T>> find(const T &val);

    void add(const T &val);

    void remove();
};

template<typename T>
ListLRU<T>::ListLRU() : m_fictionHead(new CNode<T>()), m_fictionTail(new CNode<T>()) {
    m_fictionHead->setNextNode(m_fictionTail);
    m_fictionTail->setPreviousNode(m_fictionHead);
}

template<typename T>
void ListLRU<T>::putFront(const std::shared_ptr<CNode<T>> &node) {
    if (node == m_fictionHead->getNextNode()) return;
    m_fictionHead->getNextNode()->setPreviousNode(node);
    node->getNextNode()->setPreviousNode(node->getPreviousNode());
    node->getPreviousNode()->setNextNode(node->getNextNode());
    node->setPreviousNode(m_fictionHead);
    node->setNextNode(m_fictionHead->getNextNode());
    m_fictionHead->setNextNode(node);
}

template<typename T>
void ListLRU<T>::display() const {
    for (std::shared_ptr<CNode<T>> ptr(m_fictionHead->getNextNode());
         ptr != m_fictionTail; ptr = ptr->getNextNode()) {
        std::cout << ptr->getData() << "; ";
    }
    std::cout << std::endl;
}

template<typename T>
std::shared_ptr<CNode<T>> ListLRU<T>::find(const T &val) {
    std::shared_ptr<CNode<T>> tmp;
    for (std::shared_ptr<CNode<T>> ptr(m_fictionHead->getNextNode()); ptr != m_fictionTail; ptr = ptr->getNextNode()) {
        if (ptr->getData() == val) {
            putFront(ptr);
            return ptr;
        }
    }
    return nullptr;
}

template<typename T>
void ListLRU<T>::add(const T &val) {
    if (this->getSize() >= MAX_SIZE) {
        this->remove();
    }
    std::shared_ptr<CNode<T>> tmp(new CNode<T>(val, m_fictionHead->getNextNode(), m_fictionHead));
    m_fictionHead->getNextNode()->setPreviousNode(tmp);
    m_fictionHead->setNextNode(tmp);
    if (m_fictionTail->getPreviousNode() == m_fictionHead) {
        m_fictionTail->setPreviousNode(tmp);
    }
}

template<typename T>
void ListLRU<T>::remove() {
    m_fictionTail->getPreviousNode()->getPreviousNode()->setNextNode(m_fictionTail);
    m_fictionTail->setPreviousNode(m_fictionTail->getPreviousNode()->getPreviousNode());
}

template<typename T>
int ListLRU<T>::getSize() const {
    int size = 0;
    for (std::shared_ptr<CNode<T>> ptr(m_fictionHead->getNextNode());
         ptr != m_fictionTail; ptr = ptr->getNextNode(), size++) {}
    return size;
}

#endif //M3103_LISTLRU_HPP
