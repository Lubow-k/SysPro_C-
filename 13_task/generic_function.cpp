#include <string>
#include <vector>
#include <cassert>


template <typename Checker, typename... Args>
int getIndexOfFirstMatch(Checker check, Args&&... args) {
    int result = 0, i = 0;
    bool found = ((check(std::forward<Args>(args)) ? (result = i, true) : (i++, false)) || ...);
    return found ? result : -1;
}


void test_1() {
    auto isEven = [](int n) { return n % 2 == 0; };
    int res = getIndexOfFirstMatch(isEven, 1, 3, 4, 5);
    assert(res == 2);
}

void test_2() {
    auto isEven = [](int n) { return n % 2 == 0; };
    int res = getIndexOfFirstMatch(isEven, 1, 3, 9, 5);
    assert(res == -1);
}

void test_3() {
    auto isPositive = [](float n) { return n > 0; };
    int res = getIndexOfFirstMatch(isPositive, -1.9, -1.8, 0, 5);
    assert(res == 3);
}

void test_4() {
    auto longerThanFive = [](std::string str) { return str.size() > 5; };
    int res = getIndexOfFirstMatch(longerThanFive, "NSU", "SysPro");
    assert(res == 1);
}

void test_5() {
    auto longerThanFive = [](std::vector<char> v) { return v.size() > 5; };
    std::vector<char> v_1 = {'A', 'B', 'C', 'D', 'E', 'F'};
    std::vector<char> v_2 = {'A'};
    int res = getIndexOfFirstMatch(longerThanFive, v_1, v_2);
    assert(res == 0);
}


int main() { 
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
}

