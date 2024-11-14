#include <iostream>
#include <string>
#include <vector>
#include "Application.h"
#include "Base.h"
#include "Creator.h"
#include "Class2.h"

using namespace std;

Class2::Class2(Base* parent, string name) : Base(parent, name){
    classNum = 2;
}

void Class2::signal(string &msg){
    cout << "\nSignal from " << this->getPath();
    msg += " (class: 2)";
}

void Class2::handler(string msg){
    cout << "\nSignal to " << this->getPath() << " Text: " << msg;
}