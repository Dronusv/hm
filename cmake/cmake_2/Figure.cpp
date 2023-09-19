#include <iostream>
#include"Figure.h"
figure::figure() {
    side = 0;
    name = "Фигура";
}
int figure::getside() {
    return  side;
}
std::string figure::getname() {
    return name;
}
bool figure::check() {
    if (side == 0) {
        return true;
    }
    return false;
}
void figure::print_info() {
    std::cout << name << ": " << std::endl;
    if (check() == true) {
        std::cout << "Правильная" << std::endl;
    }
    else {
        std::cout << "Неправильная" << std::endl;
    }
    std::cout << "Количество сторон: " << side << std::endl;
}


