#ifndef NODE_INCLUDED
#define NODE_INCLUDED

#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
class Node {
  public:
    Node(T);
    void add(T);
    void remove(T);
    T* get(T);
    T getMin();
    T getMax();
    bool isEmpty();
    template <class U>
    friend ostream& operator<<(ostream&, const Node<U>&);

  private:
    T info;
    Node<T>* left;
    Node<T>* right;
    int factor;

    void calcFactor();
    int maxHeight(int);
    void balance();
    void leftRotation();
    void rightRotation();
};

#include "Node.cpp"

#endif  // NODE_INCLUDED
