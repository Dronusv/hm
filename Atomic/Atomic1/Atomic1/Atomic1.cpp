
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>

using namespace std;

std::atomic<int> x = 0;
std::mutex m;

void func1() {

    for (int i = 0; i < 1000; ++i) {
        ++x;
        //x.store(x.load() + 1);
        m.lock();
        std::cout << "Plus one!  " << x << "\n";
        m.unlock();
    }
}
void func2() {
    int q = 0;
    while (true) {
        
        if (x > 0) {
            --x;
            //x.store(x.load() - 1);
            m.lock();
            std::cout << "Minus one! " << x << "\n";
            m.unlock();
            ++q;
            
        }
        if (q == 1000) {
            break;
        }
        
        
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

