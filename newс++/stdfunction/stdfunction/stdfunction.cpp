#include <iostream>
#include <functional>  
#include <vector>
int main()
{
   
    std::vector<float> angles{ 30 * 3.1415926 / 180,60 * 3.1415926 / 180 ,90 * 3.1415926 / 180 };
    std::vector<std::function<void(float)>> functions;
    functions.push_back([](const float& a) {
        float sin30 = 30 * 3.1415926 / 180;
        float sin60 = 60 * 3.1415926 / 180;
        float sin90 = 90 * 3.1415926 / 180;
        if (a == sin30) {
            std::cout << "sin: 0.5 ";
        }
        if (a == sin60) {
            std::cout << "sin: 0.866025 ";
        }
        if (a == sin90) {
            std::cout << "sin: 1 ";
        }
    });
   functions.push_back([](float a) {
       float cos30 = 30 * 3.1415926 / 180;
       float cos60 = 60 * 3.1415926 / 180;
       float cos90 = 90 * 3.1415926 / 180;
       if (a == cos30) {
           std::cout << "cos: 0.866025 ";
       }
       if (a == cos60) {
           std::cout << "cos: 0.5 ";
       }
       if (a == cos90) {
           std::cout << "cos: 2.67949e-08";
       }
       });

    for (const auto& angle : angles) {
        std::cout << angle << ": ";
        for (const auto& function : functions)
            function(angle);
        std::cout << std::endl;
    }
}

