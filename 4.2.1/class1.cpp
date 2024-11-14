#include "classes.h"
#include <iostream>
#include <string>
using namespace std;
first::first(string name) {
    this -> name = name;
    if(name != "n"){
        cout << name << "_" << 1 << endl;
        cout << name << "_" << 1 << endl;
        cout << name << "_" << 1 << endl;
    }
}