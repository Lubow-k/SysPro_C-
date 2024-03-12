#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "AVL.h"
#include "lines.cpp"


using namespace std;

int main() {
    AVLTree tree;
    AVLTree tree_1;
    tree_1.insert(23);
    tree.insert(5);
    tree.insert(8);
    tree_1 = tree;

    // Line line = Line{1, 2, 3};
    // Line line_2 = line.perpendicular(Point{-3, 0});
    // Point* point = line->intersection(Line{1, 0, 0});

    // delete point;
    return 0;
};