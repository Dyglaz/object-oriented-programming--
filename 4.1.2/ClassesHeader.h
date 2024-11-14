#ifndef CLASSESHEADER_H
#define CLASSESHEADER_H
#include <string>
class ClassOne {
    private:
    std::string objName;
    int m_val;

    public:
    ClassOne(std::string name, int val);
    void printValues();
};

class ClassTwo : public ClassOne {
    private:
    std::string objName;
    int m_val;

    public:
    ClassTwo(std::string name, int val);
    void printValues();
};

class ClassThree : public ClassTwo {
    private:
    std::string objName;
    int m_val;

    public:
    ClassThree(std::string name, int val);
    void printValues();
};

class ClassFour : public ClassThree {
    private:
    std::string objName;
    int m_val;
    
    public:
    ClassFour(std::string name, int val);
    void printValues();
};
#endif