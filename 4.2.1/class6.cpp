#include "classes.h"
#include <iostream>
#include <string>
using namespace std;
sixth::sixth(string name) : second("n"),third("n"){
    this-> second::name = name;
    second ob(name);
    third ob1(name);
    if(name != "n")
    cout << name << "_" << 4 << endl;
}