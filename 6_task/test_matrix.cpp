#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "matrix.hpp"

TEST(UnitTest, check_1) {
    std::vector<double> c = {2, 3, 4};
    Matrix m(c);
    ASSERT_TRUE(m[0][0] == 2);
    ASSERT_TRUE(m[0][1] == 0);
    ASSERT_TRUE(m[2][2] == 4);
}

TEST(UnitTest, add_matrix) {
    std::vector<double> c = {1, 1, 1};
    Matrix m(3);
    Matrix w(c);
    m += c;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) {
                ASSERT_TRUE(m[i][i] == 1);
            } else {
                ASSERT_TRUE(m[0][1] == 0);
            }
        }
    }
}


TEST(UnitTest, add_double) {
    std::vector<double> c = {8, 8, 8};
    Matrix w(c);
    Matrix m = w + (-1);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) {
                ASSERT_TRUE(m[i][i] == 7);
            } else {
                ASSERT_TRUE(m[0][1] == 0);
            }
        }
    }
}


TEST(UnitTest, mult_double) {
    std::vector<double> c = {1, 1, 1};
    Matrix m(c);
    m *= 2;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) {
                ASSERT_TRUE(m[i][i] == 2);
            } else {
                ASSERT_TRUE(m[0][1] == 0);
            }
        }
    }
}

TEST(UnitTest, mult_matrix) {
    /*  12   *  10   =   14     */
    /*  00      02       00     */
    Matrix m(2);
    m[0][0] = 1;
    m[0][1] = 2;

    Matrix w(2);
    w[0][0] = 1;
    w[1][1] = 2;

    Matrix x = m * w;
    ASSERT_TRUE(x[0][0] == 1);
    ASSERT_TRUE(x[0][1] == 4);
    ASSERT_TRUE(x[1][0] == 0);
    ASSERT_TRUE(x[1][1] == 0);
}


TEST(UnitTest, eq) {
    std::vector<double> c = {1, 1, 1};
    Matrix m(c);
    Matrix w(c);
    ASSERT_TRUE(m == w);
}

TEST(UnitTest, cast) {
    std::vector<double> c = {3, 3, 12};
    Matrix m(c);
    m[0][1] = 9;
    ASSERT_TRUE(static_cast<double>(m) == 27);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}