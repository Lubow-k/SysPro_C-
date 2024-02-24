#include <iostream>
#include <string.h>
#include <stdlib.h>

class TreeNode{
public:
    int value;  
    int height; 
    TreeNode* left;  
    TreeNode* right; 
    
    TreeNode(int val) {
        value = val;
        height = 1;
        left = nullptr;
        right = nullptr;
    }  
};

class AVLTree{
    void inDelete(TreeNode* node) {  
        if (node == nullptr) { return; }
        inDelete(node->right);
        inDelete(node->left);
        delete node;
    }

    int getHeight(TreeNode* node){
        return node == nullptr ? 0 : node->height; 
    }

    int getBalance(TreeNode* node) {
        return getHeight(node->right) - getHeight(node->left);
    }

    int max(int a, int b) {
        return (a > b)? a : b;
    }

    void fixHeight(TreeNode* node) {
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    }

    TreeNode* rotateLeft(TreeNode* root){
        TreeNode* a = root->right;
        root->right = a->left;
        a->left = root;
        fixHeight(root);
        fixHeight(a);
        return a;
    }
    
    TreeNode* rotateRight(TreeNode* root){
        TreeNode* a = root->left;
        root->left = a->right;
        a->right = root;
        fixHeight(root);
        fixHeight(a);
        return a;
    } 

    TreeNode* balance(TreeNode* root) {
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

    TreeNode* findMin(TreeNode* node) {
        return node->left ? findMin(node->left) : node;
    }

    TreeNode* removeMin(TreeNode* node) {
        if (node->left == nullptr) {
            return node->right;
        }
        node->left = removeMin(node->left);
        return balance(node);
    }

    TreeNode* insert(TreeNode* node, int value) {
        if (node == NULL) {
            return new TreeNode(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return balance(node);
    }

    TreeNode* remove(TreeNode* node, int value) {
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

    TreeNode* find(TreeNode* node, int value) {
        if (node == nullptr  || node->value == value)
            return node;
        if (value < node->value) {
            return find(node->left, value);
        } 
        return find(node->right, value);
    }


public:
    TreeNode* root;

    AVLTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void remove(int value) {
        root = remove(root, value);
    }

    TreeNode* find(int value) {
        return find(root, value);
    }

    ~AVLTree() {
        inDelete(root);
    }
};


int main() {
    AVLTree tree;
    tree.insert(5);
    tree.insert(8);

    std::cout << tree.root->value << std::endl;
    std::cout << tree.root->right->value << std::endl;

    std::cout << tree.find(5)->value << std::endl;
    std::cout << tree.find(33) << std::endl;

    return 0;
};
 