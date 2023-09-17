
#include <windows.h>
#include <iostream>

int function(std::string str, int forbidden_length) {
    if (str.size() != forbidden_length) {
        return str.size();
    }
    else {
        throw std::invalid_argument("Вы ввели слово запретной длины! До свидания");
    }   
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int fl=0;
    std::string str;
    std::cout << "Введите запретную длину: ";
    std::cin >> fl;
    try {
        for (;;) {
            std::cout << "Введите слово: ";
            std::cin >> str;
            function(str, fl);
        }
    }
    catch (std::invalid_argument& bad_length) {
        std::cout << bad_length.what();
    }
}


