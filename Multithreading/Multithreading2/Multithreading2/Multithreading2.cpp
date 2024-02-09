
#include <thread>
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <execution>
#include <exception>

using namespace std;


void exec2(std::vector<int>& v1, std::vector<int>& v2, std::vector<int>& res, int start, int end) {

   
    for (int i=start ; i < end;++i) {
        res[i]=v1[i] + v2[i];
        
    }
}

auto potok(int sizeVector, int numberPotok) {


    std::vector<int> v1(sizeVector);
    std::vector<int> v2(sizeVector);
    std::vector<int> res(sizeVector);

    auto start = std::chrono::steady_clock::now();
    std::vector<std::thread> v(numberPotok);
    int st = 0;
    int en = sizeVector / numberPotok;
    for (int i = 0; i < numberPotok; ++i) {

        v[i] = std::thread(exec2, std::ref(v1), std::ref(v2), std::ref(res), st, en);
        st = en;
        en = +en;
    }

    for (int i = 0; i < v.size(); ++i) {
        v[i].join();
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elaspend_seconds = end - start;

    return elaspend_seconds.count();

}


int main()
{
    try {
        int n = std::thread::hardware_concurrency();
        std::cout << n << " concurrent threads are supported.\n";

        std::cout << "\t\t1000 \t\t10000 \t\t100000 \t\t 1000000\n";

        std::cout << "1 potoka";
        std::cout << "\t" << potok(1000, 1) << "s";
        std::cout << "\t" << potok(10000, 1) << "s";
        std::cout << "\t" << potok(100000, 1) << "s";
        std::cout << "\t" << potok(1000000, 1) << "s\n";

        std::cout << "2 potoka";
        std::cout << "\t" << potok(1000, 2) << "s";
        std::cout << "\t" << potok(10000, 2) << "s";
        std::cout << "\t" << potok(100000, 2) << "s";
        std::cout << "\t" << potok(1000000, 2) << "s\n";

        std::cout << "4 potoka";
        std::cout << "\t" << potok(1000, 4) << "s";
        std::cout << "\t" << potok(10000, 4) << "s";
        std::cout << "\t" << potok(100000, 4) << "s";
        std::cout << "\t" << potok(1000000, 4) << "s\n";

        std::cout << "8 potoka";
        std::cout << "\t" << potok(1000, 8) << "s";
        std::cout << "\t" << potok(10000, 8) << "s";
        std::cout << "\t" << potok(100000, 8) << "s";
        std::cout << "\t" << potok(1000000, 8) << "s\n";
       
        std::cout << "16 potoka";
        std::cout << "\t" << potok(1000, 16) << "s";
        std::cout << "\t" << potok(10000, 16) << "s";
        std::cout << "\t" << potok(100000, 16) << "s";
        std::cout << "\t" << potok(1000000, 16) << "s\n";

        std::cout << "32 potoka";
        std::cout << "\t" << potok(1000, 32) << "s";
        std::cout << "\t" << potok(10000, 32) << "s";
        std::cout << "\t" << potok(100000, 32) << "s";
        std::cout << "\t" << potok(1000000, 32) << "s\n";
       
        
    }
    catch (std::exception & ex) {
        std::cout << ex.what();
    }
}

