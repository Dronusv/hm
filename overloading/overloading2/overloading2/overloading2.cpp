#include <iostream>
#include <fstream>
#include <windows.h>

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
	int getnum() {
		return numerator_;
	}
	int getden() {
		return denominator_;
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
	Fraction operator +(Fraction rhs) {
		Fraction res(0, 0);
		tr(rhs);
		res.numerator_ = rhs.numerator_ + numerator_;
		res.denominator_ = denominator_;
		res.red();
		red();
		rhs.red();
		return res;
	}
	Fraction operator -(Fraction rhs) {
		Fraction res(0, 0);
		tr(rhs);
		res.numerator_ =numerator_ - rhs.numerator_;
		res.denominator_ = denominator_;
		res.red();
		red();
		rhs.red();
		return res;
	}
	Fraction operator *(Fraction rhs) {
		Fraction res(0, 0);
		res.numerator_ = numerator_ * rhs.numerator_;
		res.denominator_ = denominator_*rhs.denominator_;
		res.red();
		return res;
	}
	Fraction operator /(Fraction rhs) {
		Fraction res(0, 0);
		res.numerator_ = numerator_ * rhs.denominator_;
		res.denominator_ = denominator_ * rhs.numerator_;
		res.red();
		return res;
	}
	Fraction& operator ++() {
		numerator_ = denominator_ + numerator_;
		return *this;
	}
	Fraction operator ++(int) {
		Fraction res = *this;
		++(*this);
		return res;
	}
	Fraction& operator --() {
		numerator_ = numerator_-denominator_;
		return *this;
	}
	Fraction operator --(int) {
		Fraction res=*this;
		--(*this);
		return res;
	}

	friend std::ostream& operator <<(std::ostream& os, const Fraction& fr);

	void tr(Fraction& rhs) {
		int tempden = denominator_;
		numerator_ = numerator_ * rhs.denominator_;
		denominator_ = denominator_ * rhs.denominator_;
		rhs.numerator_ = rhs.numerator_ * tempden;
		rhs.denominator_ = rhs.denominator_ * tempden;

	}
	void red() {
		int res= gcd(numerator_, denominator_);
		numerator_ = numerator_ / res;
		denominator_ = denominator_/res;
	}
};	


std::ostream& operator <<(std::ostream& os, const Fraction& fr) {
	os << fr.numerator_ << "/" << fr.denominator_;
	return os;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int n1, n2, d1, d2;
	std::cout << "Введите чеслитель дроби 1: ";
	std::cin >> n1;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> d1;
	std::cout << "Введите чеслитель дроби 2: ";
	std::cin >> n2;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> d2;
	Fraction fr1(n1, d1);
	Fraction fr2(n2, d2);
	Fraction res(0, 0);
	res = fr1 + fr2;
	std::cout << fr1.getnum() << "/" << fr1.getden() << " + " << fr2.getnum() << "/" << fr2.getden() << " = " << res << "\n";
	res = fr1 - fr2;
	std::cout << fr1.getnum() << "/" << fr1.getden() << " - " << fr2.getnum() << "/" << fr2.getden() << " = " << res << "\n";
	res = fr1 * fr2;
	std::cout << fr1.getnum() << "/" << fr1.getden() << " * " << fr2.getnum() << "/" << fr2.getden() << " = " << res << "\n";
	res = fr1 / fr2;
	std::cout << fr1.getnum() << "/" << fr1.getden() << " / " << fr2.getnum() << "/" << fr2.getden() << " = " << res << "\n";
	std::cout << "++" << fr1.getnum() << "/" << fr1.getden() << " * " << n2 << "/" << d2 << " = ";
	res = ++fr1 * fr2;
	std::cout << res << "\n";
	std::cout << "Значение дроби 1 =" << fr1.getnum() << "/" << fr1.getden() << "\n";
	std::cout << fr1.getnum() << "/" << fr1.getden() << "--" << " * " << n2 << "/" << d2 << " = ";
	res = fr1-- * fr2;
	std::cout << res << "\n";
	std::cout << "Значение дроби 1 =" << fr1.getnum() << "/" << fr1.getden() << "\n";
}
