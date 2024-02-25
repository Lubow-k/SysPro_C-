#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "AVL.h"


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