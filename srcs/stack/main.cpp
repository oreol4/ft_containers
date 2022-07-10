#include <iostream>

#include "Stack.hpp"
#include "../vector/Vector.hpp"
int main()
{
	ft::stack<int> v1, v2;

	v1.push(1);
	v1.push(1);
	v1.push(1);
	v1.push(1);

	v1.dispStack();

	return(0);
}