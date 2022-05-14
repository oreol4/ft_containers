#include <iostream>
#include <vector>

#include "Vector.hpp"



int main() {

	ft::vector<int> v1(5);
	std::vector<int> r1(5);
//	std::cout << "size = " << v1.size() << " cap = " << v1.capacity() << std::endl;
//	std::cout << "size = " << r1.size() << " cap = " << r1.capacity() << std::endl;

//	v1.push_back(22);
	for (size_t i = 0;i < 10; ++i) {
		v1.push_back(22);
		r1.push_back(22);
//		std::cout << "(V1) size = " << v1.size() << " cap = " << v1.capacity() << std::endl;
//		std::cout << "(R1) size = " << r1.size() << " cap = " << r1.capacity() << std::endl;
	}
	v1.push_back(3424);
	v1.pop_back();
//	std::cout << "size = " << r1.size() << " cap = " << r1.capacity() << std::endl;
//	r1.pop_back();
//	std::cout << r1[r1.size()] << std::endl;
//	std::cout << "size = " << r1.size() << " cap = " << r1.capacity() << std::endl;
//	std::cout << r1[r1.size()] << std::endl;
	for (size_t i = 0; i < v1.size(); i++) {
		std::cout << v1[i] << std::endl;
	}
//	std::cout << "size = " << v1.size() << " cap = " << v1.capacity() << std::endl;
//	for (size_t i = 0; i < r1.size(); i++) {
//		std::cout << r1[i] << std::endl;
//	}
//	v1.resize(4);
//	r1.resize(4);
//	std::cout << "size = " << v1.size() << " cap = " << v1.capacity() << std::endl;
//	std::cout << "size = " << r1.size() << " cap = " << r1.capacity() << std::endl;

//	r1.clear();
//	std::cout << "size = " << r1.size() << " cap = " << r1.capacity() << std::endl;
//	v1.clear();
//	std::cout << "|(V1) size = " << v1.size() << " cap = " << v1.capacity() << std::endl;
//	v1.push_back(3424);
//	int k = v1.size();
//	std::cout << "|(V1) size = " << v1[k] << " " << v1.size() << " cap = " << v1.capacity() << std::endl;
//	v1.clear();
//	std::cout << "(V1) size = " << v1.size() << " cap = " << v1.capacity() << std::endl;
//	std::cout << r1[r1.size() + 1];
//	try {
//		std::cout << v1.at(10) << std::endl;
//	}catch(std::exception &e) {
//		std::cerr << e.what() << std::endl;
//	}
//	std::cout << r1.back() << std::endl;


//	v1.front() -= 100;
//	std::cout << v1.front() << std::endl;
//	std::cout << "size = " << v1.size() << " cap = " << v1.capacity() << std::endl;
//	std::cout << "size = " << r1.size() << " cap = " << r1.capacity() << std::endl;
//	for (size_t i = 0; i < v1.size(); i++) {
//		std::cout << v1[i] << std::endl;
//	}
//	std::cout << "size = " << v1.size() << " cap = " << v1.capacity() << std::endl;
//	v1.push_back(1);
//	v1.push_back(1);
//	v1.push_back(1);
//	v1.push_back(1);
//	v1.push_back(1);
//	std::cout << v1.size() << std::endl;
//	std::vector<int> v2;

//	for (int i = 0;i < 5; i++ ) {
//		v1.push_back(1);
//		std::cout << "A" << std::endl;
//	}
//	v1.push_back(1);
//	std::cout << v1.empty() << std::endl;
//	std::cout << v2.max_size() << std::endl;
//	std::cout << v1.max_size() << std::endl;
//	std::cout << "size = " << v2.size() << " cap = " << v2.capacity() << std::endl;
//	v2.reserve(22);
//	std::cout << "size = " << v2.size() << " cap = " << v2.capacity() << std::endl;
//	v2.res
//	v2.reserve(10);
//	std::cout << v2.size() << std::endl;
//	std::cout << v2.capacity() << std::endl;
//	std::cout << v.size() << std::endl;
//	v.reserve(10);
//	std::cout << v.capacity() << std::endl;
//	for (int i = 0;i < 5; ++i) {
//		v2.push_back(i);
//	}
//	std::cout << "size = " << v2.size() << " cap = " << v2.capacity() << std::endl;
//	v2.resize(1);
//	std::cout << "size = " << v2.size() << " cap = " << v2.capacity() << std::endl;
//	for (size_t i = 0;i < v2.capacity(); i++) {
//		std::cout << v2[i] << std::endl;
//	}
//	for (size_t i = 0;i < v2.capacity(); i++) {
//		std::cout << v2[i] << std::endl;
//	}
//	std::cout << "resize" << std::endl;
//	v2.resize(21);
//	for (size_t i = 0;i < v2.capacity(); i++) {
//		std::cout << v2[i] << std::endl;
//	}
//	std::cout << "size = " << v2.size() << " cap = " << v2.capacity() << std::endl;
}