#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <limits>

class Point {
public:
    float x;  
    float y; 
    Point(float a, float b) {
        x = a;
        y = b;
    }
};

class Line {
public:
    // Ax + By + C = 0
    float A;
    float B;
    float C;

    Line(const Point& a, const Point& b) {
        float x = b.x - a.y;
        float y = b.y - a.y; 
        A = -y;
        B = x;
        C = -(A * a.x + B * a.y);
    }

    Line(float a, float b, float c) { 
        A = a;
        B = b;
        C = c;
    }

    Point* intersection(const Line& other) {
        float det = A * other.B - B * other.A;
        if (det == 0) {
            return nullptr;
        }
        float x = -C * other.B + B * other.C;
        float y = C * other.A - other.C * A;
        return new Point{x / det, y / det};
    }
    
    Line* perpendicular(const Point& a) {
        float perpA = -B;
        float perpB = A;
        float perpC = -(perpA * a.x + perpB * a.y);
        return new Line(perpA, perpB, perpC);
    }
};

