#include "klass.h"
DerOne::DerOne(int a1) {
    this->a1 = a1;
}

int DerOne::calc(int x) {
    return a1*x;
}

DerTwo::DerTwo(int a1, int a2) : DerOne(a1) {
    this->a1 = a1;
    this->a2 = a2;
}

int DerTwo::calc(int x) {
    return a1*x + a2*x*x;
}

DerThree::DerThree(int a1, int a2, int a3) : DerTwo(a1, a2) {
    this->a1 = a1;
    this->a2 = a2;
    this->a3 = a3;
}

int DerThree::calc(int x) {
    return a1*x + a2*x*x + a3*x*x*x;
}

DerFour::DerFour(int a1, int a2, int a3, int a4) : DerThree(a1, a2, a3) {
    this->a1 = a1;
    this->a2 = a2;
    this->a3 = a3;
    this->a4 = a4;
}

int DerFour::calc(int x) {
    return a1*x + a2*x*x + a3*x*x*x + a4*x*x*x*x;
}