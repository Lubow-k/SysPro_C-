#include <iostream>
#include "7_task/expressions.hpp"

int main() {
    // Expression* e = new Add(new Var("y"), new Val(10));
    // std::string res = e->print();
    // std::cout << res << std::endl;

    // Expression* t = e->diff("y");
    // res = t->print();
    // std::cout << res << std::endl;

    // Expression* e = new Add(new Var("x"), new Mult(new Val(10), new Var("y")));
    Expression* e = new Exponent(new Sub(new Val(10), new Val(90)));

    std::string res = e->print();
    std::cout << res << std::endl;

    Expression* res1 = e->diff("x");
    res = res1->print();
    std::cout << res << std::endl;

    Expression* res2 = e->diff("y");
    res = res2->print();
    std::cout << res << std::endl;

    delete e;
    delete res1;
    delete res2;
    return 0;
};