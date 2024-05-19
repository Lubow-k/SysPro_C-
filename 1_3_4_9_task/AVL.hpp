#pragma once
#include <queue>

template <typename T>
class AVLTree {
    struct Node {
        T value;  
        int height; 
        Node* parent;
        Node* left;  
        Node* right; 
        Node(T, Node*); 
    };
    Node* root;
    void createNewTree(const AVLTree& other);
    void inDelete(Node* node);
    static int getHeight(Node* node);
    static int getBalance(Node* node);
    static void fixHeight(Node* node);
    static Node* rotateLeft(Node* root);
    static Node* rotateRight(Node* root);
    static Node* balance(Node* root);
    static Node* findMin(Node* node);
    static Node* removeMin(Node* node);
    static Node* insert(Node* node, Node* parent, T value);
    static Node* remove(Node* node, T value);
    static bool find(Node* node, T value);
  
public:
    AVLTree();
    AVLTree(const AVLTree& other);
    AVLTree(AVLTree&& other);
    AVLTree& operator=(AVLTree other);
    void insert(T value);
    void remove(T value);
    bool find(T value);
    bool isBalanced();
    bool isEmpty();
    ~AVLTree();
    class Iterator {
        Node* current;
      public:
        Iterator(Node* node) { current = node; }

        Iterator& operator++();
        Iterator operator++(int);
        
        T& operator*() { return current->value; }
        
        Node* operator->() { return current; }
        const Node* operator->() const { return current; }
        
        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this==other);
        } 
    };

    Iterator begin() { return Iterator(findMin(AVLTree<T>::root)); }
    Iterator end() { return Iterator(nullptr); }
};
