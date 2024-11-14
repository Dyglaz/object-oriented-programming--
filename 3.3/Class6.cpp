#include <iostream>
#include <string>
#include <vector>
#include "Application.h"
#include "Base.h"
#include "Creator.h"
#include "Class6.h"

using namespace std;

Class6::Class6(Base* parent, string name) : Base(parent, name){
    classNum = 6;
}

void Class6::signal(string &msg){
    cout << "\nSignal from " << this->getPath();
    msg += " (class: 6)";
}

void Class6::handler(string msg){
    cout << "\nSignal to " << this->getPath() << " Text: " << msg;
}