#include <iostream>
#include <algorithm>
#include <vector>
#include <windows.h>
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::vector<int> v{ 4,7,9,14,12 };
    std::cout << "Входные данные";
    for (auto c : v) {
        std::cout << c << " ";
    }
    std::cout << "\n";
    std::cout << "Выходные данные ";
    std::for_each(v.begin(), v.end(), [&](int& i) {
        if (i % 2 != 0) {
            i *= 3;
        }
        });
    for (auto c : v) {
        std::cout << c << " ";
    }
    return 0;
}

