
#include <iostream>

void print_and_increase(int start)
{
	std::cout << start << std::endl;
	print_and_increase(start + 1);
}



int main(int argc, char** argv)
{
	print_and_increase(1); return 0;
}


