//
// Created by Maxime BILLY on 30/09/2021.
//

#ifndef M3103_CRDTREE_HPP
#define M3103_CRDTREE_HPP

#include "CNode.hpp"
#include "memory"

using namespace std;

template<typename T>
class CRDTree {
private:
    shared_ptr<CNode<T>> root;
public:
    explicit CRDTree(const T &data) {
        root.reset(new CNode<T> (data));
        cout << "CRDTree created\n";
    }

    ~CRDTree() {
        cout << "CRDTree deleted\n";
    }

    void add(const T &data) {
        if
        root->add(data);
    }

    void show() {
        root->show();
    }

    bool find(const T &data, std::shared_ptr<CNode<T>> current = nullptr) {
        if (current == nullptr) {current = this->root;}
        if (data < current->getData() ) {
            if (current->getLeftNode() != nullptr) {
                return find(data, current->getLeftNode());
            }
            return false;
        } else if (data > current->getData() ) {
            if (current->getRightNode() != nullptr) {
                return find(data, current->getRightNode());
            }
            return false;
        } else {
            return true;
        }
    }
};

#endif