
#include <windows.h>
#include <iostream>

class figure {
protected: 
    int side=0;
    std::string name="Фигура";
public:
    figure() {
    }
    int getside(){
        return  side;
    }
    std::string getname() {
        return name;
    }
    
};
class triangle :public figure {
public:
    triangle() {
        side = 3;
        name = "Трехугольник";
    }
};
class quadrilateral :public figure {
public:
    quadrilateral() {
        side = 4;
        name = "Четырехугольник";
    }
};
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    figure f;
    triangle triangle;
    quadrilateral q;
    std::cout << "Количество сторон: \n";
    std::cout << f.getname()<<": " << f.getside() << std::endl;
    std::cout << triangle.getname()<<": " << triangle.getside() << std::endl;
    std::cout << q.getname()<<": " << q.getside() << std::endl;
}

