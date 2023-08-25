#include <windows.h>
#include <iostream>

struct address{
    std::string city;
    std::string street;
    int house;
    int flat;
    int index;
};
void getadd(const address & add) {
    std::cout << "Город: " << add.city << "\n";
    std::cout << "Улица: " << add.street << "\n";
    std::cout << "Номер дома: " << add.house << "\n";
    std::cout << "Номер квартиры: " << add.flat << "\n";
    std::cout << "Индекс: " << add.index << "\n";
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUS");
    address a{ "Москва","Арбат",12,8,123456 };
    getadd(a);
    address b{ "Ижевск","Пушкина",59,143,953769 };
    getadd(b);
        
}

