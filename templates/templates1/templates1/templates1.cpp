#include <vector>
#include <iostream>




template <class T>
T qua(const T& a ) {
	return a * a;
}

template<>
std::vector<int> qua(const std::vector<int>& v ) {
	std::vector<int> res(v.size());
	for (int i = 0; i < res.size(); ++i) {
		res[i] = qua(v[i]);
	}
	return res;
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

