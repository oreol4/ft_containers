#include <iostream>
#include <vector>
#include "Vector.hpp"


int main() {

	ft::vector<int> v1;

	std::vector<int> st2;
	for (int i = 0;i < 10; i++) {
		st2.push_back(i);
		v1.push_back(i);
	}
	std::vector<int>::iterator it = st2.begin();
	std::vector<int>::iterator ite = st2.end() - 1;
//	it += ite;
	std::cout << *it << std::endl;
	std::cout << *ite << std::endl;
	std::cout << *it - *ite << std::endl;
	ite -= 4;
	*ite = 22;
	std::cout << *ite << std::endl;
	std::cout << "My vector/iterator" << std::endl;

	ft::vector<int>::iterator myit = v1.begin();
	ft::vector<int>::iterator myite = v1.end()-1;
	std::cout << *myit << std::endl;
	std::cout << *myite << std::endl;
	std::cout << *myit - *myite << std::endl;
	myite -= 4;
	*myite = 22;
	std::cout << *myite << std::endl;

	ft::vector<int>	newVec(myit, myite);
	for (size_t i = 0;i < newVec.size(); i++) {
		std::cout << newVec[i] << std::endl;
	}
}