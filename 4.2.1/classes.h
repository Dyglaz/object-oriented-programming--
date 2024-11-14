#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <string>
using namespace std;
class first{
    public:
    first(string name);
    
    protected:
    string name;
};

class second : public first{
    public:
    second(string name);
};

class third : public first{
    public:
    third(string name);
};

class forth : public first{
    public:
    forth(string name);
};

class fifth : public first{
    public:
    fifth(string name);
};

class sixth : public second, public third{
    public:
    sixth(string name);
};

class seventh : public forth ,public fifth{
    public:
    seventh(string name);
};

class eight : public sixth, public seventh{
    public:
    eight(string name);
};

#endif