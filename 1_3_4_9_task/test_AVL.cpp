#include <assert.h>
#include <iostream>
#include "AVL.cpp"
#include <string>



void test_1() {
    AVLTree<double> tree;
    assert(tree.isEmpty());
    std::cout << "Done #1\n";
}

void test_2() {
    AVLTree<int> tree;
    tree.insert(7);
    tree.insert(8);
    tree.insert(9);
    tree.insert(10);
    tree.insert(11);
    tree.insert(12);
    assert(tree.isBalanced());
    std::cout << "Done #2\n";
}


void test_3() {
    AVLTree<float> tree;
    tree.insert(7.9);
    tree.insert(8.2);
    tree.insert(9.1);
    tree.insert(10.0);
    tree.insert(1.3);
    tree.insert(12.5);
    assert(tree.isBalanced());
    tree.remove(10.0);
    assert(tree.isBalanced());
    std::cout << "Done #3\n";
}

void test_4() {
    AVLTree<int> tree;
    int a = 10;
    tree.insert(a);
    tree.insert(8);
    tree.insert(9);
    tree.insert(7);
    assert(tree.find(a));
    std::cout << "Done #4\n";
}

void test_5() {
    AVLTree<std::string> tree;
    tree.insert("cool");
    tree.insert("lgtm");
    AVLTree tree_1(tree);
    tree_1.insert("wow");

    assert(!tree.find("wow"));
    assert(tree_1.find("wow"));
    std::cout << "Done #5\n";
}

void test_6() {
    AVLTree<char> tree;
    tree.insert('A');
    tree.insert('B');
    AVLTree<char> tree_1;
    tree_1.insert('C');
    tree_1 = std::move(tree);
    assert(tree_1.find('B'));
    assert(!tree_1.find('C'));
    std::cout << "Done #6\n";
}


void test_7() {
    AVLTree<int> tree;
    tree.insert(4);
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(6);
    tree.insert(5);

    std::vector<int> exp(6);
    std::vector<int> real;
    std::generate(exp.begin(), exp.end(), [n = 1] () mutable {return n++;});

    for (auto& node: tree) {
        real.push_back(node.value);
    }
    assert(exp == real);
    std::cout << "Done #7\n";
}

void test_8() {
    AVLTree<char> tree;
    tree.insert('B');
    tree.insert('A');
    tree.insert('C');

    std::vector<char> exp(3);
    std::vector<char> real_1;
    std::vector<char> real_2;
    std::generate(exp.begin(), exp.end(), [n = 'A'] () mutable {return n++;});

    auto it = tree.begin();
    auto end = tree.end();

    for (; it != end; ++it) {
        real_1.push_back(it->value);
    }

    it = tree.begin();
    for (; it != end; it++) {
        real_2.push_back(it->value);
    }

    assert(exp == real_1);
    assert(exp == real_2);
    std::cout << "Done #8\n";
}





int main() {
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
    test_7();
    test_8();
    std::cout << "all tests passed\n";
}