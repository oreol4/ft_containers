#include <iostream>
#include <vector>
#include "Vector.hpp"
#include "utils.hpp"

int main() {

//	std::cout << "is_integral:" << std::endl;
//	std::cout << "char: " << ft::is_integral<char>::value << std::endl;
//	std::cout << "int: " << ft::is_integral<int>::value << std::endl;
//	std::cout << "float: " << ft::is_integral<float>::value << std::endl;
//
//
//	std::cout << "char: " << ft::is_integral<char>::value << std::endl;


	std::vector<int>	v1;
	std::vector<int>	v2;
	ft::vector<int>		m1;
	ft::vector<int>		m2;
	v1.push_back(1);
	for (size_t i = 1;i < 11; i++) {
		v1.push_back(i*2);
		v2.push_back(i*2);
		m1.push_back(i*2);
		m2.push_back(i*2);
	}
//	std::cout << v1.at(1) << std::endl;
//	std::cout << v1.front() << std::endl;
//	std::cout << v1.back() << std::endl;
//	std::cout << m1.at(1) << std::endl;
//	std::cout << m1.front() << std::endl;
//	std::cout << m1.back() << std::endl;


	bool tmp;
	tmp = v1 < v2;
	std::cout << tmp << std::endl;
//	bool tmp;
//	bool tmp2;
//	m1.push_back(2);
//	m2.push_back(2);
//	tmp = m2 == m1;
//	tmp2 = m2 != m1;
//
//	std::cout << "== " << tmp << std::endl;
//	std::cout << "!= " << tmp2 << std::endl;
//
//	m1.dispVector();
//	m2.dispVector();









//	ft::vector<int> v1;
//
//	std::vector<int> st2;
//	for (int i = 0;i < 20; i++) {
//		st2.push_back(i*2);
//		v1.push_back(i*4);
//	}
//	std::vector<int>::iterator it = st2.begin();
//	std::vector<int>::iterator ite = st2.end() - 1;
////	it += ite;
//	std::cout << *it << std::endl;
//	std::cout << *ite << std::endl;
//	std::cout << *it - *ite << std::endl;
//	ite -= 4;
//	*ite = 22;
//	std::cout << *ite << std::endl;
//	std::cout << "My vector/iterator" << std::endl;
//
//	ft::vector<int>::iterator myit = v1.begin();
//	ft::vector<int>::iterator myite = v1.end();
//	std::cout << *myit << std::endl;
//	std::cout << *myite << std::endl;
//	std::cout << *myit - *myite << std::endl;
//	myite -= 4;
//	*myite = 22;
//	std::cout << *myite << std::endl;

//	ft::vector<int>	newVec(myit, myite);
//	for (;myit < myite; myit++) {
//		std::cout << *myit << std::endl;
//	}
//	newVec.dispVector();
//	std::vector<int>::iterator sit = st2.begin();
//	std::vector<int>::iterator site = st2.end();
//	std::vector<int>	stNew(sit, site);
//	for (size_t i = 0; i < stNew.size(); i++) {
//		std::cout << stNew[i] << " ";
//	}
//	for (size_t i = 0;i < newVec.size(); i++) {
//		std::cout << newVec[i] << std::endl;
//	}

}