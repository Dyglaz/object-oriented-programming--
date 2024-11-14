#include "classes.h"
#include <iostream>
#include <string>
using namespace std;
second::second(string name) : first("n") {
    this-> name = name;
    first ob(name);
    if(name != "n")
    cout << name << "_" << 2 <<endl;
}