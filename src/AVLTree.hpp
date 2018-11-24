#ifndef AVLTREE_INCLUDED
#define AVLTREE_INCLUDED

#include <iostream>
#include "Node.hpp"

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

#include "AVLTree.inl"

#endif  // AVLTREE_INCLUDED
