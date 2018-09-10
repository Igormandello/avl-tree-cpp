template<class T>
Node<T>::Node(T info) {
    this->info = info;
    this->left = NULL;
    this->right = NULL;

    this->factor = 0;
}

template<class T>
void Node<T>::add(T info) {
    if (this->info > info)
        if (this->left != NULL) {
            this->left->add(info);
            this->left->calcFactor();
        } else
            this->left = new Node<T>(info);
    else
        if (this->right != NULL) {
            this->right->add(info);
            this->left->calcFactor();
        } else
            this->right = new Node<T>(info);

    this->calcFactor();
}

template<class T>
void Node<T>::calcFactor() {
    int left = 0;
    if (this->left != NULL)
        left = this->left->maxHeight(0);

    int right = 0;
    if (this->right != NULL)
        right = this->right->maxHeight(0);

    this->factor = right - left;
}


template<class T>
int Node<T>::maxHeight(int motherHeight) {
    int actualHeight = motherHeight + 1, mHeight =  actualHeight;
    if (this->left != NULL) {
        int leftHeight = this->left->maxHeight(actualHeight);
        if (leftHeight > mHeight)
            mHeight = leftHeight;
    }

    if (this->right != NULL) {
        int rightHeight = this->right->maxHeight(actualHeight);
        if (rightHeight > mHeight)
            mHeight = rightHeight;
    }

    return mHeight;
}

template<class T>
void Node<T>::print(ostream &os) {
    os << "(";
    if (this->left != NULL)
        this->left->print(os);

    os << "{ " << this->info << ", " << this->factor << " }";

    if (this->right != NULL)
        this->right->print(os);
    os << ")";
}
