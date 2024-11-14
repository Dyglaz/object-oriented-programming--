#include "ClassesHeader.h"
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

ClassOne::ClassOne(string name, int value) {
    objName = name + "_1";
    m_val = pow(value, 1);
}

void ClassOne::printValues() {
    cout << objName << " " << m_val << '\n';
}