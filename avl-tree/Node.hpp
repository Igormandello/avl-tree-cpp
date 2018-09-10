#ifndef NODE_INCLUDED
#define NODE_INCLUDED

#include <iostream>

template <class T>
class Node {
    public:
        Node(T*);
        void add(T*);

    private:
        T* info;
        Node<T>* left;
        Node<T>* right;
};

#include "Node.cpp"

#endif // NODE_INCLUDED
