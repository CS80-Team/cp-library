#include<bits/stdc++.h>

using namespace std;

#define ftype double

struct Point2D {
    ftype x, y;
    Point2D() {}
    Point2D(ftype x, ftype y): x(x), y(y) {}
    Point2D& operator+=(const Point2D &p2) {
        x += p2.x;
        y += p2.y;
        return *this;
    }
    Point2D& operator-=(const Point2D &p2) {
        x -= p2.x;
        y -= p2.y;
        return *this;
    }

    Point2D& operator*=(const Point2D p2) {
        x *= p2.x;
        y *= p2.y;
        return *this;
    }
    Point2D& operator/=(const Point2D p2) {
        x /= p2.x;
        y /= p2.y;
        return *this;
    }
    
    Point2D& operator+(const Point2D p2) {
        return Point2D(*this) += p2;
    }
    Point2D& operator-(const Point2D p2) {
        return Point2D(*this) -= p2;
    }
    Point2D& operator/(const Point2D p2) {
        return Point2D(*this) /= p2;
    }
    Point2D& operator*(const Point2D p2) {
        return Point2D(*this) *= p2;
    }
    

};

Point2D operator*(ftype a, Point2D b) {
        return a * b;
}


int main() {
    Point2D p1(1, 2);
    Point2D p2(3, 4);
    
    Point2D p3 = p1 * p2;
    
}