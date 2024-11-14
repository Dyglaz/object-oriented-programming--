#include <iostream>
#include <string>
#include <vector>
#include "Application.h"
#include "Base.h"
#include "Creator.h"
#include "Class2.h"
#include "Class3.h"
#include "Class4.h"
#include "Class5.h"
#include "Class6.h"

using namespace std;

App::App(Base* parent):Base(parent, "root"){
    classNum = 1;
}
void App::handler(string msg){
    cout << "\nSignal to " << this->getPath() << " Text: " << msg;
}
void App::signal(string &msg){
    cout << "\nSignal from " << this->getPath();
    msg += " (class: 1)";
}
int App::doTree(){
    int classNum;
    string parentName, childName;
    cin >> parentName;
    setName(parentName);
    Base* paRENT;
    while(true) {
        cin >> parentName;
        if (parentName == "endtree") break;
        cin >> childName >> classNum;
        paRENT = getByPath(parentName);
        if (paRENT == nullptr){
            cout << "Object tree\n";
            this->newPrint(0);
            cout << "\nThe head object " + parentName + " is not found";
            return 1;
        }
        switch(classNum){
            case(2):
            new Class2(paRENT, childName);
            break;
            case(3):
            new Class3(paRENT, childName);
            break;
            case(4):
            new Class4(paRENT, childName);
            break;
            case(5):
            new Class5(paRENT, childName);
            break;
            case(6):
            new Class6(paRENT, childName);
            break;
        }
    }
    string objPath, targPath;
    Base *obj, *targ;
    while (true){
        cin >> objPath;
        if(objPath == "end_of_connections") break;
        cin >> targPath;
        obj = this->getByPath(objPath);
        targ = this->getByPath(targPath);
        obj->setCon(getSignal(obj), targ, getHandler(targ));
    }
    return 0;
}
TypeSignal App::getSignal(Base* pointer){
    switch(pointer->getClassNum()){
        case 1:
        return SIGNAL(App::signal);
        break;
        case 2:
        return SIGNAL(Class2::signal);
        break;
        case 3:
        return SIGNAL(Class3::signal);
        break;
        case 4:
        return SIGNAL(Class4::signal);
        break;
        case 5:
        return SIGNAL(Class5::signal);
        break;
        default:
        return SIGNAL(Class6::signal);
        break;
    }
}
TypeHandler App::getHandler(Base* pointer){
    switch(pointer->getClassNum()){
        case 1:
        return HANDLER(App::handler);
        break;
        case 2:
        return HANDLER(Class2::handler);
        break;
        case 3:
        return HANDLER(Class3::handler);
        break;
        case 4:
        return HANDLER(Class4::handler);
        break;
        case 5:
        return HANDLER(Class5::handler);
        break;
        default:
        return HANDLER(Class6::handler);
        break;
    }
}
int App::startApp(){
    setAllReady();
    cout << "Object tree\n";
    newPrint(0);
    
    string cmd, pathFrom, pathTo;
    Base *obj, *targ;
    while (true){
        cin >> cmd;
        if (cmd == "END") break;
        cin >> pathFrom;
        obj = getByPath(pathFrom);
        getline (cin, pathTo);
        pathTo = pathTo.substr(1);
        if (!obj){
            cout << "\nObject " << pathFrom << " not found";
            targ = getByPath(pathTo);
            if(!targ && (cmd == "SET_CONNECT" || cmd == "DELETE_CONNECT"))
            cout << "\nHandler object " << pathTo << " not found";
        }
        else if (cmd == "EMIT") {
            obj->emitSignal(getSignal(obj), pathTo);
        }
        else if (cmd == "SET_CONDITION"){
            int cond = stoi(pathTo);
            obj->setReadiness(cond);
        }
        else{
            targ = getByPath(pathTo);
            if (!targ) cout << "\nHandler object " << pathTo << " not found";
            else if (cmd == "SET_CONNECT") {
                obj->setCon(getSignal(obj), targ, getHandler(targ));
            }
            else if (cmd == "DELETE_CONNECT") {
                obj->delCon(getSignal(obj), targ, getHandler(targ));
            }
        }
    }
    return 0;
}