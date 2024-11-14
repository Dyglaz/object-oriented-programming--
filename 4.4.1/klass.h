#ifndef KLASS_H
#define KLASS_H
#include <vector>
using namespace std;
class Base {
    public:
    int n;
    int resultMin;
    int resultSum;
    vector<int> arr;
    void in_out();
};

class DerOne : public Base {
    public:
    int func();
};

class DerTwo : public DerOne {
    public:
    int func();
};

class DerThree : public DerTwo {
    public:
    void in_out();
};

#endif