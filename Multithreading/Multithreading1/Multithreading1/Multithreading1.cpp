
#include <iostream>
#include <thread>

using namespace std;

int x = 0;

void func1() {
    for (int i = 0; i < 20; ++i) {
        ++x;
        std::cout << "Plus one!  " << x << "\n";
        std::this_thread::sleep_for(1000ms);
    }
}
void func2() {
    while (x > 0) {
        --x;
        std::cout << "Minus one! " << x << "\n";
        std::this_thread::sleep_for(2000ms);
    }
}

int main()
{
    std::thread t1(func1);
    std::thread t2(func2);
    t1.join();
    t2.join();


    return 0;
}