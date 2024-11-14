#ifndef CLASSES_H
#define CLASSES_H
class DerOne {
    public:
    virtual int calc(int x);
    DerOne(int a1);
    private:
    int a1;
};

class DerTwo : public DerOne {
    public:
    int calc(int x);
    DerTwo(int a1, int a2);
    private:
    int a1;
    int a2;
};

class DerThree : public DerTwo {
    public:
    int calc(int x);
    DerThree(int a1, int a2, int a3);
    private:
    int a1;
    int a2;
    int a3;
};

class DerFour : public DerThree {
    public:
    int calc(int x);
    DerFour(int a1, int a2, int a3, int a4);
    private:
    int a1;
    int a2;
    int a3;
    int a4;
};

#endif