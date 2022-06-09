#include <iostream>
#include <vector>
#include "Vector.hpp"


int main() {

	ft::vector<int> v1(5);
	ft::RandomAccess_iterator<int> it;
	ft::RandomAccess_iterator<int> b;
	bool t = it == b;
	std::cout << t << std::endl;
}