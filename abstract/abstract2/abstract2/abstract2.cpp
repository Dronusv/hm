#include <iostream>
#include <string>
#include <fstream>
class adress {
private:
    std::string city;
    std::string street;
    int house;
    int flat;


public:
    adress() {
        city = "Неизвестно";
        street = "Неизвестно";
        house = 0;
        flat = 0;
    };
    adress(std::string city, std::string street, int house, int flat) {
        this->city = city;
        this->street = street;
        this->house = house;
        this->flat = flat;
    };
    std::string get_str_adress() {
        std::string res = city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(flat);
        return res;
    }
    std::string get_city(){
        return city;
    }
    std::string get_street() {
        return street;
    }
    int get_house() {
        return house;
    }
    int get_flat() {
        return flat;
    }
};
void sort(adress* mass, int N) {
    adress temp;
    for (int j = 1; j < N; ++j) {
        for (int i = 0; i < N - j; ++i) {
            if (mass[i].get_city() > mass[i + 1].get_city()) {
                temp = mass[i];
                mass[i] = mass[i + 1];
                mass[i + 1] = temp;
            }
        }
    }
}
int main()
{
    std::string city;
    std::string street;
    int house;
    int flat;
    std::ifstream in("in.txt");
    int N;
    in >> N;
    adress* mass = new adress[N];
    for (int i = 0; i < N; ++i) {
        in >> city;
        in >> street;
        in >> house;
        in >> flat;
        mass[i] = { city,street,house,flat };
    }
    in.close();
    sort(mass, N);
    std::ofstream out("out.txt");
    out << N << std::endl;
    for (int i = 0; i <N; ++i) {
        out << mass[i].get_str_adress() << std::endl;
    }
    out.close();

    delete[] mass;
}