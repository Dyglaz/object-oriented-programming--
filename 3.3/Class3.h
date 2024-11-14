#ifndef __CLASS3_H
#define __CLASS3_H
#include <string>
#include "Base.h"

using namespace std;

class Class3 : public Base {
    public:
    Class3(Base* parent, string name);
    void signal(string&);
    void handler(string);
};

#endif