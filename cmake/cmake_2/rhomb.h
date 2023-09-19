#pragma once
#include "parallelogram.h"
class rhomb : public parallelogram {
public:
    rhomb();
    rhomb(int a, int A, int B);
    bool check()override;
};