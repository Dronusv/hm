#include <set>
#include <iostream>
#include <vector>
int main()
{
    int size = 0;
    std::cin >> size;
    std::set<int> s;
    for (int i = 0; i < size; ++i) {
        int numb = 0;
        std::cin >> numb;
        s.insert(numb);
    }
    std::vector<int> v;
    for (auto it : s) {
        v.push_back(it);
    }
    for (int i = v.size() - 1; i >= 0; --i) {
        std::cout << v[i]<<"\n";
    }
}

