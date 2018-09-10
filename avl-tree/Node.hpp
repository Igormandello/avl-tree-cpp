#ifndef NODE_INCLUDED
#define NODE_INCLUDED

#include <iostream>

using namespace std;

template <class T>
class Node {
    public:
        Node(T);
        void add(T);
        void print(ostream&);

    private:
        T info;
        Node<T>* left;
        Node<T>* right;
        int factor;

        void calcFactor();
        int maxHeight(int);
};

#include "Node.cpp"

#endif // NODE_INCLUDED
