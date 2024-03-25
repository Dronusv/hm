#include "cube.h"

Cube::Cube(std::vector<int> x, std::vector<int> y, std::vector<int> z) {
	this->x = x;
	this->y = y;
	this->z = z;
}
void Cube::shift(int m, int n,int k) {
	for (int i = 0; i < x.size(); ++i) {
		x[i] += m;
	}
	for (int i = 0; i < y.size(); ++i) {
		y[i] += n;
	}
	for (int i = 0; i < z.size(); ++i) {
		z[i] += k;
	}
}
void Cube::scaleX(int a) {
	for (int i = 0; i < x.size(); ++i) {
		x[i] *= a;
	}
}
void Cube::scaleY(int d) {
	for (int i = 0; i < y.size(); ++i) {
		y[i] *= d;
	}
}
void Cube::scaleZ(int e) {
	for (int i = 0; i < y.size(); ++i) {
		z[i] *= e;
	}
}
void Cube::scale(int s) {
	for (int i = 0; i < x.size(); ++i) {
		x[i] /= s;
	}
	for (int i = 0; i < y.size(); ++i) {
		y[i] /= s;
	}
	for (int i = 0; i < y.size(); ++i) {
		z[i] /= s;
	}
}
int Cube::getsqr() const {
	int a = std::abs(x[0] - x[1]);
	int b = std::abs(y[0] - y[1]);
	int c = std::abs(z[0] - z[1]);
	return 2 * a * b + 2 * a * c + 2 * b * c;
}

int Cube::getvolume() const {
	int a = std::abs(x[0] - x[1]);
	int b = std::abs(y[0] - y[1]);
	int c = std::abs(z[0] - z[1]);
	return a * b * c;
}