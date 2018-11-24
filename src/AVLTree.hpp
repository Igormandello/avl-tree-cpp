#ifndef AVLTREE_INCLUDED
#define AVLTREE_INCLUDED

#include "Node.hpp"
#include <iostream>

using namespace std;

template <class T>
class AVLTree {
    public:
        AVLTree();
        void add(T);
        void remove(T);
        T* get(T);
        template <class U>
        friend ostream& operator<<(ostream&, const AVLTree<U>&);
        void balance();

    private:
        Node<T>* root;
};

#include "AVLTree.cpp"

#endif // AVLTREE_INCLUDED