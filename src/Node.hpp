#ifndef NODE_INCLUDED
#define NODE_INCLUDED

#include <cstdlib>
#include <iostream>
#include <queue>

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
    void enqueueChildren(queue<Node<T>*>&);
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

#include "Node.inl"

#endif  // NODE_INCLUDED
