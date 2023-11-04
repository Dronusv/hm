#include <iostream>
#include <exception>
using namespace std;

class smart_array {
private:
    int* arr;
    int maxsize = 0;
    int index_size = 0;
public:
    smart_array(const int& size) {
        maxsize = size;
        arr = new int[size];
    }
    ~smart_array() {
        delete[] arr;
    }
    void add_element(const int& element) {
        if (index_size + 1 > maxsize) {
            throw invalid_argument("oversize!");
        }
        arr[index_size] = element;
        ++index_size;
    }
    int get_element(const int& index_element) {
        if (index_element < 0 || index_element >= index_size) {
            throw invalid_argument("wrong index!");
        }
        return arr[index_element];
    }
    smart_array& operator =(const smart_array& rhs) {
        maxsize = rhs.maxsize;
        index_size = rhs.index_size;
        for (int i = 0; i < maxsize; ++i) {
            arr[i] = rhs.arr[i];
        }
        return *this;
    }
};

int main()
{
    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    smart_array new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

    arr = new_array;
    return 0;
}
