#include "klass.h"
#include <iostream>


Base::Base(Base *headObjPtr, string name) {
this->name = name;
headObj = headObjPtr;
if (headObjPtr) {
headObjPtr->childObjArr.push_back(this);
}
}

void Base::setName(string name) {
this->name = name;
}

string Base::getName() {
return name;
}

void Base::setHeadObj(Base *headObjPtr) {
headObj = headObjPtr;
}

Base* Base::getHeadObj() {
return headObj;
}

void Base::printTree() {
if (this->childObjArr.size() != 0) {
cout << endl << this->getName();
for (int i = 0; i < this->childObjArr.size(); i++) {
cout << "  " << (this->childObjArr[i])->getName();
}
for (int i = 0; i < this->childObjArr.size(); i++) {
(this->childObjArr[i])->printTree();
}
}
}

Base* Base::getObjByName(Base* rootObj, string name) {
if (rootObj->getName() == name) {
return rootObj;
}
for (int i = 0; i < rootObj->childObjArr.size(); i++) {
if ( rootObj->childObjArr[i]->getName() == name) {
return rootObj->childObjArr[i];
}
Base * res = getObjByName(rootObj->childObjArr[i], name);
if (res != nullptr) {return res;}
}
return nullptr;
}

void Application::buildTree() {
string rootName;
cin >> rootName;
Branch* rootObj = new Branch(nullptr, rootName);
string parentName, childName;
cin >> parentName >> childName;
while (parentName != childName) {
Branch *child = new Branch(getObjByName(rootObj, parentName),childName);
cin >> parentName >> childName;
}
cout << rootObj->getName();
rootObj->printTree();
}
int Application::execApp() {
return 0;
}

Application::Application(Application *headObjPtr, string name) :
Base(headObjPtr, name) {}

Branch::Branch(Base *headObjPtr, string name) : Base(headObjPtr, name) {}