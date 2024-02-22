
#include <vector>
#include <iostream>
#include <thread>
#include <future>

void sort(std::vector<int>::iterator& begin, std::vector<int>::iterator& end) {
	

}

std::vector<int>::iterator mini(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end) {
	std::vector<int>::iterator min = begin;
	std::vector<int>::iterator ptr;
	for (ptr = begin; ptr < end; ptr++) {
		if (*ptr < *min) {
			min = ptr;
		}
	}
	return min;
}

int main()
{
	std::vector<int> v{ 5,3,1,2,4 };
	std::promise<std::vector<int>::iterator> prom;
	std::future<std::vector<int>::iterator> res = prom.get_future();
	for (std::vector<int>::iterator ptr = v.begin(); ptr < v.end(); ptr++) {
		auto f = std::async(mini,std::ref(ptr),v.end());
		std::vector<int>::iterator m = f.get();
		int temp = 0;
		temp = *ptr;
		*ptr = *m;
		*m = temp;
		
	}


	for (auto c : v) {
		std::cout << c<<" ";
	}
}

