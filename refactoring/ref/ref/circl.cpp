#define _USE_MATH_DEFINES
#include "Circl.h"
#include<cmath>

Circl::Circl(std::pair<int, int> xy, int R) {
	center = xy;
	this->R = R;
}

int Circl::getsqr() const {
	return M_PI * R * R;
}