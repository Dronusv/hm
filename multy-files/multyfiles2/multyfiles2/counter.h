#pragma once
class Counter {
private:
	int c;
public:
	Counter();
	Counter(int num);
	void plus();
	void minus();
	int getc();
};