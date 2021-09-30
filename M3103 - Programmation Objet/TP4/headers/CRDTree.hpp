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
        root->add(data);
    }

    void show() {
        root->show();
    }
};

#endif