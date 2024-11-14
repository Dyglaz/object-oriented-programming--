#include <iostream>
#include <string>
#include <vector>
#include "Application.h"
#include "Base.h"
#include "Creator.h"
#include "Class3.h"

using namespace std;

Class3::Class3(Base* parent, string name) : Base(parent, name){
    classNum = 3;
}

void Class3::signal(string &msg){
    cout << "\nSignal from " << this->getPath();
    msg += " (class: 3)";
}

void Class3::handler(string msg){
    cout << "\nSignal to " << this->getPath() << " Text: " << msg;
}