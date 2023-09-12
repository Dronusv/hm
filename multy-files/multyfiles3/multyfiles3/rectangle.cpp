#include "rectangle.h"
rectangle ::rectangle() {
    side = 4;
    name = "Прямоугольник";
    a = 0, b = 0, c = 0, d = 0;
    A = 0, B = 0, C = 0, D = 0;
}
rectangle::rectangle(int a, int b) {
    side = 4;
    name = "Прямоугольник";
    this->a = a;
    this->b = b;
    this->c = a;
    this->d = b;
    A = 90, B = 90, C = 90, D = 90;
}
bool rectangle::check() {
    if (parallelogram::check() == true && A == B && A == C && A == D && A == 90) {
        return true;

    }
    return false;
}
