#include <iostream>
#include <string>
#include <vector>
#include "Application.h"
#include "Base.h"
#include "Creator.h"
#include "Class4.h"

using namespace std;

Class4::Class4(Base* parent, string name) : Base(parent, name){
    classNum = 4;
}

void Class4::signal(string &msg){
    cout << "\nSignal from " << this->getPath();
    msg += " (class: 4)";
}

void Class4::handler(string msg){
    cout << "\nSignal to " << this->getPath() << " Text: " << msg;
}