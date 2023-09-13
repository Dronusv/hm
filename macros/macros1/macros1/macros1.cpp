
#include <windows.h>
#include <iostream>

#define MODE 1
#if !defined MODE
#error MODE NOT DEFINED
#endif // !defined MODE
#if MODE == 0
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::cout << "Работаю в режиме тренировки";
}
#elif MODE==1

int add(int a, int b) {
	return a + b;
}
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::cout << "Работаю в боевом режиме\n";
	int a, b;
	std::cout << "Введите число 1: ";
	std::cin >> a;
	std::cout << "Введите число 2: ";
	std::cin >> b;
	std::cout << "Результат сложения : " << add(a, b);
}
#else
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::cout << "Неизвестный режим. Завершение работы";
}
#endif // MODE ==0





