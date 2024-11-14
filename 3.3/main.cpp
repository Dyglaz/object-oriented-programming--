#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Application.h"
#include "Base.h"

using namespace std;

int main() {
    App tree(nullptr);
    if(tree.doTree() == 0) return tree.startApp();
    return 0;
}