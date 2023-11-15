
#include <iostream>
#include<vector>
#include <algorithm>


void sortv(std::vector<int>& v) {
    std::vector<int>::iterator ip;
    std::sort(v.begin(), v.end());
    ip = std::unique(v.begin(), v.end());
    v.resize(std::distance(v.begin(), ip));
}

int main()
{
    std::vector<int> v{ 1, 1, 2, 5 ,6, 1, 2, 4 };
    sortv(v);
    for (auto c : v) {
        std::cout << c << " ";
    }
}
