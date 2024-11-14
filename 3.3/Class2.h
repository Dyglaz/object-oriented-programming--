#ifndef __CLASS2_H
#define __CLASS2_H
#include <string>
#include "Base.h"

using namespace std;

class Class2 : public Base {
    public:
    Class2(Base* parent, string name);
    void signal(string&);
    void handler(string);
};

#endif