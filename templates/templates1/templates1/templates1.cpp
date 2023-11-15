#include <vector>
#include <iostream>




template <class T>
T qua(T& a ) {
	return a * a;
}

template<>
std::vector<int> qua(std::vector<int>& v ) {
	for (int i = 0; i < v.size(); ++i) {
		v[i] = qua(v[i]);
	}
	return v;
}

int main()
{   
	int a=2;
	double b = 3.4;
	std::cout << qua(a) <<" " << qua(b)<<" ";
	std::vector<int> v{1, 2, 3};
	qua(v);
	for (auto c : v) {
		std::cout << c<<' ';
	}
}

