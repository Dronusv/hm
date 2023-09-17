#include "isosceles_triangle.h"
#include "ex.h"
isosceles_triangle :: isosceles_triangle() {
    side = 3;
    name = "Равнобедренный Треугольник";
    a = 0, b = 0, c = 0;
    A = 0, B = 0, C = 0;
}
isosceles_triangle::isosceles_triangle(int a, int b, int A, int B) {
    side = 3;
    name = "Равнобедренный треугольник";
    this->a = a;
    this->b = b;
    c = this->a;
    this->A = A;
    this->B = B;
    C = this->A;
    check();
}
bool isosceles_triangle::check(){
    if (triangle::check() == true && a == c && A == C) {
        return true;

    }
    if (a != c) {
        throw ex("Стороны не равны");
    }
    if (A != C) {
        throw ex("углы не равны");
    }
    return false;
}
