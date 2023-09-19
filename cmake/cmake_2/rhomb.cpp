#include"rhomb.h"


rhomb ::rhomb() {
    side = 4;
    name = "Ромб";
    a = 0, b = 0, c = 0, d = 0;
    A = 0, B = 0, C = 0, D = 0;
}
rhomb::rhomb(int a, int A, int B) {
    side = 4;
    name = "Ромб";
    this->a = a;
    this->b = a;
    this->c = a;
    this->d = a;
    this->A = A;
    this->B = B;
    this->C = A;
    this->D = B;
}
bool rhomb::check() {
    if (parallelogram::check() == true && a == b && a == c && a == d) {
        return true;

    }
    return false;
}
