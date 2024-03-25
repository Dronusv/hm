#pragma once
#include "shape.h"

class Square : public Shape2D {
public:
	Square(std::vector<int> x, std::vector<int> y);
	int getsqr() const override;
	void shift(int m, int n) override;
	void scaleX(int a) override;
	void scaleY(int d) override;
	void scale(int s) override;
private:
	std::vector<int> x;
	std::vector<int> y;

};