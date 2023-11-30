#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
class sum {
public:
    void operator()( const int& a) {
        int res=0;
            if (a % 3 == 0) {
                summ += a;
            }
    }
    int get_sum() {
        return summ;
    }
private:
    int summ = 0;
};
class count {
public:
    void operator()(const int & a) {
            if (a%3 == 0) {
                ++countt;
            }
    }
    int get_count() {
        return countt;
    }
private:
    int countt = 0;
};
int main()
{
    std::vector<int> v{ 4, 1, 3, 6, 25, 54 };
    std::list<int> l{ 1,2,3,4,5,6 };
    sum x;
    sum z;
    count y;
    x = std::for_each(v.begin(), v.end(), x);
    y = std::for_each(v.begin(), v.end(), y);
    z = std::for_each(l.begin(), l.end(), z);
    
    std::cout << "[OUT] : get_sum() = " << x.get_sum() << std::endl;
    std::cout << "[OUT] : get_count() = " << y.get_count() << std::endl;
}

