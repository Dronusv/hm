
#include <vector>
#include <iostream>


template <typename T>

void move_vectors(std::vector<T>& a, std::vector<T>& b) {
    std::vector<T> tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}
int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two = {"1234"};
    move_vectors(two, one);
}

