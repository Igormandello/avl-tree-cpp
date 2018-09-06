template<class T>
AVLTree<T>::AVLTree() {
    this->root = NULL;
}

template<class T>
void AVLTree<T>::add(T newInfo) {
    this->root = new Node<T>(newInfo);
}
