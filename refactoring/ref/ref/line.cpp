#include "line.h"

Line::Line(std::vector<int> x, std::vector<int> y) {
	this->x = x;
	this->y = y;
}
void Line::shift(int m, int n) {
	for (int i = 0; i < x.size(); ++i) {
		x[i] += m;
	}
	for (int i = 0; i < y.size(); ++i) {
		y[i] += n;
	}
}
void Line::scaleX(int a) {
	for (int i = 0; i < x.size(); ++i) {
		x[i] *= a;
	}
}
void Line::scaleY(int d) {
	for (int i = 0; i < y.size(); ++i) {
		y[i] *= d;
	}
}
void Line::scale(int s) {
	for (int i = 0; i < x.size(); ++i) {
		x[i] /= s;
	}
	for (int i = 0; i < y.size(); ++i) {
		y[i] /= s;
	}
}