#include <iostream>
#include <windows.h>
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::cout << "������� ���: ";
	std::string name;
	std::cin >> name;
	std::cout << "������������, " << name << "!";


	return 0;
}