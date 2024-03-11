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
    Node* rotateLeft(Node* root);
    Node* rotateRight(Node* root);
    Node* balance(Node* root);
    Node* findMin(Node* node);
    Node* removeMin(Node* node);
    Node* insert(Node* node, int value);
    Node* remove(Node* node, int value);
    bool find(Node* node, int value);
  
public:
    AVLTree();
    AVLTree(const AVLTree& other);
    AVLTree& operator=(const AVLTree& other);
    void insert(int value);
    void remove(int value);
    bool find(int value);
    bool isBalanced();
    bool isEmpty();
    ~AVLTree();
};
