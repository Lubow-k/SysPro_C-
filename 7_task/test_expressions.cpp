#include <assert.h>
#include <iostream>
#include "expressions.hpp"


void test_1() {
    // from presentation
    Expression* e = new Add(new Var("x"), new Mult(new Val(10), new Var("y")));
    assert(static_cast<std::string>(*e)== "(x + (10 * y))");
    Expression* res1 = e->diff("x");
    assert(static_cast<std::string>(*res1) == "(1 + ((0 * y) + (10 * 0)))");
    Expression* res2 = e->diff("y");
    assert(static_cast<std::string>(*res2) == "(0 + ((0 * y) + (10 * 1)))");
    delete e;
    delete res1;
    delete res2;
    std::cout << "Done #1\n";
}

void test_2() {
    // print exponent
    Expression* e = new Exponent(new Sub(new Val(10), new Val(90)));
    assert(static_cast<std::string>(*e) == "e^(10 - 90)");
    delete e;
    std::cout << "Done #2\n";
}

void test_3() {
    // diff exponent
    Expression* e = new Exponent(new Var("x"));
    assert(static_cast<std::string>(*e) == "e^x");
    Expression* res1 = e->diff("x");
    assert(static_cast<std::string>(*res1) == "(1 * e^x)");
    Expression* res2 = e->diff("y");
    assert(static_cast<std::string>(*res2) == "(0 * e^x)");
    delete e;
    delete res1;
    delete res2;
    std::cout << "Done #3\n";
}

void test_4() {
    // polynomial
    Expression* e = new Add(new Mult(new Var("x"), new Var("x")), new Mult(new Val(5), new Var("x")));
    assert(static_cast<std::string>(*e) == "((x * x) + (5 * x))");
    Expression* res1 = e->diff("x");
    assert(static_cast<std::string>(*res1) == "(((1 * x) + (x * 1)) + ((0 * x) + (5 * 1)))");
    delete e;
    delete res1;
    std::cout << "Done #4\n";
}

void test_5() {
    // diff division
    Expression* e = new Div(new Var("x"), new Var("y"));
    assert(static_cast<std::string>(*e) == "(x / y)");
    Expression* res1 = e->diff("x");
    assert(static_cast<std::string>(*res1) == "(((1 * y) - (x * 0)) / (y * y))");
    delete e;
    delete res1;
    std::cout << "Done #5\n";
}

void test_6() {
    // diff not exist var 
    Expression* e = new Add(new Var("x"), new Var("z"));
    Expression* res1 = e->diff("y");
    assert(static_cast<std::string>(*res1) == "(0 + 0)");
    delete e;
    delete res1;
    std::cout << "Done #6\n";
}


int main() {
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
    std::cout << "all tests passed\n";
}
