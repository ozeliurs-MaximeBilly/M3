//
// Created by Martin Moreira de Jesus on 25/09/2021.
// Completed by Maxime BILLY on the 30/09/2021 with the help of his overlord god.
//

#ifndef M3103_CNODE_HPP
#define M3103_CNODE_HPP

#include <iostream>
#include <memory>
#include <stdlib.h>

template<typename T>
class CNode {
private:
    T data;
    std::shared_ptr<CNode<T>> left, right;
public:
    CNode(const T &data,
                    const std::shared_ptr<CNode<T>> &right = nullptr,
                    const std::shared_ptr<CNode<T>> &left = nullptr) {
        srand(time(0));
        this->data = data;
        this->right = right;
        this->left = left;
    }
    ~CNode() {
    }

    const T &getData() const {
        return this->data;
    }

    const std::shared_ptr<CNode<T>> &getRightNode() const {
        return this->right;
    }

    const std::shared_ptr<CNode<T>> &getLeftNode() const {
        return this->left;
    }

    void setRightNode(const std::shared_ptr<CNode<T>> &node) {
        this->right = node;
    }

    void setLeftNode(const std::shared_ptr<CNode<T>> &node) {
        this->left = node;
    }

    void add(const T& data){
        if (data > this->data) {
            if (right == nullptr) {
                right.reset(new CNode<T>(data));
            } else {
                right->add(data);
            }
        } else if (data < this->data) {
            if (left == nullptr) {
                left.reset(new CNode<T>(data));
            } else {
                left->add(data);
            }
        }
    }

    void show(){
        if (left != nullptr) {left->show();}
        std::cout << data << "\n";
        if (right != nullptr) {right->show();}
    }
};

#endif //M3103_CNODE_HPP

//eof