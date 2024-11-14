#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "klass.h"
using namespace std;
int main() {
    DerFour *obj;
    int a1, a2, a3, a4;
    int x;
    cin >> a1 >> a2 >> a3 >> a4;
    cout << "a1 = " << a1 << "     a2 = " << a2;
    cout << "     a3 = " << a3 << "     a4 = " << a4;
    DerFour objF(a1, a2, a3, a4);
    obj = &objF;
    int classNum;
    while (true) {
        cin >> x;
        if (x == 0) {
            break;
        }
        cin >> classNum;
        cout << "\nClass " << classNum << "    F( " << x << " ) = ";
        if (classNum == 1) {
            cout << obj->DerOne::calc(x);
        } else if (classNum == 2) {
            cout << obj->DerTwo::calc(x);
        } else if (classNum == 3) {
            cout << obj->DerThree::calc(x);
        } else {
            cout << obj->DerFour::calc(x);
        }
    }
    return 0;
}