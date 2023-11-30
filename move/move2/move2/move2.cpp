#include <ostream>
#include <iostream>
#include<vector>
#include<string>
#include <algorithm>

class big_integer {
private:
    std::vector<int> v;
public:
    big_integer(int size) {
        for (int i = 0; i < size; ++i) {
            v.push_back(0);
        }
    }
    big_integer(std::string str) {
        for (auto c : str) {
            int ia = c - '0';
            v.push_back(ia);
        }
        
    }
    big_integer(const big_integer &other) {
        v = other.v;
    }
    big_integer(big_integer&& other) noexcept {
        v = std::move(other.v);
    }
    big_integer& operator=(const big_integer& other) {
        return *this = big_integer(other);
    }
    big_integer& operator=( big_integer&& other) noexcept {
        std::swap(v, other.v);
        return *this;
    }
    big_integer fmax(big_integer& lhs,big_integer & rhs) {
        if (lhs.v.size() > rhs.v.size()) {
            return lhs;
        }
        return rhs;

    }
    big_integer fmin(big_integer& lhs, big_integer& rhs) {
        if (rhs.v.size() < lhs.v.size()) {
            return rhs;
        }
        return lhs;

    }
    big_integer operator +(big_integer& lhs) {
        big_integer res = fmax(*this, lhs);
        big_integer min = fmin(*this, lhs);
        std::reverse(res.v.begin(), res.v.end());
        std::reverse(min.v.begin(), min.v.end());
        res.v.push_back(0);
        for (int i = 0; i < min.v.size(); ++i) {
            int resi= res.v[i] + min.v[i];
            int rem = 0;
            if (resi >= 10) {
                resi = resi - 10;
                rem = 1;
            }
            res.v[i] = resi;
            res.v[i + 1] += rem;
        }
        if (res.v[res.v.size() - 1] == 0) {
            res.v.pop_back();
        }
        std::reverse(res.v.begin(), res.v.end());
        return res;
    }
    big_integer operator *(big_integer &lhs) {
        big_integer rhs = *this;
        big_integer lhs2 = lhs;
        std::reverse(rhs.v.begin(), rhs.v.end());
        std::reverse(lhs2.v.begin(), lhs2.v.end());
        int length = rhs.v.size() + lhs.v.size();
        big_integer res(length+1);
        for (int i = 0; i < rhs.v.size(); i++) {
            for (int j = 0; j < lhs2.v.size(); j++) {
                res.v[i + j] += rhs.v[i] * lhs2.v[j];
            }
        }
        for (int i = 0; i < length; i++)
        {
            res.v[i+ 1] += res.v[i] / 10;
            res.v[i] %= 10;
        }


        while (res.v[length] == 0) {
            res.v.pop_back();
            length--;
        }
        std::reverse(res.v.begin(), res.v.end());
        return res;
    }
    friend std::ostream& operator <<(std::ostream& os, const big_integer& bi);
};
std::ostream& operator <<(std::ostream& os, const big_integer& bi) {
    
    for (auto c : bi.v) {
        os << c << " ";
    }
    return os;
}

int main()
{
    
    auto number1 = big_integer("3841983");
    auto number2 = big_integer("234823987");
    auto result2 = number1 + number2;
    auto result = number1 * number2;
    big_integer number3(number2);
    std::cout << number1<<"\n";
    std::cout << number2 << "\n";
    std::cout << number3 << "\n";
    std::cout << result<<"\n";
    std::cout << result2;
}

