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

};

int main()
{
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}