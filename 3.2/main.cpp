#include <stdlib.h>
#include <stdio.h>
#include "klass.h"
int main() {
    Application app(nullptr);
    app.buildTree();
    return app.execApp();
}