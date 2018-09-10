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
            /*this->left->calcFactor();

            if (abs(this->left->factor) > 1)
                this->left->balance();*/
        } else
            this->left = new Node<T>(info);
    else
        if (this->right != NULL) {
            this->right->add(info);
            /*this->right->calcFactor();

            if (abs(this->right->factor) > 1)
                this->right->balance();*/
        } else
            this->right = new Node<T>(info);

    this->calcFactor();
    if (abs(this->factor) > 1)
        this->balance();
}

template<class T>
void Node<T>::balance() {
    if (this->factor > 1) {
        if (this->right->left == NULL) //Left rotation
            this->leftRotation();
        else if (this->right->right == NULL) { //Right left rotation
            this->right->rightRotation();
            this->leftRotation();
        } else { //Left rotation with child
            cout << "To Do";
        }
    } else if (this->factor < -1) {
        if (this->left->right == NULL) //Right rotation
            this->rightRotation();
        else if (this->left->left == NULL) { //Left right rotation
            this->left->leftRotation();
            this->rightRotation();
        } else { //Right rotation with child
            cout << "To Do";
        }
    }

    this->calcFactor();
}

template<class T>
void Node<T>::leftRotation() {
    Node<T>* aux = this->right;
    this->right = aux->left;
    swap(*this, *aux);

    this->left = aux;
    aux->calcFactor();
}

template<class T>
void Node<T>::rightRotation() {
    Node<T>* aux = this->left;
    this->left = aux->right;
    swap(*this, *aux);

    this->right = aux;
    aux->calcFactor();
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
