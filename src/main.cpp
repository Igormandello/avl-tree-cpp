#include <iostream>
#include "AVLTree.hpp"

using namespace std;

int main() {
  AVLTree<char> t;

  char data[] = {'M', 'N', 'O', 'L', 'K', 'Q', 'P', 'H', 'I', 'A'};
  for (int n = 0; n < 10; n++) {
    t.add(data[n]);
    cout << t;
    cout << endl;
  }

  return 0;
}
