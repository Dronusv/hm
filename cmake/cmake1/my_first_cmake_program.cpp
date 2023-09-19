#include <iostream>
#include <windows.h>
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::cout << "Введите имя: ";
	std::string name;
	std::cin >> name;
	std::cout << "Здравствуйте, " << name << "!";


	return 0;
}