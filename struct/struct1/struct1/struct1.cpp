
#include <iostream>


int main()
{
    setlocale(LC_ALL, "Russian");
    enum class months {
        January=1,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December,
    };
    months m;
    int month=1;
    for (;month!=0;) {
        std::cout << "Введите номер месяца: ";
        std::cin >> month;
        m = static_cast<months>(month);
        switch (m) {
        
        case months::January:
            std::cout << "Январь\n";
            break;
        case months::February :
            std::cout << "Февраль\n";
            break;
        case months::March:
            std::cout << "Март\n";
            break;
        case months::April:
            std::cout << "Апрель\n";
            break;
        case months::May:
            std::cout << "Май\n";
            break;
        case months::June:
            std::cout << "Июнь\n";
            break;
        case months::July:
            std::cout << "Июль\n";
            break;
        case months::August:
            std::cout << "Август\n";
            break;
        case months::September:
            std::cout << "Сентябрь\n";
            break;
        case months::October:
            std::cout << "Октябрь\n";
            break;
        case months::November:
            std::cout << "Ноябрь\n";
            break;
        case months::December:
            std::cout << "Декабрь\n";

            break;
        }   
    }
    std::cout << "До свидания";
}

