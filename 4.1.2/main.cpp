#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "ClassesHeader.h"
using namespace std;
int main() {
    string name;
    int val;
    cin >> name >> val;
    ClassFour obj(name, val);
    obj.printValues();
    return(0);
}