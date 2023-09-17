#include "parallelogram.h"
#include "ex.h"
parallelogram ::parallelogram() {
    side = 4;
    name = "Параллелограмм";
    a = 0, b = 0, c = 0, d = 0;
    A = 0, B = 0, C = 0, D = 0;
}
parallelogram::parallelogram(int a, int b, int A, int B) {
    side = 4;
    name = "Параллелограмм";
    this->a = a;
    this->b = b;
    this->c = a;
    this->d = b;
    this->A = A;
    this->B = B;
    this->C = A;
    this->D = B;
    check();
}
bool parallelogram::check() {
    if (quadrilateral::check() == true && a == c && b == d && A == C && B == D) {
        return true;
    }
    if (a != c && b != d) {
        throw "Стороны попарно не равны";
    }
    if (A != C && B != D) {
        throw "Углы попарно не равны";
    }
    return false;
}
