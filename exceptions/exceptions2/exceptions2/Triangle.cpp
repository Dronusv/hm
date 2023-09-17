#include"Triangle.h"
#include"ex.h"

triangle ::triangle() {
        side = 3;
        name = "Треугольник";
        a = 0, b = 0, c = 0;
        A = 0, B = 0, C = 0;
    }
triangle::triangle(int a, int b, int c, int A, int B, int C) {
        side = 3;
        name = "Треугольник";
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
        check();
    }
    int triangle::get_a() {
        return a;
    }
    int triangle::get_b() {
        return b;
    }
    int triangle::get_c() {
        return c;
    }
    int triangle::get_A() {
        return A;
    }
    int triangle::get_B() {
        return B;
    }
    int triangle::get_C() {
        return C;
    }
    bool triangle::check()  {
        if (side == 3 && (A + B + C) == 180) {
            return true;

        }
        throw ex("сумма углов не равна 180");
        return false;
    }
    void triangle::print_info()  {
        std::cout << name << ": " << std::endl;
        if (check() == true) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << side << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    }
