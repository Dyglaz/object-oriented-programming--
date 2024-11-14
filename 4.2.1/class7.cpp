#include "classes.h"
#include <iostream>
#include <string>
using namespace std;
seventh::seventh(string name) : forth("n"),fifth("n"){
    this-> forth::name = name;
    forth ob(name);
    fifth ob1(name);
    if(name != "n")
    cout << name << "_" << 7 << endl;
}