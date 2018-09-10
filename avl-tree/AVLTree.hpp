#ifndef AVLTREE_INCLUDED
#define AVLTREE_INCLUDED

#include "Node.hpp"
#include <iostream>

using namespace std;

template <class T>
class AVLTree {
    public:
        AVLTree();
        void add(T*);

    private:
        Node<T>* root;
};

#include "AVLTree.cpp"

#endif // AVLTREE_INCLUDED
