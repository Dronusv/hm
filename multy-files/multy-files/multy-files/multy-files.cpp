#include "mathop.h"
#include <iostream>
#include <windows.h>

int main()
{    
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int a, b,op;
    std::cout << "Введите первое число: ";
    std::cin >> a;
    std::cout << "Введите второе число: ";
    std::cin >> b;
    std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    std::cin >> op;
    switch (op) {
    case 1: 
        std::cout << a << " + " << b << " = " << addition(a, b);
        break;
    case 2:
        std::cout << a << " - " << b << " = " << subtraction(a, b);
        break;
    case 3:
        std::cout << a << " * " << b << " = " << multiplication(a, b);
        break;
    case 4:
        std::cout << a << " / " << b << " = " << division(a, b);
        break;
    case 5:
        std::cout << a << " в степени " << b << " = " << degree(a, b);
        break;
    default:
        std::cout << "Неправильный ввод!";
        break;
    }

    
        
}

