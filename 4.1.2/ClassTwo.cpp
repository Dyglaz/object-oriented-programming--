#include "ClassesHeader.h"
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

ClassTwo::ClassTwo(string name, int value): ClassOne(name, value) {
    objName = name + "_2";
    m_val = pow(value, 2);
}

void ClassTwo::printValues() {
    ClassOne::printValues();
    cout << objName << " " << m_val << '\n';
}