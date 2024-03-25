#define _USE_MATH_DEFINES
#include "Cylinder.h"
#include<cmath>
Cylinder::Cylinder(std::pair<int, int> xy, int R, int H) {
	center = xy;
	this->R = R;
	this->H = H;
}

int Cylinder::getsqr() const {
	return M_PI * R * R + 2 * R * H;
}

int Cylinder::getvolume() const {
	return M_PI * R * R * H;
}