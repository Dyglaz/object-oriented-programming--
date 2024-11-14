#ifndef BITWORK_H
#define BITWORK_H
#include <bitset>
using namespace std;
class Object {
    private:
    bitset<8> value;
    bitset<8> mask;
    public:
    Object(int value, int mask);
    bitset<8> getValue();
    Object operator& (Object& obj);
    Object operator| (Object& obj);
};

#endif
