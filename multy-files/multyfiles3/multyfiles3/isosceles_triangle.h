#pragma once
#include "Triangle.h"

class isosceles_triangle :public triangle {
public:
    isosceles_triangle();
    isosceles_triangle(int a, int b, int A, int B);
    bool check()override;
};