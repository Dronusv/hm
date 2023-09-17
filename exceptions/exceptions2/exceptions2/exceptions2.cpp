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
#include "ex.h"


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
    try
    {
        triangle t(10, 20, 30, 50, 60, 50);
        std::cout << t.getname() << " (стороны " << t.get_a() << ", " << t.get_b() << ", " << t.get_c() << "; углы " << t.get_A() << ", " << t.get_B() << ", " << t.get_C() << ") создан\n";
    }
    catch (const ex& e) {
        std::cout<<"Ошибка создания фигуры.Причина: " << e.what()<<"\n";
    }
    try
    {
        right_triangle rt(10, 20, 30, 50, 40);
        std::cout << rt.getname() << " (стороны " << rt.get_a() << ", " << rt.get_b() << ", " << rt.get_c() << "; углы " << rt.get_A() << ", " << rt.get_B() << ", " << rt.get_C() << ") создан\n";
    }
    catch (const ex& e) {
        std::cout << "Ошибка создания фигуры.Причина: " << e.what() << "\n";
    }
    try
    {
        isosceles_triangle it(10, 20, 50, 80);
        std::cout << it.getname() << " (стороны " << it.get_a() << ", " << it.get_b() << ", " << it.get_c() << "; углы " << it.get_A() << ", " << it.get_B() << ", " << it.get_C() << ") создан\n";
    }
    catch (const ex& e) {
        std::cout << "Ошибка создания фигуры.Причина: " << e.what() << "\n";
    }
    try
    {
        equilateral_triangle et(30);
        std::cout << et.getname() << " (стороны " << et.get_a() << ", " << et.get_b() << ", " << et.get_c() << "; углы " << et.get_A() << ", " << et.get_B() << ", " << et.get_C() << ") создан\n";
    }
    catch (const ex& e) {
        std::cout << "Ошибка создания фигуры.Причина: " << e.what() << "\n";
    }
    try
    {
        quadrilateral q(10, 20, 30, 40, 90, 90, 90, 90);
        std::cout << q.getname() << " (стороны " << q.get_a() << ", " << q.get_b() << ", " << q.get_c()<<", " << q.get_d() << "; углы " << q.get_A() << ", " << q.get_B() << ", " << q.get_C()<<", "<<q.get_D() << ") создан\n";
    }
    catch (const ex& e) {
        std::cout << "Ошибка создания фигуры.Причина: " << e.what() << "\n";
    }
    try
    {
        parallelogram p(20, 30, 30, 40);
        std::cout << p.getname() << " (стороны " << p.get_a() << ", " << p.get_b() << ", " << p.get_c() << ", " << p.get_d() << "; углы " << p.get_A() << ", " << p.get_B() << ", " << p.get_C() << ", " << p.get_D() << ") создан\n";
    }
    catch (const ex& e) {
        std::cout << "Ошибка создания фигуры.Причина: " << e.what() << "\n";
    }
    try
    {
        rectangle r(10, 20);
        std::cout << r.getname() << " (стороны " << r.get_a() << ", " << r.get_b() << ", " << r.get_c() << ", " << r.get_d() << "; углы " << r.get_A() << ", " << r.get_B() << ", " << r.get_C() << ", " << r.get_D() << ") создан\n";
    }
    catch (const ex& e) {
        std::cout << "Ошибка создания фигуры.Причина: " << e.what() << "\n";
    }
    try
    {
        rhomb rh(20,90,90);
        std::cout << rh.getname() << " (стороны " << rh.get_a() << ", " << rh.get_b() << ", " << rh.get_c() << ", " << rh.get_d() << "; углы " << rh.get_A() << ", " << rh.get_B() << ", " << rh.get_C() << ", " << rh.get_D() << ") создан\n";
    }
    catch (const ex& e) {
        std::cout << "Ошибка создания фигуры.Причина: " << e.what() << "\n";
    }
    try
    {
        square s(20);
        std::cout << s.getname() << " (стороны " << s.get_a() << ", " << s.get_b() << ", " << s.get_c() << ", " << s.get_d() << "; углы " << s.get_A() << ", " << s.get_B() << ", " << s.get_C() << ", " << s.get_D() << ") создан\n";
    }
    catch (const ex& e) {
        std::cout << "Ошибка создания фигуры.Причина: " << e.what() << "\n";
    }
}