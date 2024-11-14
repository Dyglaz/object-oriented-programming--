#include "klass.h"
#include <iomanip>
#include <algorithm>
#include <iostream>
void DerOne::fillArray() {
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void DerTwo::printArray() {
    for (int i = 0; i < arr.size(); i++) {
        cout << setw(5) << arr[i];
    }
}

void DerTwo::sortArray() {
    sort(arr.begin(), arr.end());
}

void DerThree::process() {
    fillArray();
    cout << "Array dimension: " << n;
    cout << "\nThe original array:";
    printArray();
    sortArray();
    cout << "\nAn ordered array:";
    printArray();
}