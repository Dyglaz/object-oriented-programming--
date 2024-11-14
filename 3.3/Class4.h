#ifndef __CLASS4_H
#define __CLASS4_H
#include <string>
#include "Base.h"

using namespace std;

class Class4 : public Base {
    public:
    Class4(Base* parent, string name);
    void signal(string&);
    void handler(string);
};

#endif