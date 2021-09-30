//
// Created by Martin Moreira de Jesus on 25/09/2021.
//

#ifndef M3103_CLIST_HPP
#define M3103_CLIST_HPP

#include "CNode.hpp"

template<typename T>
class CList {
private:
    std::shared_ptr<CNode<T>> fictionHead;
    std::shared_ptr<CNode<T>> fictionTail;
public:
    CList();

    virtual ~CList();

    const std::shared_ptr<CNode<T>> &begin() const;

    const std::shared_ptr<CNode<T>> &end() const;

    void displayFromHead() const;

    void displayFromTail() const;

    void pushFront(const T &val);

    void pushBack(const T &val);

    std::shared_ptr<CNode<T>> find(const T &val) const;

    void addAfter(const std::shared_ptr<CNode<T>> &node, const T &val);

    void addBefore(const std::shared_ptr<CNode<T>> &node, const T &val);

    void remove(const std::shared_ptr<CNode<T>> &node);
};

template<typename T>
CList<T>::CList() : fictionHead(new CNode<T>()), fictionTail(new CNode<T>()) {
    this->fictionHead->setNextNode(this->fictionTail);
    this->fictionTail->setPreviousNode(this->fictionHead);
}

template<typename T>
CList<T>::~CList() {
    std::cout << "List deleted\n";
}

template<typename T>
void CList<T>::displayFromHead() const {
    for (std::shared_ptr<CNode<T>> tmp(this->fictionHead->getNextNode());
         tmp != this->fictionTail; tmp = tmp->getNextNode()) {
        std::cout << tmp->getData() << "; ";
    }
    std::cout << std::endl;
}

template<typename T>
void CList<T>::displayFromTail() const {
    for (std::shared_ptr<CNode<T>> tmp(this->fictionTail->getPreviousNode());
         tmp != this->fictionHead; tmp = tmp->getPreviousNode()) {
        std::cout << tmp->getData() << "; ";
    }
    std::cout << std::endl;
}

template<typename T>
void CList<T>::pushFront(const T &val) {
    std::shared_ptr<CNode<T>> tmp(new CNode<T>(val, this->fictionHead->getNextNode(), this->fictionHead));
    this->fictionHead->setNextNode(tmp);
    tmp->getNextNode()->setPreviousNode(tmp);
}

template<typename T>
void CList<T>::pushBack(const T &val) {
    std::shared_ptr<CNode<T>> tmp(new CNode<T>(val, this->fictionTail, this->fictionTail->getPreviousNode()));
    this->fictionTail->getPreviousNode()->setNextNode(tmp);
    this->fictionTail->setPreviousNode(tmp);
}

template<typename T>
std::shared_ptr<CNode<T>> CList<T>::find(const T &val) const {
    for (std::shared_ptr<CNode<T>> tmp(this->fictionHead->getNextNode());
         tmp != this->fictionTail; tmp = tmp->getNextNode()) {
        if (tmp->getData() == val) {
            return tmp;
        }
    }
    return nullptr;
}

template<typename T>
void CList<T>::addAfter(const std::shared_ptr<CNode<T>> &node, const T &val) {
    std::shared_ptr<CNode<T>> tmp(new CNode<T>(val, node->getNextNode(), node));
    node->setNextNode(tmp);
    tmp->getNextNode()->setPreviousNode(tmp);
}

template<typename T>
void CList<T>::addBefore(const std::shared_ptr<CNode<T>> &node, const T &val) {
    std::shared_ptr<CNode<T>> tmp(new CNode<T>(val, node, node->getPreviousNode()));
    node->getPreviousNode()->setNextNode(tmp);
    node->setPreviousNode(tmp);
}

template<typename T>
void CList<T>::remove(const std::shared_ptr<CNode<T>> &node) {
    if (node == nullptr) return;
    node->getNextNode()->setPreviousNode(node->getPreviousNode());
    node->getPreviousNode()->setNextNode(node->getNextNode());
}

template<typename T>
const std::shared_ptr<CNode<T>> &CList<T>::begin() const {
    return this->fictionHead;
}

template<typename T>
const std::shared_ptr<CNode<T>> &CList<T>::end() const {
    return this->fictionTail;
}

#endif //M3103_CLIST_HPP
