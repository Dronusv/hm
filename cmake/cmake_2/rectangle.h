#pragma once
#include"parallelogram.h"
class rectangle : public parallelogram {
public:
    rectangle();
    rectangle(int a, int b);
    bool check()override;
};