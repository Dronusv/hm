#include<string>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>

bool srtit(std::pair<char, int>& a, std::pair<char, int>& b) {
    return a.second > b.second;
}

void sortm(std::map<char,int>& m ) {
    std::vector<std::pair<char, int>> v;
    for(auto it :m){
        v.push_back(it);
    }
    std::sort(v.begin(), v.end(), srtit);
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i].first <<": "<<v[i].second<<"\n";
    }
}
int main()
{
    std::string str;
    std::map<char, int> m;
    std::getline(std::cin, str);
    for (int i = 0; i < str.size(); ++i) {
        m[str[i]] = 0;
    }
    for (int i = 0; i < str.size(); ++i) {
        m[str[i]]++;
    }
    sortm(m);
}

