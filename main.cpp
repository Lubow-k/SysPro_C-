#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "AVL.h"
#include "lines.cpp"


using namespace std;

int main() {
    // AVLTree tree;
    // tree.insert(5);
    // tree.insert(8);

    // cout << tree.root->value << endl;
    // cout << tree.root->right->value << endl;

    Line* line = new Line{1, 2, 3};
    Line* line_2 = line->perpendicular(Point{-3, 0});
    Point* point = line->intersection(Line{1, 0, 0});

    delete point;
    delete line;
    delete line_2;
    return 0;
};