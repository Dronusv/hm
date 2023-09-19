#pragma once
#include <iostream>
class figure {
protected:
    int side;
    std::string name;
public:
    figure();
    int getside();
    std::string getname();
    virtual bool check();
    virtual void print_info();
};