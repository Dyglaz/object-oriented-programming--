#ifndef KLASS_H
#define KLASS_H
#include <vector>
using namespace std;
class Base {
    public:
    int n;
    vector<int> arr;
};

class DerOne: public virtual Base {
    public:
    void fillArray();
};

class DerTwo: public virtual Base {
    public:
    void sortArray();
    void printArray();
};

class DerThree: public DerOne, public DerTwo {
    public:
    void process();
};

#endif