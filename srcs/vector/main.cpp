#include <iostream>
#include "Vector.hpp"
#include "utils.hpp"
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include <vector>





int main() {

	ft::vector<int>		v2;
	std::vector<int>	v3;


	for (size_t i = 0;i < 10;i++) {
		v2.push_back(i * 2);
		v3.push_back(i * 2);
	}
//
//	ft::vector<int>::iterator it = v2.begin();
//	v2.erase(it);
//	v2.erase(it + 1);
	std::vector<int>::iterator fit = v3.begin();
	std::vector<int>::iterator fite = v3.end();

	ft::vector<int>::iterator it = v2.begin();
	ft::vector<int>::iterator ite = v2.end();

	v3.erase(fit + 2, fite - 2);
	v2.erase(it + 2, ite - 2);
	v2.dispVector();
	for (size_t i = 0;i < v3.size();i++) {
		std::cout << v3[i] << " ";
	}
//	v2.insert(it, 4444);
//	v2.erase(it, ite);
//	v2.dispVector();
//	int _ratio = 10000;
//	std::vector<int> v;
//	ft::vector<int>	 vector;
//	for (int i = 0; i < 9900 * _ratio; ++i)
//		vector.push_back(i);
//	v.push_back(*(vector.erase(vector.begin() + 8 * _ratio, vector.end() - 1500 * _ratio)));
//	v.push_back(*(vector.begin() + 82 * _ratio));
//	v.push_back(vector.size());
//	v.push_back(vector.capacity());

}