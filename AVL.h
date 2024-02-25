class TreeNode{
public:
    int value;  
    int height; 
    TreeNode* left;  
    TreeNode* right; 

    TreeNode(int val); 
};


class AVLTree {
    void inDelete(TreeNode* node);
    int getHeight(TreeNode* node);
    int getBalance(TreeNode* node);
    int max(int a, int b);
    void fixHeight(TreeNode* node);
    TreeNode* rotateLeft(TreeNode* root);
    TreeNode* rotateRight(TreeNode* root);
    TreeNode* balance(TreeNode* root);
    TreeNode* findMin(TreeNode* node);
    TreeNode* removeMin(TreeNode* node);
    TreeNode* insert(TreeNode* node, int value);
    TreeNode* remove(TreeNode* node, int value);
    TreeNode* find(TreeNode* node, int value);
  
public:
    TreeNode* root;
    AVLTree();
    void insert(int value);
    void remove(int value);
    TreeNode* find(int value);
    bool isBalanced();
    ~AVLTree();
};
