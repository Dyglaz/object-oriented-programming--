#ifndef __CLASS6_H
#define __CLASS6_H
#include <string>
#include "Base.h"

using namespace std;

class Class6 : public Base {
    public:
    Class6(Base* parent, string name);
    void signal(string&);
    void handler(string);
};

#endif