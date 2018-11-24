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
void AVLTree<T>::remove(T info) {
    if (this->root != NULL) {
        this->root->remove(info);

        if (this->root->isEmpty()) {
            delete this->root;
            this->root = NULL;
        }
    }
}

template<class T>
T* AVLTree<T>::get(T desiredInfo) {
    if (this->root == NULL)
        return NULL;
    else
        return this->root->get(desiredInfo);
}

template<class T>
ostream& operator<<(ostream& os, const AVLTree<T>& a) {
    if (a.root != NULL)
        os << *a.root;

    return os;
}
