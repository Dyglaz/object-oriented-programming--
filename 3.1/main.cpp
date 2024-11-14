#include <stdlib.h>
#include <stdio.h>
#include "Classes.h"

int main() {
    Application app(nullptr);
    app.buildTree();
    return app.execApp();
}