#include <iostream>
#include "Vector.hpp"
#include "utils.hpp"
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include <vector>





int main() {
	std::vector<int>	v1;
	ft::vector<int>		f1;
	for (int i = 0;i < 6; i++) {
		f1.push_back(2);
		v1.push_back(2);
	}
//	std::cout << f1.size() << std::endl;
//	std::cout << v1.size() << std::endl;
	ft::vector<int>::iterator it = f1.end();
//	std::vector<int>::iterator vit = v1.begin();
//	vit = v1.insert(vit, 444);
//	std::cout << *vit << std::endl;
//	for (size_t i = 0;i < v1.size(); i++) {
//		std::cout << v1[i] << " ";
//	}
//	std::cout << std::endl;
	f1.insert(it,4, 444);
//	std::cout << *it << std::endl;
//	it = f1.end();
//	f1.insert(it, 444);
	f1.dispVector();
//	it = f1.end();
//	f1.insert(it, 444);
//	f1.dispVector();
//	it = v1.begin();
//	v1.insert(it, 444);
//	it = v1.begin();
//	v1.insert(it, 444);
//	v1.insert(it, 444);
//	std::cout << v1.size() << " " << v1.capacity() << std::endl;
//	f1.insert(it, 444);
//	ft::vector<int>		f4;
//	ft::vector<int>::iterator it = f1.begin();
//	ft::vector<int>::iterator ite = f1.end();
//	f4.assign(it, ite);
//	f4.dispVector();
//	v1.resize(2000);
//	f1.resize(2000);
//	std::cout << v1.size() << " " << v1.capacity() << std::endl;
//
//	std::cout << f1.size() << " " << f1.capacity() << std::endl;
//
//	v1.resize(2);
//	f1.resize(2);
//	std::cout << v1.size() << " " << v1.capacity() << std::endl;
//
//	std::cout << f1.size() << " " << f1.capacity() << std::endl;
//	v1.resize(200);
//	f1.resize(200);
//	std::cout << v1.size() << " " << v1.capacity() << std::endl;
//
//	std::cout << f1.size() << " " << f1.capacity() << std::endl;
}