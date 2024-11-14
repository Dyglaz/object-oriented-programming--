#include <iostream>
#include <string>
#include <vector>
#include "Application.h"
#include "Base.h"
#include "Creator.h"

using namespace std;

Creator::Creator(Base* parent, string name) : Base(parent, name){}