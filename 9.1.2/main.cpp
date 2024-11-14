#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include "klass.h"
int main() {
    int n;
    cin >> n;
    vector <Object> arr;
    int value, mask;
    cin >> hex;
    for (int i = 0; i < n; i++) {
        cin >> value >> mask;
        arr.push_back(Object(value, mask));
    }
    cin >> dec;
    int num1, num2;
    char op;
    while(cin >> num1 >> op >> num2) {
        if (op == '&') {
            arr[num1-1] = arr[num1-1] & arr[num2-1];
        } else {
            arr[num1-1] = arr[num1-1] | arr[num2-1];
        }
    }
    cout << setw(2) << setfill('0') << hex << uppercase << arr[num1-1].getValue().to_ulong();
    return(0);
}