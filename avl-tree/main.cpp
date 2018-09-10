#include "AVLTree.hpp"
#include <iostream>

using namespace std;

int main()
{
    AVLTree<int> *t = new AVLTree<int>();

    int data[] = { 5, 4, 3 };
    for (int n = 0; n < 3; n++)
        t->add(data[n]);

    t->print(cout);

    return 0;
}
