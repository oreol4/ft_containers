#include <iostream>
#include <vector>
#include <cstdlib>
// New/delete overloading, allocators
// 9.1 Standard new-delete overloading.




//void* operator new(size_t n) {
//	std::cout << "Allocated " << n << " bytes" << std::endl;
//	return (malloc(n));
//}
//
//void operator delete(void* ptr) {
////	(void)h;
//	std::cout << "Deallocated bytes" << std::endl;
//	free (ptr);
//}
//
//void* operator new[](size_t n) {
//	std::cout << "Allocated array" << std::endl;
//	return (malloc(n));
//}
//
//void operator delete[](void *ptr) {
//	std::cout << "Deallocated array" << std::endl;
//	free (ptr);
//}

// Перегрузка оператора new для своего типа(не глобальная перегрузка, как написано выше)


struct S {
	int x = 0;
	double d = 0.0;
	static void* operator new (size_t n) {
		std::cout << "Allocated for S struct " << n << " bytes" << std::endl;
		return (malloc(n));
	}
	void operator delete (void *ptr, size_t n) {
		std::cout << "Deallocated S struct " << n << " bytes" << std::endl;
		free (ptr);
	}
};

// playcement new
void* operator new (size_t /*n*/, void *ptr) { // call constructor
	return ptr;
}

void* operator new(size_t n, std::nothrow_t) { // return nullptr if didnt work out allocate memmory
	return (malloc(n));
}

struct mynew_t {};
mynew_t my_tag;

void* operator new (size_t n, mynew_t) {
	std::cout << "Allocate mymew_t" << std::endl;
	return (malloc(n));
}

void operator delete (void *ptr, mynew_t) {
	std::cout << "Deallocate mymew_t" << std::endl;
	free (ptr);
}

int main() {

	int *ptr = new (my_tag) int(4);

//	operator delete(ptr, mynew_t);
	//int *ptr = new(std::nothrow) int(5);


	/*std::vector<int> v1;
	for (int i = 0; i < 10; ++i) {
		v1.push_back(i);
		std::cout << "value = " << v1[i] << " size = " << v1.size() << " cap = " << v1.capacity() << std::endl;
	}

	S *p = new S();
	delete p;*/
}
