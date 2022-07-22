#include <iostream>
#include "pair.hpp"
#include <string>
#include "Map.hpp"
#include <map>
#include "BTree.hpp"

int main() {
	ft::pair<int, std::string> f(141, "Hello world");
	ft::pair<int, std::string> t;
	ft::RBtree<int>	m;
	std::cout << m._root.data << std::endl;


	return (0);
}