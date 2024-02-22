
#include <iostream>
#include <thread>
#include <mutex>
#include <time.h>
#include <Windows.h>



class data {
public:
    std::string name;
    int age;
    std::mutex m;
    void print() {
        std::cout << age << " " << name<<"\n";
    }
};

void swap_lock(data &lhs,data& rhs) {
    std::lock(lhs.m, rhs.m);

    data temp;
    temp.age = lhs.age;
    temp.name = lhs.name;
    lhs.age = rhs.age;
    lhs.name = rhs.name;
    rhs.age = temp.age;
    rhs.name = temp.name;
    
    rhs.m.unlock();
    lhs.m.unlock();
    
}

void swap_scoped_lock(data& lhs, data& rhs) {
    std::scoped_lock sl(lhs.m,rhs.m);
    data temp;
    temp.age = lhs.age;
    temp.name = lhs.name;
    lhs.age = rhs.age;
    lhs.name = rhs.name;
    rhs.age = temp.age;
    rhs.name = temp.name;
}

void swap_unique_lock(data& lhs, data& rhs) {
    std::unique_lock<std::mutex> ul(lhs.m,std::defer_lock);
    std::unique_lock<std::mutex> ul2(rhs.m,std::defer_lock);
    std::lock(ul, ul2);
    data temp;
    temp.age = lhs.age;
    temp.name = lhs.name;
    lhs.age = rhs.age;
    lhs.name = rhs.name;
    rhs.age = temp.age;
    rhs.name = temp.name;
    
}

int main()
{
    data a;
    a.age = 10;
    a.name = "a";
    data b;
    b.age = 12;
    b.name="b";
    swap_lock(a, b);
    a.print();
    b.print();
    swap_scoped_lock(a, b);
    a.print();
    b.print();
    swap_unique_lock(a, b);
    a.print();
    b.print();
    swap_unique_lock(a, b);
    a.print();
    b.print();
    
}

