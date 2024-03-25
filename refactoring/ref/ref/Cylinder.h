#pragma once
#include "shape.h"

class Cylinder : public Shape3D {
public:
	Cylinder(std::pair<int, int> xy, int R, int H);
	int getsqr() const override;
	int getvolume() const override;
private:
	std::pair<int, int> center;
	int R;
	int H;
};
