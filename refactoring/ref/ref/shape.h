#pragma once
#include <string>
#include <vector>

class Shape1D {
public:
	virtual void shift(int m, int n) =0;
	virtual void scaleX(int a)=0;
	virtual void scaleY(int d) =0;
	virtual void scale(int s) =0 ;
};

class Shape2D : public Shape1D
{
public:
	Shape2D() = default;
	virtual int getsqr() const = 0;
	
};

class Shape3D: public Shape2D
{
public:
	Shape3D() = default;
	virtual int getvolume() const = 0;
	virtual void shift(int m, int n, int k) =0;
	virtual void scaleZ(int e)=0;
};

