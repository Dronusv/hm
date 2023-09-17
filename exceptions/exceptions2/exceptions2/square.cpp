#include "square.h"
#include "ex.h"

square ::square() {
    side = 4;
    name = "Квадрат";
    a = 0, b = 0, c = 0, d = 0;
    A = 0, B = 0, C = 0, D = 0;
}
square::square(int a) {
    side = 4;
    name = "Квадрат";
    this->a = a;
    this->b = a;
    this->c = a;
    this->d = a;
    A = 90, B = 90, C = 90, D = 90;
    check();
}
bool square::check(){
    if (rhomb::check() == true && A == B && A == C && A == D && A == 90) {
        return true;

    }
    throw ex("Не все углы равны 90");
    return false;
}
