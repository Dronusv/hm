#include <windows.h>
#include <iostream>
#include"Figure.h"
#include"Triangle.h"
#include"quadrilateral.h"
#include"right_triangle.h"
#include"isosceles_triangle.h"
#include"equilateral_triangle.h"
#include"parallelogram.h"
#include "rectangle.h"
#include"rhomb.h"
#include "square.h"



void print_info_triangle(triangle* t) {
    std::cout << t->getname() << ":" << std::endl;
    std::cout << "Стороны: a=" << t->get_a() << " b=" << t->get_b() << " c=" << t->get_c() << std::endl;
    std::cout << "Углы: A=" << t->get_A() << " B=" << t->get_B() << " C=" << t->get_C() << std::endl;

}
void print_info_quadrilateral(quadrilateral* t) {
    std::cout << t->getname() << ":" << std::endl;
    std::cout << "Стороны: a=" << t->get_a() << " b=" << t->get_b() << " c=" << t->get_c() << " d=" << t->get_d() << std::endl;
    std::cout << "Углы: A=" << t->get_A() << " B=" << t->get_B() << " C=" << t->get_C() << " D=" << t->get_D() << std::endl;


}


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    figure f;
    triangle t(10, 20, 30, 50, 60, 70);
    right_triangle rt(10, 20, 30, 50, 40);
    isosceles_triangle it(10, 20, 50, 60);
    equilateral_triangle et(30);
    quadrilateral q(10, 20, 30, 40, 50, 60, 70, 80);
    parallelogram p(20, 30, 30, 40);
    rectangle r(10, 20);
    square s(20);
    f.print_info();
    std::cout << std::endl;
    t.print_info();
    std::cout << std::endl;
    rt.print_info();
    std::cout << std::endl;
    it.print_info();
    std::cout << std::endl;
    et.print_info();
    std::cout << std::endl;
    q.print_info();
    std::cout << std::endl;
    p.print_info();
    std::cout << std::endl;
    r.print_info();
    std::cout << std::endl;
    s.print_info();
}