#include "AVL.h"

AVLTree::Node::Node(int val):
    value(val),
    height(1),
    left(nullptr),
    right(nullptr) {}

void AVLTree::inDelete(AVLTree::Node* node) {  
    if (node == nullptr) { return; }
    inDelete(node->right);
    inDelete(node->left);
    delete node;
}

int AVLTree::getHeight(AVLTree::Node* node){
    return node == nullptr ? 0 : node->height; 
}

int AVLTree::getBalance(AVLTree::Node* node) {
    return getHeight(node->right) - getHeight(node->left);
}

void AVLTree::fixHeight(AVLTree::Node* node) {
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
}

AVLTree::Node* AVLTree::rotateLeft(AVLTree::Node* root){
    AVLTree::Node* a = root->right;
    root->right = a->left;
    a->left = root;
    fixHeight(root);
    fixHeight(a);
    return a;
}

AVLTree::Node* AVLTree::rotateRight(AVLTree::Node* root){
    AVLTree::Node* a = root->left;
    root->left = a->right;
    a->right = root;
    fixHeight(root);
    fixHeight(a);
    return a;
} 

AVLTree::Node* AVLTree::balance(AVLTree::Node* root) {
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

AVLTree::Node* AVLTree::findMin(AVLTree::Node* node) {
    return node->left ? findMin(node->left) : node;
}

AVLTree::Node* AVLTree::removeMin(AVLTree::Node* node) {
    if (node->left == nullptr) {
        return node->right;
    }
    node->left = removeMin(node->left);
    return balance(node);
}

AVLTree::Node* AVLTree::insert(AVLTree::Node* node, int value) {
    if (node == nullptr) {
        return new AVLTree::Node(value);
    }
    if (value < node->value) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }
    return balance(node);
}

AVLTree::Node* AVLTree::remove(AVLTree::Node* node, int value) {
    if (node == nullptr) return node;
    if (value < node->value) {
        node->left = remove(node->left, value);
    } else if (value > node->value) {
        node->right = remove(node->right, value);
    } else {
        AVLTree::Node* l = node->left;
        AVLTree::Node* r = node->right;
        delete node;
        if (!r) return l;
        AVLTree::Node* min = findMin(r);
        min->right = removeMin(r);
        min->left = l;
        return balance(min);
    }
    return balance(node);
}

bool AVLTree::find(AVLTree::Node* node, int value) {
    if (node == nullptr) 
        return false;  
    if (node->value == value)
        return true;
    if (value < node->value) {
        return find(node->left, value);
    } 
    return find(node->right, value);
}

void AVLTree::createNewTree(const AVLTree& other) {
    root = nullptr;
    std::queue<AVLTree::Node *> q;
    if (other.root != nullptr) {
        q.push(other.root);
    }
    while (!q.empty()) { 
        AVLTree::Node* temp = q.front();
        q.pop(); 
        insert(temp->value);
        if (temp->left != nullptr)
            q.push(temp->left);

        if (temp->right != nullptr)
            q.push(temp->right);
    }
}

AVLTree::AVLTree():
        root(nullptr) {}


AVLTree::AVLTree(const AVLTree& other) {
    createNewTree(other);
}

AVLTree& AVLTree::operator=(const AVLTree& other) {
    if (this != &other) {
        inDelete(root);
        createNewTree(other);
    }
    return *this;
}

void AVLTree::insert(int value) {
    root = insert(root, value);
}

void AVLTree::remove(int value) {
    root = remove(root, value);
}

bool AVLTree::find(int value) {
    return find(root, value);
}

bool AVLTree::isBalanced() {
    int b = getBalance(root);
    return -1 <= b && b <= 1;
}

bool AVLTree::isEmpty() {
    return root == nullptr;
}

AVLTree::~AVLTree() {
    inDelete(root);
}



 