#include <iostream>
#include "mix_in.hpp"


class Foo: public Counter<Foo, 3> {};

void test_1() {
    try {
        Foo ob_1;
        Foo ob_2;
        Foo ob_3;
    } catch(const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return;
    }
    std::cout << "Success" << std::endl;
}


void test_2() {
    try {
        Foo ob_1;
        Foo ob_2;
        Foo ob_3;
        Foo ob_4;
    } catch(const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return;
    }
    std::cout << "Success" << std::endl;
}

void test_3() {
    try {
        Foo ob_1;
        Foo ob_2;
        Foo ob_0;
        Foo ob_3(ob_2);
    } catch(const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return;
    }
    std::cout << "Success" << std::endl;
}

int main() {
    test_1();
    test_2();
    test_3();
    return 0;
}