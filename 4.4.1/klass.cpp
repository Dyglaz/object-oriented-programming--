#include "klass.h"
#include <iostream>
#include <iomanip>
void Base::in_out() {
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int DerOne::func() {
    resultMin = arr[0];
    for (int i = 1; i < n; i++) {
        resultMin -= arr[i];
    }
    return resultMin;
}

int DerTwo::func() {
    resultSum = 0;
    for (int i = 0; i < n; i++) {
        resultSum += arr[i];
    }
    return resultSum;
}

void DerThree::in_out() {
    cout << "Array dimension: " << n;
    cout << "\nThe original array:";
    for (int i = 0; i < n; i++) {
        cout << setw(5) << arr[i];
    }
    cout << "\nMin: " << resultMin;
    cout << "\nSum: " << resultSum;
}