#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <limits>

class Point {
    double x, y;

public: 
    Point(double a, double b): x(a), y(b) {}
    
    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }
};

class Line {
    double A, B, C;   // Ax + By + C = 0, where A = 1 

public:
    Line(const Point& a, const Point& b) {
        double x = b.getX() - a.getX();
        double y = b.getY() - a.getY(); 
        A = 1;
        B = x / (-y);
        C = -(A * a.getX() + B * a.getY());
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

    Point* intersection(const Line& other) {
        double det = A * other.getB() - B * other.getA();
        if (det == 0) {
            return nullptr;
        }
        double x = -C * other.getB() + B * other.getC();
        double y = C * other.getA() - other.getC() * A;
        return new Point{x / det, y / det};
    }
    
    Line* perpendicular(const Point& a) {
        double perpA = 1;
        double perpB = A / (-B);
        double perpC = -(perpA * a.getX() + perpB * a.getY());
        return new Line(perpA, perpB, perpC);
    }
};

