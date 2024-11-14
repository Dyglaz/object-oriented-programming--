#ifndef __BASE_H
#define __BASE_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Base;
typedef void (Base::*TypeSignal)(string&);
#define SIGNAL(signal)((TypeSignal)(&signal));
typedef void (Base::*TypeHandler)(string);
#define HANDLER(handler)((TypeHandler)(&handler));

class Base{
    protected:
    string name;
    Base* parent;
    vector <Base*> children;
    int isReady;
    int classNum;
    struct oneConnect {
        TypeSignal signal;
        Base* target;
        TypeHandler handler;
    };
    vector <oneConnect> connects;
    public:
    Base(Base* parent, string name = "app_root");
    void setName(string name);
    string getName();
    void print();
    void setParent(Base* newParent);
    Base* getParent();
    Base* getByName(string name);
    void newPrint(int tab);
    void printReadiness(int tab);
    void setReadiness(int isReady);
    Base* findChild(const string &name);
    Base* getByPath(string path);
    void setAllReady();
    string getPath();
    int getClassNum();
    void setCon(TypeSignal, Base*, TypeHandler);
    void delCon(TypeSignal, Base*, TypeHandler);
    void emitSignal(TypeSignal, string);
    int getReadiness();
    ~Base();
};

#endif