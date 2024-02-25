#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "AVL.cpp"

using namespace std;

TEST(UnitTest, correct_insert) {
    AVLTree tree;
    tree.insert(5);
    tree.insert(8);
    tree.insert(9);
    ASSERT_TRUE(tree.root->value == 8);
}

TEST(UnitTest, correct_remove) {
    AVLTree tree;
    tree.insert(5);
    tree.insert(8);
    tree.insert(9);
    ASSERT_TRUE(tree.root->value == 8);
    ASSERT_TRUE(tree.root->right->value == 9);
    ASSERT_TRUE(tree.root->left->value == 5);
    tree.remove(8);
    ASSERT_TRUE(tree.root->value == 9);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}