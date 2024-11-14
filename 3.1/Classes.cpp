#include "Classes.h"
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

int Base::getReadiness() {
    return isReady;
}

void Base::setReadiness(int _isReady) {
    if (_isReady == 0) {
        this->isReady = _isReady;
        for (int i = 0; i < this->childObjArr.size(); i++) {
            this->childObjArr[i]->setReadiness(_isReady);
        }
    }
    else {
        if (headObj) {
            this->isReady = _isReady && headObj->getReadiness();
        }
        else {
            this->isReady = _isReady;
        }
    }
}

void Base::printTree(int tabLevel, bool printReadiness) {
    string tabs(tabLevel*4, ' ');
    cout << tabs << this->getName();
    if (printReadiness) {
        if (this->getReadiness() != 0) {
            cout << " is ready";
        }
        else {
            cout << " is not ready";
        }
    }
    for (int i = 0; i < this->childObjArr.size(); i++) {
        cout << endl;
        (this->childObjArr[i])->printTree(tabLevel+1, printReadiness);
    }
}

Base* Base::getObjByName(Base* rootObj, string name) {
    if (rootObj->getName() == name) {
        return rootObj;
    }
    for (int i = 0; i < rootObj->childObjArr.size(); i++) {
        if (rootObj->childObjArr[i]->getName() == name) {
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
    Application* rootObj = new Application(nullptr, rootName);
    string parentName, childName;
    int classNum;
    while (true) {
        cin >> parentName;
        if (parentName == "endtree") break;
        cin >> childName >> classNum;
        switch (classNum) {
            case 2: {
                cl_2 *child = new cl_2(getObjByName(rootObj, parentName), childName);
                break;
            }
            case 3: {
                cl_3 *child = new cl_3(getObjByName(rootObj, parentName), childName);
                break;
            }
            case 4: {
                cl_4 *child = new cl_4(getObjByName(rootObj, parentName), childName);
                break;
            }
            case 5: {
                cl_5 *child = new cl_5(getObjByName(rootObj, parentName), childName);
                break;
            }
            case 6: {
                cl_6 *child = new cl_6(getObjByName(rootObj, parentName), childName);
                break;
            }
            default:
            break;
        }
    }
    cout << "Object tree" << endl;
    rootObj->printTree(0, false);
    cout << endl;
    string objName;
    int isReady;
    while (cin >> objName >> isReady) {
        getObjByName(rootObj, objName)->setReadiness(isReady);
    }
    cout << "The tree of objects and their readiness" << endl;
    rootObj->printTree(0, true);
}

int Application::execApp() {
    return 0;
}

Application::Application(Application *headObjPtr, string name) :
Base(headObjPtr, name) {}