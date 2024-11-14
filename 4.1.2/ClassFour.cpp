#include "ClassesHeader.h"
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

ClassFour::ClassFour(string name, int value) : ClassThree(name, value) {
    objName = name + "_4";
    m_val = pow(value, 4);
}

void ClassFour::printValues() {
    ClassThree::printValues();
    cout << objName << " " << m_val;
}