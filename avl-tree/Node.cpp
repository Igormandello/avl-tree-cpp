template<class T>
Node<T>::Node(T* info) {
    this->info = info;
    this->left = NULL;
    this->right = NULL;
}

template<class T>
void Node<T>::add(T* info) {
    if (this->info > info)
        if (this->left != NULL)
            this->left->add(info);
        else
            this->left = new Node<T>(info);
    else
        if (this->right != NULL)
            this->right->add(info);
        else
            this->right = new Node<T>(info);
}
