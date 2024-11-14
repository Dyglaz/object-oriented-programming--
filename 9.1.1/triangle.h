#ifndef TRIANGLE_H
#define TRIANGLE_H
class Triangle {
    private:
    int a, b, c;
    public:
    Triangle();
    Triangle(int _side1, int _side2, int _side3);
    bool validateTriangle();
    Triangle operator+ (Triangle &obj);
    Triangle operator- (Triangle &obj);
    void toString();
    int Perimeter();
    float Area();
};

#endif