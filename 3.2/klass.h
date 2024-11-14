#ifndef KLASS_H
#define KLASS_H
#include <string>
#include <vector>
using namespace std;
class Base {
    public:
    Base();
    Base(Base *headObjPtr, string name = "TestObject");
    string getName();
    void setName(string name);
    Base* getHeadObj();
    int getReadiness();
    void setReadiness(int _isReady);
    void setHeadObj(Base *headObj);
    void printTree(int tabLevel, bool printReadiness);
    Base* getObjByPath(string path);
    Base* getObjByName(string name);
    
    private:
    int isReady = 0;
    string name;
    Base *headObj;
    vector<Base*> childObjArr;
};

class Application : public Base {
    public:
    Application(Application *headObjPtr, string name = "TestObject");
    void buildTree();
    int execApp();
};

class cl_2 : public Base {
    public:
    using Base::Base;
};

class cl_3 : public Base {
    public:
    using Base::Base;
};

class cl_4 : public Base {
    public:
    using Base::Base;
};

class cl_5 : public Base {
    public:
    using Base::Base;
};

class cl_6 : public Base {
    public:
    using Base::Base;
};

#endif