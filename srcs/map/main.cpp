#include <iostream>
#include "pair.hpp"
#include <string>



int main() {
	ft::pair<int, std::string> f(141, "Hello world");
	ft::pair<int, std::string> t;

	t = ft::make_pair(10, "afd");
	std::cout << t.first_args << " " << t.second_args << std::endl;
	std::cout << f.first_args << " " << f.second_args << std::endl;
	return (0);
}