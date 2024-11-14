#include "ClassesHeader.h"
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

ClassThree::ClassThree(string name, int value): ClassTwo(name, value) {
    objName = name + "_3";
    m_val = pow(value, 3);
}

void ClassThree::printValues() {
    ClassTwo::printValues();
    cout << objName << " " << m_val << '\n';
}