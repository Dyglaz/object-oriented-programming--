#include <stdlib.h>
#include <stdio.h>
#include "klass.h"
int main() {
    DerThree *obj;
    obj = new DerThree();
    obj->Base::in_out();
    obj->DerOne::func();
    obj->DerTwo::func();
    obj->DerThree::in_out();
    return 0;
}