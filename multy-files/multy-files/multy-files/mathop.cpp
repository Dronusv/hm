#include "mathop.h"

int addition(int a, int b) {
	return a + b;
}
int subtraction(int a, int b) {
	return a - b;
}
int multiplication(int a, int b) {
	return a * b;
}
int division(int a, int b) {
	return a / b;
}
int degree(int a, int b) {
	if (b == 0) {
		return 1;
	}
	int temp = a;
	for (int i=0; i < b-1; ++i) {
		a = a * temp;
	}
	return a;
}