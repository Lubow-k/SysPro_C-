#include "AVL.h"
#include <queue>

TreeNode::TreeNode(int val):
    value(val),
    height(1),
    left(nullptr),
    right(nullptr) {}

void AVLTree::inDelete(TreeNode* node) {  
    if (node == nullptr) { return; }
    inDelete(node->right);
    inDelete(node->left);
    delete node;
}

int AVLTree::getHeight(TreeNode* node){
    return node == nullptr ? 0 : node->height; 
}

int AVLTree::getBalance(TreeNode* node) {
    return getHeight(node->right) - getHeight(node->left);
}

int AVLTree::max(int a, int b) {
    return (a > b)? a : b;
}

void AVLTree::fixHeight(TreeNode* node) {
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

}

TreeNode* AVLTree::rotateLeft(TreeNode* root){
    TreeNode* a = root->right;
    root->right = a->left;
    a->left = root;
    fixHeight(root);
    fixHeight(a);
    return a;
}

TreeNode* AVLTree::rotateRight(TreeNode* root){
    TreeNode* a = root->left;
    root->left = a->right;
    a->right = root;
    fixHeight(root);
    fixHeight(a);
    return a;
} 

TreeNode* AVLTree::balance(TreeNode* root) {
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

TreeNode* AVLTree::findMin(TreeNode* node) {
    return node->left ? findMin(node->left) : node;
}

TreeNode* AVLTree::removeMin(TreeNode* node) {
    if (node->left == nullptr) {
        return node->right;
    }
    node->left = removeMin(node->left);
    return balance(node);
}

TreeNode* AVLTree::insert(TreeNode* node, int value) {
    if (node == nullptr) {
        return new TreeNode(value);
    }
    if (value < node->value) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }
    return balance(node);
}

TreeNode* AVLTree::remove(TreeNode* node, int value) {
    if (node == nullptr) return node;
    if (value < node->value) {
        node->left = remove(node->left, value);
    } else if (value > node->value) {
        node->right = remove(node->right, value);
    } else {
        TreeNode* l = node->left;
        TreeNode* r = node->right;
        delete node;
        if (!r) return l;
        TreeNode* min = findMin(r);
        min->right = removeMin(r);
        min->left = l;
        return balance(min);
    }
    return balance(node);
}

TreeNode* AVLTree::find(TreeNode* node, int value) {
    if (node == nullptr  || node->value == value)
        return node;
    if (value < node->value) {
        return find(node->left, value);
    } 
    return find(node->right, value);
}

void AVLTree::createNewTree(const AVLTree& other) {
    root = nullptr;
    std::queue<TreeNode *> q;
    if (other.root != nullptr) {
        q.push(other.root);
    }
    while (!q.empty()) { 
        TreeNode* temp = q.front();
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
    inDelete(root);
    createNewTree(other);
    return *this;
}

void AVLTree::insert(int value) {
    root = insert(root, value);
}

void AVLTree::remove(int value) {
    root = remove(root, value);
}

TreeNode* AVLTree::find(int value) {
    return find(root, value);
}

bool AVLTree::isBalanced() {
    int b = getBalance(root);
    return -1 <= b && b <= 1;
}

AVLTree::~AVLTree() {
    inDelete(root);
}



 