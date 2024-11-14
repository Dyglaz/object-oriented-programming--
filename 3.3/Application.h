#ifndef __APPLICATION_H
#define __APPLICATION_H
#include "Base.h"
#include "Creator.h"

using namespace std;

class App: public Base{
    public:
    App(Base* parent);
    int doTree();
    int startApp();
    TypeSignal getSignal(Base*);
    TypeHandler getHandler(Base*);
    void signal(string&);
    void handler(string);
};

#endif