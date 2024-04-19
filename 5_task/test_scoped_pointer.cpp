#include <assert.h>
#include <iostream>
#include "scoped_pointer.cpp"


void test_1() {
    // copy_ctr
    ScopedPointer sp_0 = ScopedPointer(new Point{2, 3});
    ScopedPointer sp_1 = sp_0;
    sp_1->x = 9;
    assert(sp_0->x == 2);
    assert(sp_0->y == 3);
    assert(sp_1->x == 9);
    assert(sp_1->y == 3);
    std::cout << "Done #1\n";
}

void test_2() {
    // move_ctr
    ScopedPointer sp_0 = ScopedPointer(new Point{2, 3});
    ScopedPointer sp_1 = std::move(sp_0);
    assert(sp_1->x == 2);
    assert(sp_1->y == 3);
    std::cout << "Done #2\n";
}

void test_3() {
    // move_assignment_operator
    ScopedPointer sp_0 = ScopedPointer(new Point{1, 1});
    ScopedPointer sp_1 = ScopedPointer(new Point{2, 2});
    sp_1 = std::move(sp_0);
    assert(sp_1->x == 1);
    assert(sp_1->y == 1);
    std::cout << "Done #3\n";
}

void test_4() {
    // copy_assignment_operator
    ScopedPointer sp_0 = ScopedPointer(new Point{1, 1});
    ScopedPointer sp_1 = ScopedPointer(new Point{2, 2});
    sp_1 = sp_0;
    assert(sp_1->x == 1);
    assert(sp_1->y == 1);
    std::cout << "Done #4\n";
}

void test_5() {
    // move_ctr_v2
    ScopedPointerV2 sp_0 = ScopedPointerV2(new Point{4, 4});
    ScopedPointerV2 sp_1= std::move(sp_0);
    assert(sp_1->x == 4);
    assert(sp_1->y == 4);
    std::cout << "Done #5\n";
}

void test_6() {
    // move_assignment_operator_v2
    ScopedPointerV2 sp_0 = ScopedPointerV2(new Point{5, 4});
    ScopedPointerV2 sp_1 = ScopedPointerV2(new Point{2, 2});
    sp_1 = std::move(sp_0);
    assert(sp_1->x == 5);
    assert(sp_1->y == 4);
    assert(sp_0.get() == std::nullopt);
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
