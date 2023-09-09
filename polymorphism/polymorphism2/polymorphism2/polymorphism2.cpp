#include <windows.h>
#include <iostream>

class figure {
protected:
    int side = 0;
    std::string name = "Фигура";
public:
    figure() {
    }
    int getside() {
        return  side;
    }
    std::string getname() {
        return name;
    }

};
class triangle :public figure {
protected:
    int a, b, c;
    int A, B, C;
public:
    triangle() {
        side = 3;
        name = "Треугольник";
        a=0, b=0, c = 0;
        A=0, B=0, C = 0;
    }
    triangle(int a, int b, int c, int A, int B, int C) {
        side = 3;
        name = "Треугольник";
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
    int get_a() {
        return a;
    }
    int get_b() {
        return b;
    }
    int get_c() {
        return c;
    }
    int get_A() {
        return A;
    }
    int get_B() {
        return B;
    }
    int get_C() {
        return C;
    }
};
class quadrilateral :public figure {
protected:
    int a, b, c,d;
    int A, B, C,D;
public:
    quadrilateral() {
        side = 4;
        name = "Четырехугольник";
        a=0, b=0, c=0,d = 0;
        A=0, B=0, C=0,D = 0;
    }
    quadrilateral (int a, int b, int c,int d, int A, int B, int C,int D) {
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
    }
    int get_a() {
        return a;
    }
    int get_b() {
        return b;
    }
    int get_c() {
        return c;
    }
    int get_d() {
        return d;
    }
    int get_A() {
        return A;
    }
    int get_B() {
        return B;
    }
    int get_C() {
        return C;
    }
    int get_D() {
        return D;
    }
};
class right_triangle : public triangle {
public:
    right_triangle(int a, int b, int c, int A, int B) {
        side = 3;
        name = "Прямоугольный треугольник";
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        C = 90;
    }
};
class isosceles_triangle :public triangle {
    public:
        isosceles_triangle() {
            side = 3;
            name = "Равнобедренный Треугольник";
            a = 0, b = 0, c = 0;
            A = 0, B = 0, C = 0;
        }
        isosceles_triangle(int a, int b, int A, int B) {
            side = 3;
            name = "Равнобедренный треугольник";
            this->a = a;
            this->b = b;
            c = this->a;
            this->A = A;
            this->B = B;
            C = this->A;
        }
};
class equilateral_triangle : public isosceles_triangle {
public:
    equilateral_triangle(int a) {
        side = 3;
        name = "Равноcторонний треугольник";
        this->a = a;
        b = a;
        c = a;
        A=60, B=60, C = 60;
    }

};
class parallelogram : public quadrilateral {
public:
    parallelogram() {
        side = 4;
        name = "Параллелограмм";
        a = 0, b = 0, c = 0, d = 0;
        A = 0, B = 0, C = 0, D = 0;
    }
    parallelogram(int a, int b, int A, int B) {
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
    }

};
class rectangle : public parallelogram {
public:
    rectangle() {
        side = 4;
        name = "Прямоугольник";
        a = 0, b = 0, c = 0, d = 0;
        A = 0, B = 0, C = 0, D = 0;
    }
    rectangle(int a, int b) {
        side = 4;
        name = "Прямоугольник";
        this->a = a;
        this->b = b;
        this->c = a;
        this->d = b;
        A = 90, B = 90, C = 90, D = 90;
    }
};
class rhomb : public parallelogram {
public:
    rhomb() {
        side = 4;
        name = "Ромб";
        a = 0, b = 0, c = 0, d = 0;
        A = 0, B = 0, C = 0, D = 0;
    }
    rhomb(int a, int A, int B) {
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

};
class square :public rhomb {
public:
    square() {
        side = 4;
        name = "Квадрат";
        a = 0, b = 0, c = 0, d = 0;
        A = 0, B = 0, C = 0, D = 0;
    }
    square(int a) {
        side = 4;
        name = "Квадрат";
        this->a = a;
        this->b = a;
        this->c = a;
        this->d = a;
        A = 90, B = 90, C = 90, D = 90;
    }
};

    void print_info_triangle(triangle* t) {
        std::cout << t->getname() << ":" << std::endl;
        std::cout << "Стороны: a=" << t->get_a() << " b=" << t->get_b() << " c=" << t->get_c() << std::endl;
        std::cout << "Углы: A=" << t->get_A() << " B=" << t->get_B() << " C=" << t->get_C() << std::endl;
        
    }
    void print_info_quadrilateral(quadrilateral* t) {
        std::cout << t->getname() << ":" << std::endl;
        std::cout << "Стороны: a=" << t->get_a() << " b=" << t->get_b() << " c=" << t->get_c()<<" d=" << t->get_d() << std::endl;
        std::cout << "Углы: A=" << t->get_A() << " B=" << t->get_B() << " C=" << t->get_C()<<" D="<<t->get_D() << std::endl;
        
       
    }


    int main()
    {
        SetConsoleOutputCP(1251);
        SetConsoleCP(1251);
        figure f;
        triangle t(10, 20, 30, 50, 60, 70);
        right_triangle rt(10, 20, 30, 50, 60);
        isosceles_triangle it(10, 20, 50, 60);
        equilateral_triangle et(30);
        quadrilateral q(10, 20, 30, 40, 50, 60, 70, 80);
        parallelogram p(20, 30, 30, 40);
        rectangle r(10, 20);
        square s(20);
        print_info_triangle(&t);
        std::cout << std::endl;
        print_info_triangle(&rt);
        std::cout << std::endl;
        print_info_triangle(&it);
        std::cout << std::endl;
        print_info_triangle(&et);
        std::cout << std::endl;
        print_info_quadrilateral(&q);
        std::cout << std::endl;
        print_info_quadrilateral(&p);
        std::cout << std::endl;
        print_info_quadrilateral(&r);
        std::cout << std::endl;
        print_info_quadrilateral(&s);
    }

