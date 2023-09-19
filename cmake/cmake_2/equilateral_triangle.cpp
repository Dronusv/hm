#include"equilateral_triangle.h"


equilateral_triangle ::equilateral_triangle(int a) {
    side = 3;
    name = "Равноcторонний треугольник";
    this->a = a;
    b = a;
    c = a;
    A = 60, B = 60, C = 60;
}
bool equilateral_triangle ::check() {
    if (isosceles_triangle::check() == true && a == b && A == B && A == 60) {
        return true;

    }
    return false;
}
