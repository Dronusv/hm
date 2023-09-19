#pragma once
#include "quadrilateral.h"
class parallelogram : public quadrilateral {
public:
    parallelogram();
    parallelogram(int a, int b, int A, int B);
    bool check()override;
};