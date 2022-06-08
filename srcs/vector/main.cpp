#include <iostream>
//#include <vector>

#include "Vector.hpp"


int main() {

	ft::vector<int> v1;
	for (size_t i = 0; i < 10;i++) {
		v1.push_back(i);
	}
	std::cout << "v1 = " << v1.capacity() << " " << v1.size() << std::endl;
	for (size_t i = 0; i < v1.size(); i++) {
		std::cout << v1[i] << " ";
	}
	std::cout << std::endl;
	v1.pop_back();
	std::cout << "v1 = " << v1.capacity() << " " << v1.size() << std::endl;
	for (size_t i = 0; i < v1.size(); i++) {
		std::cout << v1[i] << " ";
	}
	std::cout << std::endl;

	std::vector<int> v2;
	for (size_t i = 0; i < 10;i++) {
		v2.push_back(i);
	}
	std::cout << "v2 = " << v2.capacity() << " " << v2.size() << std::endl;
	for (size_t i = 0; i < v2.size(); i++) {
		std::cout << v2[i] << " ";
	}
	std::cout << std::endl;
	v2.pop_back();
	std::cout << "v2 = " << v2.capacity() << " " << v2.size() << std::endl;
	for (size_t i = 0; i < v2.size(); i++) {
		std::cout << v2[i] << " ";
	}
}