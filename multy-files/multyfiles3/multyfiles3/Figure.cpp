#include <iostream>
#include"Figure.h"
figure::figure() {
    side = 0;
    name = "������";
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
        std::cout << "����������" << std::endl;
    }
    else {
        std::cout << "������������" << std::endl;
    }
    std::cout << "���������� ������: " << side << std::endl;
}


