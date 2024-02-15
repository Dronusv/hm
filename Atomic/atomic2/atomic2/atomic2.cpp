
#include <Windows.h>
#include <iostream>
#include <thread>
#include<vector>
#include<mutex>
#include <atomic>
#include <chrono>

using namespace std;

class consol_parameter
{
public:
    static void SetColor(int text, int background)
    {
        SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
    }
    static void SetPosition(int x, int y)
    {
        COORD point;
        point.X = x;
        point.Y = y;
        SetConsoleCursorPosition(hStdOut, point);
    }
private:
    static HANDLE hStdOut;
};
HANDLE consol_parameter::hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);



std::mutex m;
std::atomic<int> q=1;

void ProgresBar() {
    int size = 15;
    int numb = 0;
    m.lock();
    std::cout <<q<<"\t #" << std::this_thread::get_id() << "\n";
    numb = q;
    ++q;
    m.unlock();
    std::this_thread::sleep_for(1000ms);
    consol_parameter cr;
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 15; ++i) {
        m.lock();
        std::this_thread::sleep_for(70ms);
        cr.SetColor(0, 15);
        cr.SetPosition(20+i, numb);     
        std::cout << " ";
        m.unlock();
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elaspend_seconds = end - start;
    m.lock();
    cr.SetColor(15, 0);
    cr.SetPosition(40, numb);
    std::cout << elaspend_seconds.count()<<"s";
    m.unlock();
   
}




int main()
{

   std::cout << "N \t ID \t    PROGRES BAR \tTime \n";
   int N = 4;
   std::vector<std::thread> v(N);
   for (int i = 0; i < 4; ++i) {
       v[i]=std::thread(ProgresBar);
   }
   for (int i = 0; i < 4; ++i) {
       v[i].join();
   }
   consol_parameter cr;
   cr.SetColor(15, 0);
   cr.SetPosition(6, 6);
}

