#include <queue>

class AVLTree {
    struct Node {
        int value;  
        int height; 
        Node* left;  
        Node* right; 
        Node(int val); 
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
    static Node* insert(Node* node, int value);
    static Node* remove(Node* node, int value);
    static bool find(Node* node, int value);
  
public:
    AVLTree();
    AVLTree(const AVLTree& other);
    AVLTree(AVLTree&& other);
    AVLTree& operator=(AVLTree other);
    void insert(int value);
    void remove(int value);
    bool find(int value);
    bool isBalanced();
    bool isEmpty();
    ~AVLTree();
};
