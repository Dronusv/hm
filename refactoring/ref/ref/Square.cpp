#include "Square.h"

Square::Square(std::vector<int> x, std::vector<int> y) {
	this->x = x;
	this->y = y;
}
void Square::shift(int m, int n) {
	for (int i = 0; i < x.size(); ++i) {
		x[i] += m;
	}
	for (int i = 0; i < y.size(); ++i) {
		y[i] += n;
	}
}
void Square::scaleX(int a) {
	for (int i = 0; i < x.size(); ++i) {
		x[i] *= a;
	}
}
void Square::scaleY(int d) {
	for (int i = 0; i < y.size(); ++i) {
		y[i] *= d;
	}
}
void Square::scale(int s) {
	for (int i = 0; i < x.size(); ++i) {
		x[i] /= s;
	}
	for (int i = 0; i < y.size(); ++i) {
		y[i] /= s;
	}
}

int Square::getsqr() const {
	int a = std::abs(x[0] - x[1]);
	int b = std::abs(y[0] - y[1]);
	return a * b;
}