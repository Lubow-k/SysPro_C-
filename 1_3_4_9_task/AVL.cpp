#include "AVL.hpp"
#include <iostream>


template <typename T>
AVLTree<T>::Iterator& AVLTree<T>::Iterator::operator++() {
    AVLTree<T>::Node* p;
    if (current->right != nullptr) {
        current = current->right;
        current = findMin(current);
    } else {
        p = current->parent;
        while (p != nullptr && current == p->right) {
            current = p;
            p = p->parent;
        }
        current = p;
    }
    return *this;
}


template <typename T>
AVLTree<T>::Iterator AVLTree<T>::Iterator::operator++(int) {
    auto it = *this;
    ++*this;
    return it;
}


template <typename T>
AVLTree<T>::Node::Node(T val_, AVLTree<T>::Node* parent_):
    value(val_),
    height(1),
    parent(parent_),
    left(nullptr),
    right(nullptr) {}


template <typename T>
void AVLTree<T>::inDelete(AVLTree<T>::Node* node) {  
    if (node == nullptr) { return; }
    inDelete(node->right);
    inDelete(node->left);
    delete node;
}

template <typename T>
int AVLTree<T>::getHeight(AVLTree<T>::Node* node){
    return node == nullptr ? 0 : node->height; 
}

template <typename T>
int AVLTree<T>::getBalance(AVLTree<T>::Node* node) {
    return getHeight(node->right) - getHeight(node->left);
}

template <typename T>
void AVLTree<T>::fixHeight(AVLTree<T>::Node* node) {
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
}

template <typename T>
AVLTree<T>::Node* AVLTree<T>::rotateLeft(AVLTree<T>::Node* root){
    AVLTree<T>::Node* a = root->right;
    root->right = a->left;
    if (a->left != nullptr) {
        a->left->parent = root;
    }
    a->left = root;
    a->parent = root->parent;
    root->parent = a;
    fixHeight(root);
    fixHeight(a);
    return a;
}

template <typename T>
AVLTree<T>::Node* AVLTree<T>::rotateRight(AVLTree<T>::Node* root){
    AVLTree<T>::Node* a = root->left;
    root->left = a->right;
    if (a->right != nullptr) {
        a->right->parent = root;
    }
    a->right = root;
    a->parent = root->parent;
    root->parent = a;
    fixHeight(root);
    fixHeight(a);
    return a;
} 


template <typename T>
AVLTree<T>::Node* AVLTree<T>::balance(AVLTree<T>::Node* root) {
    fixHeight(root);
    int height_difference = getBalance(root);
    if (height_difference >= 2) {
        if (getBalance(root->right) <= -1) {
            root->right = rotateRight(root->right);
        }
        return rotateLeft(root);
    } else if (height_difference <= -2) {
        if (getBalance(root->left) >= 1) {
            root->left = rotateLeft(root->left);
        }
        return rotateRight(root);
    }
    return root;
}

template <typename T>
AVLTree<T>::Node* AVLTree<T>::findMin(AVLTree<T>::Node* node) {
    return node->left ? findMin(node->left) : node;
}

template <typename T>
AVLTree<T>::Node* AVLTree<T>::removeMin(AVLTree<T>::Node* node) {
    if (node->left == nullptr) {
        return node->right;
    }
    node->left = removeMin(node->left);
    return balance(node);
}

template <typename T>
AVLTree<T>::Node* AVLTree<T>::insert(AVLTree<T>::Node* node, AVLTree<T>::Node* parent, T value) {
    if (node == nullptr) {
        return new AVLTree<T>::Node(value, parent);
    }
    if (value < node->value) {
        node->left = insert(node->left, node, value);
    } else {
        node->right = insert(node->right, node, value);
    }
    return balance(node);
}

template <typename T>
AVLTree<T>::Node* AVLTree<T>::remove(AVLTree<T>::Node* node, T value) {
    if (node == nullptr) return node;
    if (value < node->value) {
        node->left = remove(node->left, value);
    } else if (value > node->value) {
        node->right = remove(node->right, value);
    } else {
        AVLTree<T>::Node* l = node->left;
        AVLTree<T>::Node* r = node->right;
        delete node;
        if (!r) return l;
        AVLTree<T>::Node* min = findMin(r);
        min->right = removeMin(r);
        min->left = l;
        return balance(min);
    }
    return balance(node);
}

template <typename T>
bool AVLTree<T>::find(AVLTree<T>::Node* node, T value) {
    if (node == nullptr) 
        return false;  
    if (node->value == value)
        return true;
    if (value < node->value) {
        return find(node->left, value);
    } 
    return find(node->right, value);
}

template <typename T>
void AVLTree<T>::createNewTree(const AVLTree<T>& other) {
    root = nullptr;
    std::queue<AVLTree<T>::Node *> q;
    if (other.root != nullptr) {
        q.push(other.root);
    }
    while (!q.empty()) { 
        AVLTree<T>::Node* temp = q.front();
        q.pop(); 
        insert(temp->value);
        if (temp->left != nullptr)
            q.push(temp->left);

        if (temp->right != nullptr)
            q.push(temp->right);
    }
}

template <typename T>
AVLTree<T>::AVLTree():
        root(nullptr) {}


template <typename T>
AVLTree<T>::AVLTree(const AVLTree<T>& other) {    // copy constructor 
    createNewTree(other);
}

template <typename T>
AVLTree<T>::AVLTree(AVLTree<T>&& other) {         // move constructor 
    root = other.root;
    other.root = nullptr;
}

template <typename T>
AVLTree<T>& AVLTree<T>::operator=(AVLTree<T> other) {   // copy and swap 
    std::swap(root, other.root);
    return *this;
}

template <typename T>
void AVLTree<T>::insert(T value) {
    root = insert(root, nullptr, value);
}

template <typename T>
void AVLTree<T>::remove(T value) {
    root = remove(root, value);
}

template <typename T>
bool AVLTree<T>::find(T value) {
    return find(root, value);
}

template <typename T>
bool AVLTree<T>::isBalanced() {
    int b = getBalance(root);
    return -1 <= b && b <= 1;
}

template <typename T>
bool AVLTree<T>::isEmpty() {
    return root == nullptr;
}

template <typename T>
AVLTree<T>::~AVLTree() {
    inDelete(root);
}



 