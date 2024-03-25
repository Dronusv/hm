#pragma once
#include "shape.h"

class Line :public Shape1D {
public:
	Line(std::vector<int> x, std::vector<int> y);
	void shift(int m, int n)  override;
	void scaleX(int a) override;
	void scaleY(int d) override;
	void scale(int s) override;
private:
	std::vector<int> x;
	std::vector<int> y;
};
