#include "quadrilateral.h"
#include "ex.h"


quadrilateral ::quadrilateral() {
        side = 4;
        name = "Четырехугольник";
        a = 0, b = 0, c = 0, d = 0;
        A = 0, B = 0, C = 0, D = 0;
    }
quadrilateral::quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) {
        side = 4;
        name = "Четырехугольник";
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
        check();
    }
    int quadrilateral::get_a() {
        return a;
    }
    int quadrilateral::get_b() {
        return b;
    }
    int quadrilateral::get_c() {
        return c;
    }
    int quadrilateral::get_d() {
        return d;
    }
    int quadrilateral::get_A() {
        return A;
    }
    int quadrilateral::get_B() {
        return B;
    }
    int quadrilateral::get_C() {
        return C;
    }
    int quadrilateral::get_D() {
        return D;
    }
    bool quadrilateral::check() {
        if (side == 4 && (A + B + C + D) == 360) {
            return true;

        }
        throw ex("Сумма углов не равна 360");
        return false;
    }
       void quadrilateral::print_info()  {
        std::cout << name << ": " << std::endl;
        if (check() == true) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << side << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }
