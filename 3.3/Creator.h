#ifndef __CREATOR_H
#define __CREATOR_H
#include <string>
#include "Base.h"

using namespace std;

class Creator : public Base {
    public:
    Creator(Base* parent, string name);
};

#endif