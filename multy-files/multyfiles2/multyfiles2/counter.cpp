#include"counter.h"

Counter::Counter() {
	c = 1;
}
Counter::Counter(int num) {
	c = num;
}
int Counter::getc() {
	return c;
}
void Counter::minus() {
	c--;
}
void Counter::plus() {
	c++;
}

