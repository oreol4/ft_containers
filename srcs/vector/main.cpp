#include <iostream>
#include "Vector.hpp"
#include "utils.hpp"
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include <vector>





int main() {

	ft::vector<int>		v2;
	ft::vector<int>		v5;


	std::vector<int>	v3;
	std::vector<int>	v4;

	for (size_t i = 0;i < 10;i++) {
		v2.push_back(i * 2);
//		v5.push_back(i * 2);
		v4.push_back(i * 2);
		v3.push_back(i * 2);
	}
	v5.push_back(1);
//	std::cout
	std::cout << v2.size() << " " << v2.capacity() << std::endl;
	std::cout << v5.size() << " " << v5.capacity() << std::endl;
	v4.swap(v3);
	v5.swap(v2);
	v5.dispVector();
	v2.dispVector();
//	for (size_t i = 0;i < v3.size();i++) {
//		std::cout << v3[i] << " ";
//	}
//	std::cout << v3.size() << " " << v3.capacity() << std::endl;
//	std::cout << v4.size() << " " << v4.capacity() << std::endl;
//	ft::vector<int>::iterator it = v2.begin() + 4;
//	ft::vector<int>::iterator ite = v2.end() - 5;
//	std::vector<int>::iterator si = v3.begin() + 4;
//	std::vector<int>::iterator sie = v3.end() - 5;
//
//	v5.assign(it, ite);
//	v5.dispVector();
//	v4.assign(si, sie);
//	for (size_t i = 0;i < v4.size();i++){
//		std::cout << v4[i] << " ";
//	}
//
//	std::cout << std::endl;
//
//	std::cout << "STD = " << v4.size() << std::endl;
//	std::cout << "MY  = " << v5.size() << std::endl;
}