#include <assert.h>
#include <iostream>
#include "matrix.hpp"


void test_1() {
    std::vector<double> c = {2, 3, 4};
    Matrix m(c);
    assert(m[0][0] == 2);
    assert(m[0][1] == 0);
    assert(m[2][2] == 4);
    std::cout << "Done #1\n";
}

void test_2() {
    // add_matrix
    std::vector<double> c = {1, 1, 1};
    Matrix m(3);
    Matrix w(c);
    m += c;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) {
                assert(m[i][i] == 1);
            } else {
                assert(m[0][1] == 0);
            }
        }
    }
    std::cout << "Done #2\n";
}

void test_3() {
    // add_double
    std::vector<double> c = {8, 8, 8};
    Matrix w(c);
    Matrix m = w + (-1);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) {
                assert(m[i][i] == 7);
            } else {
                assert(m[0][1] == 0);
            }
        }
    }
    std::cout << "Done #3\n";
}

void test_4() {
    // mult_double
    std::vector<double> c = {1, 1, 1};
    Matrix m(c);
    m *= 2;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) {
                assert(m[i][i] == 2);
            } else {
                assert(m[0][1] == 0);
            }
        }
    }
    std::cout << "Done #4\n";
}

void test_5() {
    // mult_matrix
    /*  12   *  10   =   14     */
    /*  00      02       00     */
    Matrix m(2);
    m[0][0] = 1;
    m[0][1] = 2;

    Matrix w(2);
    w[0][0] = 1;
    w[1][1] = 2;

    Matrix x = m * w;
    assert(x[0][0] == 1);
    assert(x[0][1] == 4);
    assert(x[1][0] == 0);
    assert(x[1][1] == 0);
    std::cout << "Done #5\n";
}

void test_6() {
    // eq 
    std::vector<double> c = {1, 1, 1};
    Matrix m(c);
    Matrix w(c);
    assert(m == w);
    std::cout << "Done #6\n";
}

void test_7() {
    // cast
    std::vector<double> c = {3, 3, 12};
    Matrix m(c);
    m[0][1] = 9;
    assert(static_cast<double>(m) == 27);
    std::cout << "Done #7\n";
}

void test_8() {
    // operator[][] out of range
    std::vector<double> c = {1, 2, 3};
    Matrix m(c);
    try {
      m[4][4] = 9;
    } catch (std::out_of_range e) {
        std::string message = "Row: 4, col: 4, matrix len: 3";
        assert(message == std::string(e.what()));
    }
    std::cout << "Done #8\n";
}

void test_9() {
    // A = num * B;
    std::vector<double> c = {1, 1, 1};
    Matrix b(c);
    Matrix a = 3 * b;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) {
                assert(a[i][i] == 3);
            } else {
                assert(a[0][1] == 0);
            }
        }
    }
    std::cout << "Done #9\n";
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
    test_9();
    std::cout << "all tests passed\n";
}
