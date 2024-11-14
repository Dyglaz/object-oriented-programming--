#include <iostream>
#include <string>
#include <vector>
#include "Base.h"

using namespace std;

Base::Base(Base* parent, string name){
    this->parent = parent;
    this->name = name;
    if(this->parent != nullptr) parent->children.push_back(this);
}

void Base::setName(string name){
    this->name = name;
}

string Base::getName(){
    return name;
}

void Base::print(){
    cout << name << " ";
    for (int i = 0; i < children.size(); i++){
        cout << children[i]->getName();
        if (i != children.size() - 1) cout << " ";
    }
    for (int i = 0; i < children.size(); i++){
        if (children[i]->children.size() > 0){
            cout << "\n";
            children[i]->print();
        }
    }
}

void Base::setParent(Base* newParent){
    if(newParent != nullptr && this->parent != nullptr){
        for(int i = 0; i < this->parent->children.size(); i++){
            if(this->parent->children[i] == this){
                this->parent->children.erase(this->parent->children.begin() + i);
            }
        }
        this->parent = newParent;
        newParent->children.push_back(this);
    }
}

Base* Base::getParent(){
    return parent;
}

Base::~Base(){
    for (int i = 0; i < children.size(); i++) delete children[i];
}

Base* Base::getByName(string name){
    if (this->name == name){
        return this;
    }
    for (int i = 0; i < this->children.size(); i++){
        Base* des = children[i]->getByName(name);
        if(des != nullptr){
            return des;
        }
    }
    return nullptr;
}

void Base::newPrint(int tab){
    int factor = tab*4;
    for(int i = 0; i < factor; i++){
        cout << " ";
    }
    cout << this->name;
    if(!this->children.size()){
        return;
    }
    cout << endl;
    for(int i = 0; i < this->children.size(); i++){
        this->children[i]->newPrint(tab+1);
        if(i!= this->children.size()-1){
            cout << endl;
        }
    }
}

void Base::setReadiness(int isReady){
    Base* obj = this->getParent();
    if(this->isReady == 0 && isReady == 0) return;
    if ((obj != nullptr && obj->isReady != 0) || (obj == nullptr)) this->isReady = isReady;
    else this->isReady = 0;
    if(this->isReady == 0){
        for(int i = 0; i < this->children.size(); i++){
            children[i]->setReadiness(0);
        }
    }
}

void Base::printReadiness(int tab){
    int factor = tab*4;
    for(int i = 0; i < factor; i++){
        cout << " ";
    }
    cout << this->name;
    if (this->isReady == 0) cout << " is not ready";
    else cout << " is ready";
    if(!this->children.size()){
        return;
    }
    cout << endl;
    for(int i = 0; i < this->children.size(); i++){
        this->children[i]->printReadiness(tab+1);
        if(i != this->children.size()-1){
            cout << endl;
        }
    }
}

Base* Base::getByPath(string path){
    if(!path.size()) return nullptr;
    if (path == "." || path == this->getName()) return this;
    string childName;
    if (path[0] == '/'){
        Base* obj = this;
        while (obj->parent) obj = obj->parent;
        if (path == "/") return obj;
        if (path[1] == '/') return obj->getByName(path.substr(2));
        else return obj->getByPath(path.substr(1));
    }
    else{
        int pos;
        for (pos = 0; pos < path.size() && path[pos] != '/'; pos++) childName += path[pos];
        for (int i = 0; i < this->children.size(); i++){
            if(this->children[i]->getName() == childName){
                if(path == childName) return this->children[i];
                else return this->children[i]->getByPath(path.substr(pos+1));
            }
        }
    }
    return nullptr;
}

string Base::getPath(){
    if(!parent) return "/";
    if (parent->parent) return parent->getPath() + "/" + name;
    else return parent->getPath() + "" + name;
}

int Base::getClassNum(){
    return classNum;
}

void Base::setCon(TypeSignal signal, Base* target, TypeHandler handler){
    for(int i = 0; i<connects.size(); i++){
        if(connects[i].signal == signal && connects[i].target == target && connects[i].handler == handler) return;
    }
    oneConnect current = {signal, target, handler}; 
    connects.push_back(current);
}

void Base::delCon(TypeSignal signal, Base* target, TypeHandler handler){
    for(int i = 0; i < connects.size(); i++){
        if(connects[i].signal == signal && connects[i].target == target && connects[i].handler == handler){
            connects.erase(connects.begin() + i);
            return;
        }
    }
}

void Base::emitSignal(TypeSignal signal, string msg){
    if(isReady){
        (this->*signal)(msg);
        for(int i = 0; i < connects.size(); i++){
            if(connects[i].signal == signal && connects[i].target->getReadiness()) (connects[i].target->*connects[i].handler)(msg);
        }
    }
}

void Base::setAllReady(){
    this->setReadiness(1);
    for (int i = 0; i <this->children.size(); i++){
        this->children[i]->setAllReady();
    }
}

int Base::getReadiness(){
    return isReady;
}