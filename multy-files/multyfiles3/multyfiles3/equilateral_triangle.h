#pragma once
#include "isosceles_triangle.h"
class equilateral_triangle : public isosceles_triangle {
public:
    equilateral_triangle(int a);
    bool check()override;
};