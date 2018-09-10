#include "AVLTree.hpp"
#include <iostream>

using namespace std;

int main()
{
    AVLTree<char> *t = new AVLTree<char>();

    char data[] = { 'N', 'L', 'P', 'K', 'M', 'O', 'Q', 'H', 'I' };
    for (int n = 0; n < 9; n++) {
        t->add(data[n]);
        t->print(cout);
        cout << endl;
    }

    return 0;
}
