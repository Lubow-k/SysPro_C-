#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "AVL.h"


using namespace std;

int main() {
    AVLTree tree;
    tree.insert(5);
    tree.insert(8);

    cout << tree.root->value << endl;
    cout << tree.root->right->value << endl;

    return 0;
};