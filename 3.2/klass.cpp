#include "klass.h"
#include <sstream>
#include <iostream>
#include <string>
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
        if (this->getReadiness()) {
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

Base* Base::getObjByName(string name) {
    if (this->getName() == name) {
        return this;
    }
    for (int i = 0; i < this->childObjArr.size(); i++) {
        if (this->childObjArr[i]->getName() == name) {
            return this->childObjArr[i];
        }
        Base * res = this->childObjArr[i]->getObjByName(name);
        if (res != nullptr) {return res;}
    }
    return nullptr;
}

Base* Base::getObjByPath(string path) {
    istringstream ss(path);
    string obj;
    Base* head = this;
    bool flag;
    while (getline(ss, obj, '/')) {
        flag = false;
        if (obj != "") {
            for (int i = 0; i < head->childObjArr.size(); i++) {
                if (head->childObjArr[i]->getName() == obj) {
                    head = head->childObjArr[i];
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                return nullptr;
            }
        }
    }
    return head;
}

void Application::buildTree() {
    string rootName;
    cin >> rootName;
    this->setName(rootName);
    string path, childName;
    int classNum;
    while (true) {
        cin >> path;
        if (path == "endtree") break;
        cin >> childName >> classNum;
        Base* parent = this->getObjByPath(path);
        if (parent == nullptr) {
            cout << "Object tree" << endl;
            this->printTree(0, false);
            cout << "\nThe head object " << path << " is not found";
            exit(0);
        }
        switch (classNum) {
            case 2: {
                cl_2 *child = new cl_2(parent, childName);
                break;
            }
            case 3: {
                cl_3 *child = new cl_3(parent, childName);
                break;
            }
            case 4: {
                cl_4 *child = new cl_4(parent, childName);
                break;
            }
            case 5: {
                cl_5 *child = new cl_5(parent, childName);
                break;
            }
            case 6: {
                cl_6 *child = new cl_6(parent, childName);
                break;
            }
            default:
            break;
        }
    }
}

int Application::execApp() {
    cout << "Object tree" << endl;
    this->printTree(0, false);
    string cmd, path;
    Base * curObj = this;
    Base * temp;
    while (true) {
        cin >> cmd;
        if (cmd == "END") {
            break;
        }
        cout << endl;
        cin >> path;
        if (path == ".") {
            temp = curObj;
        }
        else if (path.rfind("//", 0) == 0) {
            temp = this->getObjByName(path.substr(2));
        }
        else if (path.rfind("/", 0) == 0) {
            temp = this->getObjByPath(path);
        }
        else {
            temp = curObj->getObjByPath(path);
        }
        if (cmd == "SET") {
            if (temp != nullptr) {
                curObj = temp;
                cout << "Object is set: " << curObj->getName();
            }
            else {
                cout << "Object is not found: " << curObj->getName() << " " << path;
            }
        }
        if (cmd == "FIND") {
            cout << path;
            if (temp != nullptr) {
                cout << " Object name: " << temp->getName();
            }
            else {
                cout << " Object is not found";
            }
        }
    }
    return 0;
}

Application::Application(Application *headObjPtr, string name) :
Base(headObjPtr, name) {}