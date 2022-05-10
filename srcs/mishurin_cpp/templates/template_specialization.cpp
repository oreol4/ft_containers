#include <iostream>
#include <vector>
// Специализация шаблонов


/*Полная явная специализация шаблонов.
Допустим есть такая версия вектора, которая работает по другому
template < typename T >

class vector {

};

template <>
class vector<bool> {
};*/

// Частичная специализация

/*template < typename T >
struct S {
	void f() {
		std::cout << "1" << std::endl;
	}
};

template <>
struct S<int> {
	void f() {
		std::cout << "2" << std::endl;
	}
};

template <typename T>
struct S<T*> {
	void f() {
		std::cout << "3" << std::endl;
	}
};*/

template <typename T, typename Container = std::vector<T> >
class stack {
private:
	Container c;
public:
};

int main() {

	stack<int> s;
}