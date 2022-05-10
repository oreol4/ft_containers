#include <iostream>

// Класс который умеет делать аллокейт и деаллокейт.
// Аллокейт

template < typename T >

class allocator {
public:
	T *allocator(size_t count) const {
		return ::operator_new(count * sizeof(T));
	}

	void deallocate(T *ptr, size_t /*count*/) {
		::operator delete(reinterpret_cast<void*>(ptr));
	}

	template < typename... Args >
	void construct(T* ptr, const Args&... args) {
		new (ptr) T(args...);
	}

	void destroy(T* ptr) {
		ptr->~T();
	}
};



int main() {

}