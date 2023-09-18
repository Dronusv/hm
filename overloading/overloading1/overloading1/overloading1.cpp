#include <iostream>


int gcd(int a, int b) {
	if (a < b) {
		std::swap(a, b);
	}

	while (b) {
		a %= b;
		std::swap(a, b);
	}

	return a;
}

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	
	bool operator ==(Fraction rhs) {
		tr(rhs);
		if (numerator_ == rhs.numerator_) {
			red();
			rhs.red();
			return true;
		}
		red();
		rhs.red();
		return false;
	}
	bool operator !=(Fraction rhs) {
		tr(rhs);
		if (numerator_ != rhs.numerator_) {
			red();
			rhs.red();
			return true;
		}
		red();
		rhs.red();
		return false;
	}
	bool operator <(Fraction rhs) {
		tr(rhs);
		if (numerator_ < rhs.numerator_) {
			red();
			rhs.red();
			return true;
		}
		red();
		rhs.red();
		return false;
	}
	bool operator >(Fraction rhs) {
		tr(rhs);
		if (numerator_ > rhs.numerator_) {
			red();
			rhs.red();
			return true;
		}
		red();
		rhs.red();
		return false;
	}
	bool operator <=(Fraction rhs) {
		tr(rhs);
		if (numerator_ <= rhs.numerator_) {
			red();
			rhs.red();
			return true;
		}
		red();
		rhs.red();
		return false;
	}
	bool operator >=(Fraction rhs) {
		tr(rhs);
		if (numerator_ >= rhs.numerator_) {
			red();
			rhs.red();
			return true;
		}
		red();
		rhs.red();
		return false;
	}

	void tr(Fraction& rhs) {
		int tempden = denominator_;
		numerator_ = numerator_ * rhs.denominator_;
		denominator_ = denominator_ * rhs.denominator_;
		rhs.numerator_ = rhs.numerator_ * tempden;
		rhs.denominator_ = rhs.denominator_ * tempden;

	}
	void red() {
		int res = gcd(numerator_, denominator_);
		numerator_ = numerator_ / res;
		denominator_ = denominator_ / res;
	}
};


int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}