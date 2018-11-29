template <class T>
AVLTree<T>::AVLTree() {
  this->root = NULL;
}

template <class T>
void AVLTree<T>::add(T newInfo) {
  if (this->root == NULL)
    this->root = new Node<T>(newInfo);
  else
    this->root->add(newInfo);
}

template <class T>
void AVLTree<T>::remove(T info) {
  if (this->root != NULL) {
    this->root->remove(info);

    if (this->root->isEmpty()) {
      delete this->root;
      this->root = NULL;
    }
  }
}

template <class T>
bool AVLTree<T>::isEmpty() {
  return this->root == NULL;
}

template <class T>
T* AVLTree<T>::get(T desiredInfo) {
  if (this->root == NULL)
    return NULL;
  else
    return this->root->get(desiredInfo);
}

template <class T>
ostream& operator<<(ostream& os, const AVLTree<T>& a) {
  queue<Node<T>*> q;
  q.push(a.root);

  int traversed = 0, level = 0;
  while (!q.empty()) {
    Node<T>* current = q.front();
    q.pop();
    traversed++;

    if (current == NULL)
      os << "{}";
    else {
      current->enqueueChildren(q);
      os << *current;
    }

    if (traversed == pow(2, level)) {
      level++;
      traversed = 0;
      os << endl;
    }
  }

  return os;
}
