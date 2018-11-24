template <class T>
Node<T>::Node(T info) {
  this->info = info;
  this->left = NULL;
  this->right = NULL;

  this->factor = 0;
}

template <class T>
void Node<T>::add(T info) {
  if (this->info > info)
    if (this->left != NULL)
      this->left->add(info);
    else
      this->left = new Node<T>(info);
  else if (this->right != NULL)
    this->right->add(info);
  else
    this->right = new Node<T>(info);

  this->calcFactor();
  if (abs(this->factor) > 1)
    this->balance();
}

template <class T>
void Node<T>::remove(T info) {
  if (info == this->info) {
    if (this->left == NULL && this->right == NULL)
      this->info = NULL;
    else if (this->right != NULL) {
      T minInfo = this->right->getMin();
      this->right->remove(minInfo);

      if (this->right->info == NULL) {
        delete this->right;
        this->right = NULL;
      }

      this->info = minInfo;
    } else {
      T maxInfo = this->left->getMax();
      this->left->remove(maxInfo);

      if (this->left->info == NULL) {
        delete this->left;
        this->left = NULL;
      }

      this->info = maxInfo;
    }
  } else if (info < this->info && this->left != NULL) {
    this->left->remove(info);

    if (this->left->info == NULL) {
      delete this->left;
      this->left = NULL;
    }
  } else if (info > this->info && this->right != NULL) {
    this->right->remove(info);

    if (this->right->info == NULL) {
      delete this->right;
      this->right = NULL;
    }
  }

  this->calcFactor();
  if (abs(this->factor) > 1)
    this->balance();
}

template <class T>
T* Node<T>::get(T desiredInfo) {
  if (desiredInfo == this->info)
    return &this->info;
  else if (desiredInfo < this->info && this->left != NULL)
    return this->left->get(desiredInfo);
  else if (desiredInfo > this->info && this->right != NULL)
    return this->right->get(desiredInfo);
  else
    return NULL;
}

template <class T>
T Node<T>::getMin() {
  if (this->left != NULL)
    return this->left->getMin();
  else
    return this->info;
}

template <class T>
T Node<T>::getMax() {
  if (this->right != NULL)
    return this->right->getMax();
  else
    return this->info;
}

template <class T>
void Node<T>::balance() {
  if (this->factor > 1) {
    if (this->right->right != NULL)  // Left rotation and Left rotation with child
      this->leftRotation();
    else {  // Right left rotation
      this->right->rightRotation();
      this->leftRotation();
    }
  } else if (this->factor < -1) {
    if (this->left->left != NULL)  // Right rotation and Right rotation with child
      this->rightRotation();
    else {  // Left right rotation
      this->left->leftRotation();
      this->rightRotation();
    }
  }

  this->calcFactor();
}

template <class T>
void Node<T>::leftRotation() {
  Node<T>* aux = this->right;
  this->right = aux->left;
  swap(*this, *aux);

  this->left = aux;
  aux->calcFactor();
}

template <class T>
void Node<T>::rightRotation() {
  Node<T>* aux = this->left;
  this->left = aux->right;
  swap(*this, *aux);

  this->right = aux;
  aux->calcFactor();
}

template <class T>
void Node<T>::calcFactor() {
  int left = 0;
  if (this->left != NULL)
    left = this->left->maxHeight(0);

  int right = 0;
  if (this->right != NULL)
    right = this->right->maxHeight(0);

  this->factor = right - left;
}

template <class T>
int Node<T>::maxHeight(int motherHeight) {
  int actualHeight = motherHeight + 1, mHeight = actualHeight;
  if (this->left != NULL) {
    int leftHeight = this->left->maxHeight(actualHeight);
    if (leftHeight > mHeight) mHeight = leftHeight;
  }

  if (this->right != NULL) {
    int rightHeight = this->right->maxHeight(actualHeight);
    if (rightHeight > mHeight) mHeight = rightHeight;
  }

  return mHeight;
}

template <class T>
bool Node<T>::isEmpty() {
  return this->info == NULL;
}

template <class T>
ostream& operator<<(ostream& os, const Node<T>& node) {
  os << "(";
  if (node.left != NULL)
    os << *node.left;

  os << "{ " << node.info << ", " << node.factor << " }";

  if (node.right != NULL)
    os << *node.right;
  os << ")";

  return os;
}
