#pragma once
#include "Figure.h"
class triangle :public figure {
protected:
    int a, b, c;
    int A, B, C;
public:
    triangle();
    triangle(int a, int b, int c, int A, int B, int C);
    int get_a();
    int get_b();
    int get_c();
    int get_A();
    int get_B();
    int get_C();
    bool check() override;
    void print_info() override;
};