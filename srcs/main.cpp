#include <iostream>
#include <memory>
#include "Vector.hpp"
#include <vector>
#include <stack>
#include "Stack.hpp"

int main()
{
	Stack<int> v1;
	v1.push(2);
	v1.push(2);
	v1.push(2);
	v1.push(2);
//	v1.push(2);
//	v1.push(2);
//	v1.push(444);
//	v1.push(-222);
	std::cout << v1.size() << std::endl;
//	std::cout << v1.top() << std::endl;
	v1.pop();
	std::cout << v1.size() << std::endl;
	Stack<int> V(v1);
//	std::stack<int> v2;
//	v2.push(1);
//	v2.push(1);
//	v2.push(1);
//	v2.push(1);
//	v2.push(1);
//	v2.push(1);
//	v2.push(4);
//	v2.push(1);
//	std::cout << v2.size() << std::endl;
	return(0);
}