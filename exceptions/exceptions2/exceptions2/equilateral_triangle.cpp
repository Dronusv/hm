#include"equilateral_triangle.h"
#include "ex.h"

equilateral_triangle ::equilateral_triangle(int a) {
    side = 3;
    name = "�����c�������� �����������";
    this->a = a;
    b = a;
    c = a;
    A = 60, B = 60, C = 60;
    check();
}
bool equilateral_triangle ::check() {
    if (isosceles_triangle::check() == true && a == b && A == B && A == 60) {
        return true;

    }
    if (a != b) {
        throw ex("������� �� �����");
    }
    if (A != B&&A!=60) {
        throw ex("�� ��� ���� �� ����� 60");
    }
    
    return false;
}
