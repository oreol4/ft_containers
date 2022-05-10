#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>


namespace ft {
	template<typename T>

	class vector {
	private:
		T *arr;
		size_t sz;
		size_t cap;
		// allocator
	public:
		typedef typename size_t size_type;
		typedef typename T value_type;
		vector() {};
		~vector() {};
		vector &operator=(const vector &rhs) {
			this->arr = rhs.arr;
			this->cap = rhs.cap;
			this->sz = rhs.sz;
			return (*this);
		};

	};

}

#endif