#include <iostream>
#include <vector>
class get_sum {
public:
    int operator()(const std::vector<int>& v) {
        int res=0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] % 3 == 0) {
                res+=v[i];
            }
        }
        return res;
    }
};
class get_count {
public:
    int operator()(const std::vector<int>& v) {
        int res = 0;
        for (int i = 0; i < v.size();++i) {
            if (v[i] %3 == 0) {
                ++res;  
            }
        }
        return res;
    }
};
int main()
{
    std::vector<int> v{ 4, 1, 3, 6, 25, 54 };
    get_sum get_sum;
    get_count get_count;
    std::cout<<get_sum(v)<<" ";
    std::cout << get_count(v);
}

