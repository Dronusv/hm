#pragma once
#include "rhomb.h"

class square :public rhomb {
public:
    square();
    square(int a);
    bool check()override;
};