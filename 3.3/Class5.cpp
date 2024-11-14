#include <iostream>
#include <string>
#include <vector>
#include "Application.h"
#include "Base.h"
#include "Creator.h"
#include "Class5.h"

using namespace std;

Class5::Class5(Base* parent, string name) : Base(parent, name){
    classNum = 5;
}

void Class5::signal(string &msg){
    cout << "\nSignal from " << this->getPath();
    msg += " (class: 5)";
}

void Class5::handler(string msg){
    cout << "\nSignal to " << this->getPath() << " Text: " << msg;
}