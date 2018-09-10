template<class T>
AVLTree<T>::AVLTree() {
    this->root = NULL;
}

template<class T>
void AVLTree<T>::add(T newInfo) {
    if (this->root == NULL)
        this->root = new Node<T>(newInfo);
    else
        this->root->add(newInfo);
}

template<class T>
void AVLTree<T>::print(ostream &os) {
    if (this->root != NULL)
        this->root->print(os);
}
