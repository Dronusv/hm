#include"right_triangle.h"
#include "ex.h"
right_triangle :: right_triangle(int a, int b, int c, int A, int B) {
 side = 3;
 name = "������������� �����������";
 this->a = a;
 this->b = b;
 this->c = c;
 this->A = A;
 this->B = B;
 C = 90;
 check();
}
bool right_triangle::check() {
   if (triangle::check() == true && C == 90) {
       return true;
   
   }
   throw ex("���� � �� ����� 90");
   return false;
}
