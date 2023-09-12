#pragma once
#include "Triangle.h"
class right_triangle : public triangle {
public:
    right_triangle(int a, int b, int c, int A, int B);
    bool check()override;
};