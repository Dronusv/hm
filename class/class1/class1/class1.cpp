#include <iostream>

class calculator {
private:
	double num1;
	double num2;
public:
	double add() {
		return num1 + num2;
	}
	double multiply() {
		return num1 * num2;
	}
	double subtract_1_2() {
		return num2 - num1;
	}
	double subtract_2_1() {
		return num1 - num2;
	}
	double divide_1_2() {
		return num1 / num2;
	}
	double divide_2_1() {
		return num2 / num1;
	}
	bool set_num1(double num1) {
		if (num1 != 0) {
			this->num1 = num1;
			return true;
		}
		return false;
	}
	bool set_num2(double num2) {
		if (num2 != 0) {
			this->num2 = num2;
			return true;
		}
		return false;
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	calculator calc;
	int numb;
	for (;;) {
		std::cout<< "Введите num1: ";
		std::cin>> numb;
		calc.set_num1(numb);
		while (calc.set_num1(numb) == false){
				std::cout << "Неверный ввод! "<<std::endl;
				std::cout << "Введите num1: ";
				std::cin >> numb;
		}
		std::cout << "Введите num2: ";
		std::cin >> numb;
		calc.set_num2(numb);
		while (calc.set_num2(numb) == false){
				std::cout << "Неверный ввод! " << std::endl;
				std::cout << "Введите num2: ";
				std::cin >> numb;
		};
		std::cout << calc.add() << std::endl;
		std::cout << calc.multiply() << std::endl;
		std::cout << calc.subtract_1_2() << std::endl;
		std::cout << calc.subtract_2_1() << std::endl;
		std::cout << calc.divide_1_2() << std::endl;
		std::cout << calc.divide_2_1() << std::endl;
	}
}