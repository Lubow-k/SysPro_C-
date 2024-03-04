#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "AVL.cpp"

using namespace std;

TEST(UnitTest, start_empty) {
    AVLTree tree;
    ASSERT_TRUE(tree.root == nullptr);
}

TEST(UnitTest, correct_insert) {
    AVLTree tree;
    tree.insert(7);
    tree.insert(8);
    tree.insert(9);
    tree.insert(10);
    tree.insert(11);
    tree.insert(12);
    ASSERT_TRUE(tree.isBalanced());
    ASSERT_TRUE(tree.root->value == 10);
}

TEST(UnitTest, correct_remove) {
    AVLTree tree;
    tree.insert(7);
    tree.insert(8);
    tree.insert(9);
    tree.insert(10);
    tree.insert(11);
    tree.insert(12);
    ASSERT_TRUE(tree.isBalanced());
    tree.remove(10);
    ASSERT_TRUE(tree.isBalanced());
}

TEST(UnitTest, correct_find) {
    AVLTree tree;
    int a = 10;
    tree.insert(7);
    tree.insert(8);
    tree.insert(9);
    tree.insert(10);
    TreeNode* node = tree.find(a);
    ASSERT_TRUE(node->value == a);
}


TEST(UnitTest, find_not_exist_elem) {
    AVLTree tree;
    int a = 11;
    tree.insert(7);
    tree.insert(8);
    tree.insert(9);
    tree.insert(10);
    TreeNode* node = tree.find(a);
    ASSERT_TRUE(node == nullptr);
}


TEST(UnitTest, remove_not_exist_elem) {
    AVLTree tree;
    tree.insert(7);
    tree.remove(8);
    ASSERT_TRUE(tree.root->value == 7);
}

TEST(UnitTest, copy_constructor_diff_tree) {
    AVLTree tree;
    tree.insert(7);
    tree.insert(8);
    AVLTree tree_1(tree);
    tree_1.insert(9);

    TreeNode* node = tree.find(9);
    ASSERT_TRUE(node == nullptr);

    node = tree_1.find(9);
    ASSERT_TRUE(node->value == 9);
}


TEST(UnitTest, copy_assignment_operator_diff_tree) {
    AVLTree tree;
    tree.insert(7);
    tree.insert(8);
    AVLTree tree_1 = tree;
    tree_1.insert(9);

    TreeNode* node = tree.find(7);
    ASSERT_TRUE(node->value == 7);

    node = tree.find(9);
    ASSERT_TRUE(node == nullptr);

    node = tree_1.find(7);
    ASSERT_TRUE(node->value == 7);

    node = tree_1.find(9);
    ASSERT_TRUE(node->value == 9);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}