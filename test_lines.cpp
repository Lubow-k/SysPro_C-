#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "lines.cpp"

using namespace std;

TEST(UnitTest, perpendicular) {
    Line* line = new Line{1, 2, 3};
    Line* line_2 = line->perpendicular(Point{-3, 0});
    ASSERT_TRUE(line_2->A == -2);
    ASSERT_TRUE(line_2->B == 1);
    ASSERT_TRUE(line_2->C == -6);
    delete line;
    delete line_2;
}

TEST(UnitTest, perpendicular_2) {
    Line* line = new Line{0, 1, 0};
    Line* line_2 = line->perpendicular(Point{0, 0});
    ASSERT_TRUE(line_2->A == -1);
    ASSERT_TRUE(line_2->B == 0);
    ASSERT_TRUE(line_2->C == 0);
    delete line;
    delete line_2;
}

TEST(UnitTest, intersection) {
    Line* line = new Line{1, 2, 3};
    Point* point = line->intersection(Line{1, 0, 0});
    ASSERT_TRUE(point->x == 0);
    ASSERT_TRUE(point->y == -1.5);
    delete line;
    delete point;
}

TEST(UnitTest, intersection_empty) {
    Line* line = new Line{1, 2, 3};
    Point* point = line->intersection(Line{2, 4, 6});
    ASSERT_TRUE(point==nullptr);
    delete line;
    delete point;
}

TEST(UnitTest, points_coefficients) {
    Line* line = new Line{-2, 2, 0};
    Line* line_2 = new Line{Point{2, 2}, Point{4, 4}};
    ASSERT_TRUE(line->A == line_2->A);
    ASSERT_TRUE(line->B == line_2->B);
    ASSERT_TRUE(line->C == line_2->C);
    delete line;
    delete line_2;
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}