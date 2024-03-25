#pragma once
#include "shape.h"

class Cube : public Shape3D {
public:
	Cube(std::vector<int> x, std::vector<int> y, std::vector<int> z);
	int getsqr() const override;
	int getvolume() const override;
	void shift(int m, int n, int k) override;
	void scaleX(int a) override;
	void scaleY(int d) override;
	void scaleZ(int e) override;
	void scale(int s) override;

private:
	std::vector<int> x;
	std::vector<int> y;
	std::vector<int> z;

};