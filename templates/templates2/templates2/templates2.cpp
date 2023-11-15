
#include <vector>
#include <iostream>

template<class T> 
class table {
private:
    std::vector<std::vector<T>> v;
    int r = 0;
    int c= 0;
public:
    table(int row, int colum) {
       r = row;
       c = colum;
        for (int i = 0; i < row; i++) {
            v.push_back(std::vector<int>(colum));
        }
    }
    
    std::vector<int>& operator[](int col) {
        return v[col];
    }
    
    const int Size() {
        return r * c;
    }
};
int main()
{
    auto test = table<int>(2, 3);
    test[1][0] = 4;
    std::cout << test[1][0]<<" "<<test.Size();
    
}

