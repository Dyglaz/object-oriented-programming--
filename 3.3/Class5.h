#ifndef __CLASS5_H
#define __CLASS5_H
#include <string>
#include "Base.h"

using namespace std;

class Class5 : public Base {
    public:
    Class5(Base* parent, string name);
    void signal(string&);
    void handler(string);
};

#endif