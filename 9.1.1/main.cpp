#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "triangle.h"
using namespace std;
int main() {
    int n;
    cin >> n;
    vector <Triangle> arr;
    int a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        arr.push_back(Triangle(a, b, c));
    }
    int num1, num2;
    char op;
    while(cin >> num1 >> op >> num2) {
        if (op == '+') {
            arr[num1-1] = arr[num1-1] + arr[num2-1];
        } else {
            arr[num1-1] = arr[num1-1] - arr[num2-1];
        }
    }
    arr[num1-1].toString();
    return 0;
}