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
	void setHeadObj(Base *headObj);
	void printTree();
	Base* getObjByName(Base* rootObj, string name);
	
	private:
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

class Branch : public Base {
	public:
	Branch(Base *headObjPtr, string name = "TestObject");
};
#endif