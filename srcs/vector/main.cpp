#include <iostream>
#include <vector>
#include "Vector.hpp"


int main() {


//	ft::RAIterator<random_access_iterator_tag, int>	t;
//	std::vector<int>::iterator k;
//	std::cout << *k << std::endl;



//	ft::vector<int> v1;
//	for (int i = 0;i < 10; i++) {
//		v1.push_back(i * 2);
//	}
//	ft::vector<int>::iterator iter;
//	ft::vector<int>::iterator itend = v1.begin();
//
//	for (iter = v1.end();iter > itend; --iter) {
//		std::cout << *iter << std::endl;
//	}
//	iter = v1.begin();
//	std::cout << *iter-4 << std::endl;
	ft::vector<int> v1;

	std::vector<int> v2;
	for (int i = 0;i < 10; i++) {
		v2.push_back(i);
		v1.push_back(i);
	}
	std::vector<int>::iterator it = v2.end();
	ft::vector<int>::iterator ite = v1.end();
	std::cout << it[-4] << std::endl;
	std::cout << ite[-4] << std::endl;
//	it = v2.begin()-1;
//	ite = v1.begin()-1;
//	std::cout << "my " << *ite << std::endl;
//	std::cout << "std" << *it << std::endl;

}