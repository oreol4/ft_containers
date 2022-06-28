#include <iostream>
#include "Vector.hpp"
#include "utils.hpp"
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include <vector>





int main() {

	ft::vector<int>		v2;



	for (size_t i = 0;i < 10;i++) {
		v2.push_back(i * 2);
	}
	ft::vector<int>::iterator it = v2.begin() + 2;
	v2.insert(it, 4444);
	for (size_t i = 0;i < v2.size();i++) {
		std::cout << v2[i] << " ";
	}























//	ft::vector<int>		v4;
//	std::vector<int>::iterator ft;
//	std::vector<int>::iterator fte;
	//ft::vector<int>::iterator it;
	//ft::vector<int>::iterator ite;
//	std::vector<int>::iterator f;
//	std::vector<int> myvector;
////	ft::vector<int>::iterator ite;
//	for (int i = 0;i < 5;i++) {
//		v2.push_back(i  *2);
//		myvector.push_back(i * 2);
////		v1.push_back(i  * 2);
//	}
//	it = v2.begin();
//	ite = v2.end();
////	f = myvector.end() - 1;
//	v2.erase(it);
////	myvector.erase(f);
//	for (size_t i = 0;i < v2.size(); i++) {
//		std::cout << v2[i] << " ";
//	}
//	std::vector<int> myvector;
//	for (int i=1; i<=10; i++) myvector.push_back(i);
//
//	// erase the 6th element
//	myvector.erase (myvector.begin()+5);
//
//	// erase the first 3 elements:
//	std::vector<int>::iterator res;
//	res = myvector.erase (myvector.begin(),myvector.begin()+3);
//	std::cout << *res << std::endl;


//	it = v2.begin();
//	ite = v2.end();
//	ft = v1.begin();
//	fte = v1.end();
////	v4.assign(it, ite);
////	v3.assign(ft, fte);
////	for (size_t i = 0;i < v2.size(); i++) {
////		std::cout << v4[i] << " ";
////	}
//	std::cout << std::endl;
////	for (size_t i = 0;i < v3.size(); i++) {
////		std::cout << v3[i] << " ";
////	}
//	v2.swap(v4);
//		for (size_t i = 0;i < v3.size(); i++) {
//		std::cout << v4[i] << " ";
//	}
//	std::cout << std::endl;
//	std::cout << v4.size() << " " << v4.capacity() << std::endl;
//	std::cout << v3.size() << " " << v3.capacity() << std::endl;
}