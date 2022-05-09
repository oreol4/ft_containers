#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include "Stack.hpp"

int main()
{
	ft::stack<int> v1, v2;
	bool t;

	v1.push(1);
	v1.push(1);
	v1.push(1);
	v1.push(1);

	v2.push(1);
	v2.push(1);
	v2.push(1);
	v2.push(1);

	t = v1 == v2;
	std::cout << "operator == " << t << std::endl;
	t = v1 < v2;
	std::cout << "operator < " << t << std::endl;
	t = v1 > v2;
	std::cout << "operator > " << t << std::endl;
	t = v1 >= v2;
	std::cout << "operator >= " << t << std::endl;
	t = v1 <= v2;
	std::cout << "operator <= " << t << std::endl;
	t = v1 != v2;
	std::cout << "operator != " << t << std::endl;
	std::cout << v1.empty() << std::endl;
	return(0);
}