#include<bits/stdc++.h>

#define ftype double

struct Point3D {
    ftype x, y, z;
    Point3D() {}
    Point3D(ftype x, ftype y, ftype z): x(x), y(y), z(z) {}
    Point3D& operator+=(const Point3D &p2) {
        x += p2.x;
        y += p2.y;
        z += p2.z;
        return *this;
    }
    Point3D& operator-=(const Point3D &p2) {
        x -= p2.x;
        y -= p2.y;
        z -= p2.z;
        return *this;
    }

    Point3D& operator*=(const Point3D p2) {
        x *= p2.x;
        y *= p2.y;
        z *= p2.z;
        return *this;
    }
    Point3D& operator/=(const Point3D p2) {
        x /= p2.x;
        y /= p2.y;
        z /= p2.z;
        return *this;
    }
    
    Point3D& operator+(const Point3D p2) {
        return Point3D(*this) += p2;
    }
    Point3D& operator-(const Point3D p2) {
        return Point3D(*this) -= p2;
    }
    Point3D& operator/(const Point3D p2) {
        return Point3D(*this) /= p2;
    }
    Point3D& operator*(const Point3D p2) {
        return Point3D(*this) *= p2;
    }
    

};

Point3D operator*(ftype a, Point3D b) {
        return a * b;
}

int main() {
    Point3D p1(1, 2);
    Point3D p2(3, 4);
    
    Point3D p3 = p1 * p2;
}