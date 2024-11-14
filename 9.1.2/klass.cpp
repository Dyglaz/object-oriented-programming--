#include "klass.h"
Object::Object(int value, int mask) {
    this->value = value;
    this->mask = mask;
}

bitset<8> Object::getValue() {
    return value;
}

Object Object::operator &(Object& obj) {
    bitset<8> resMask = mask & obj.mask;
    value = (value & ~resMask) | (resMask & (value & obj.value));
    return *this;
}

Object Object::operator |(Object& obj) {
    bitset<8> resMask = mask & obj.mask;
    value = (value & ~resMask) | (resMask & (value | obj.value));
    return *this;
}