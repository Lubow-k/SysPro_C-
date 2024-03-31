#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <optional>
#include "scoped_pointer.cpp"

using namespace std;

TEST(UnitTest, copy_ctr) {
    ScopedPointer sp_0 = ScopedPointer(new Point{2, 3});
    ScopedPointer sp_1 = sp_0;
    sp_1->x = 9;
    ASSERT_TRUE(sp_0->x == 2);
    ASSERT_TRUE(sp_0->y == 3);
    ASSERT_TRUE(sp_1->x == 9);
    ASSERT_TRUE(sp_1->y == 3);
}

TEST(UnitTest, move_ctr) {
    ScopedPointer sp_0 = ScopedPointer(new Point{2, 3});
    ScopedPointer sp_1 = std::move(sp_0);
    ASSERT_TRUE(sp_1->x == 2);
    ASSERT_TRUE(sp_1->y == 3);
}


TEST(UnitTest, move_assignment_operator) {
    ScopedPointer sp_0 = ScopedPointer(new Point{1, 1});
    ScopedPointer sp_1 = ScopedPointer(new Point{2, 2});
    sp_1 = std::move(sp_0);
    ASSERT_TRUE(sp_1->x == 1);
    ASSERT_TRUE(sp_1->y == 1);
}

TEST(UnitTest, copy_assignment_operator) {
    ScopedPointer sp_0 = ScopedPointer(new Point{1, 1});
    ScopedPointer sp_1 = ScopedPointer(new Point{2, 2});
    sp_1 = sp_0;
    ASSERT_TRUE(sp_1->x == 1);
    ASSERT_TRUE(sp_1->y == 1);
}

TEST(UnitTest, move_ctr_v2) {
    ScopedPointerV2 sp_0 = ScopedPointerV2(new Point{4, 4});
    ScopedPointerV2 sp_1= std::move(sp_0);
    ASSERT_TRUE(sp_1->x == 4);
    ASSERT_TRUE(sp_1->y == 4);
}

TEST(UnitTest, move_assignment_operator_v2) {
    ScopedPointerV2 sp_0 = ScopedPointerV2(new Point{5, 4});
    ScopedPointerV2 sp_1 = ScopedPointerV2(new Point{2, 2});
    sp_1 = std::move(sp_0);
    ASSERT_TRUE(sp_1->x == 5);
    ASSERT_TRUE(sp_1->y == 4);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}