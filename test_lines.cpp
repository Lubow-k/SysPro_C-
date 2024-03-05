#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "lines.cpp"

using namespace std;

TEST(UnitTest, perpendicular) {
    Line line{1, 2, 3};
    Line* line_2 = line.perpendicular(Point{-3, 0});
    ASSERT_TRUE(line_2->getA() == 1);
    ASSERT_TRUE(line_2->getB() == -0.5);
    ASSERT_TRUE(line_2->getC() == 3);
    delete line_2;
}

TEST(UnitTest, perpendicular_2) {
    Line line{0, 1, 0};
    Line* line_2 = line.perpendicular(Point{0, 0});
    ASSERT_TRUE(line_2->getA() == 1);
    ASSERT_TRUE(line_2->getB() == 0);
    ASSERT_TRUE(line_2->getC() == 0);
    delete line_2;
}

TEST(UnitTest, intersection) {
    Line line{1, 2, 3};
    Point* point = line.intersection(Line{1, 0, 0});
    ASSERT_TRUE(point->getX() == 0);
    ASSERT_TRUE(point->getY() == -1.5);
    delete point;
}

TEST(UnitTest, intersection_empty) {
    Line line{3, 2, 1};
    Point* point = line.intersection(Line{6, 4, 2});
    ASSERT_TRUE(point == nullptr);
    delete point;
}

TEST(UnitTest, points_coefficients) {
    Line line{-2, 2, 0};
    Line* line_2 = new Line{Point{1, 1}, Point{4, 4}};
    Line* line_3 = new Line{Point{-5, - 5}, Point{2, 2}};
    ASSERT_TRUE(line.getA() == line_2->getA() && line_2->getA() == line_3->getA());
    ASSERT_TRUE(line.getB() == line_2->getB() && line_2->getB() == line_3->getB());
    ASSERT_TRUE(line.getC() == line_2->getC() && line_2->getC() == line_3->getC());
    delete line_2;
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}