﻿#include <iostream>
#include"counter.h"
#include <windows.h>
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
	std::string answer;
	std::cin >> answer;

	if (answer == "да") {
		std::cout << "Введите начальное значение счетчика: ";
		int c;
		std::cin >> c;
		Counter conc(c);
		for (;;) {
			std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
			char com;
			std::cin >> com;
			if (com == '+') {
				conc.plus();
			}
			if (com == '-') {
				conc.minus();
			}
			if (com == '=') {
				std::cout << conc.getc() << std::endl;
			}
			if (com == 'x') {
				break;
			}
		}
	}
	else {
		Counter conc;
		for (;;) {
			std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
			char com;
			std::cin >> com;
			if (com == '+') {
				conc.plus();
			}
			if (com == '-') {
				conc.minus();
			}
			if (com == '=') {
				std::cout << conc.getc() << std::endl;
			}
			if (com == 'x') {
				break;
			}
		}
	}



}
