#pragma once
#include "shape.h"
class Circl :public Shape2D {
public:
	Circl(std::pair<int, int> xy, int R);
	int getsqr() const override;
private:
	std::pair<int, int> center;
	int R;
};