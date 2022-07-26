#include <iostream>
//#include "pair.hpp"
#include "Map.hpp"


int main() {
	ft::map<int, int> t;
	t.__root->data = 4;
	std::cout << t.__root->data << std::endl;
	std::cout << t.__root->is_red << std::endl;
	t.__root->insertNode(t, 44);
}
