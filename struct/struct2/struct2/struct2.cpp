#include <windows.h>
#include <iostream>
struct bankacc {
    
    int number;
    std::string name;
    double money;
};
void Change_bankacc(bankacc& acc,int new_money) {
    acc.money = new_money;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    bankacc b;
    std::cout << "Введите номер счёта: ";
    std::cin >> b.number;
    std::cout << "Введите имя владельца: ";
    std::cin >> b.name;
    std::cout << "Введите баланс: ";
    std::cin >> b.money;
    std::cout << "Введите новый баланс: ";
    int m;
    std::cin >> m;
    Change_bankacc(b, m);
    std::cout << "Ваш счет: " << b.name << ", " << b.number << ", " << b.money;
}

