#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <limits>
#include <optional>

struct Point {
    double x, y; 
    Point(double x_, double y_): x(x_), y(y_) {}
};

class Line {
    double A, B, C;   // Ax + By + C = 0, where A = 1 

public:
    Line(const Point& a, const Point& b) {
        double x = b.x - a.x;
        double y = b.y - a.y; 
        A = 1;
        B = x / (-y);
        C = -(A * a.x + B * a.y);
    }

    Line(double a, double b, double c) { 
        A = 1;
        B = b / a;
        C = c / a;
    }

    double getA() const {
        return A;
    }

    double getB() const {
        return B;
    }

    double getC() const {
        return C;
    }

    std::optional<Point> intersection(const Line& other) {
        double det = A * other.getB() - B * other.getA();
        if (det == 0) {
            return std::nullopt;
        }
        double x = -C * other.getB() + B * other.getC();
        double y = C * other.getA() - other.getC() * A;
        return Point{x / det, y / det};
    }
    
    Line perpendicular(const Point& a) {
        double perpA = 1;
        double perpB = A / (-B);
        double perpC = -(perpA * a.x + perpB * a.y);
        return Line(perpA, perpB, perpC);
    }
};

