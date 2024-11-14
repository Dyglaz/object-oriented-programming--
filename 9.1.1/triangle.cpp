#include "triangle.h"
#include <cmath>
#include <iostream>
Triangle::Triangle(int _side1, int _side2, int _side3) {
    a = _side1;
    b = _side2;
    c = _side3;
}

Triangle::Triangle() {}

bool Triangle::validateTriangle() {
    if (a > 0 and b > 0 and c > 0) {
        if ((a+b)>c and (a+c)>b and (c+b)>a) {
            return true;
        }
    }
    return false;
}

void Triangle::toString() {
    std::cout << "a = " << a << "; b = " << b << "; c = " << c << '.';
}

Triangle Triangle::operator+ (Triangle& obj) {
    Triangle res(a + obj.a, b + obj.b, c + obj.c);
    if (res.validateTriangle()) {
        return res;
    }
    return *this;
}

Triangle Triangle::operator- (Triangle& obj) {
    Triangle res(a - obj.a, b - obj.b, c - obj.c);
    if (res.validateTriangle()) {
        return res;
    }
    return *this;
}

int Triangle::Perimeter() {
    return a + b + c;
}

float Triangle::Area() {
    float semiP = (a + b + c) / 2.0;
    return std::sqrt(semiP * (semiP - a) * (semiP - b) * (semiP - c));
}