#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>


namespace ft {
	template< typename T , typename Aloc = std::allocator<T> >

	class vector {
	private:
		T *arr;
		size_t sz;
		size_t cap;
		Aloc myallocator;
	public:

		// MEMBER TYPES
		typedef T value_type;
		typedef Aloc allocator_type;
		typedef typename Aloc::reference reference;
		typedef typename Aloc::const_reference const_refernce;
		typedef typename Aloc::pointer pointer;
		typedef typename Aloc::const_pointer const_pointer;
		// this place for iterators
		typedef size_t size_type;

		vector(const allocator_type& alloc = allocator_type()): arr(0), sz(0), cap(0), myallocator(alloc){};
		vector(size_t n, const value_type& value = value_type(), const Aloc& alloc = Aloc()): sz(n), cap(n), myallocator(alloc){
//			if (n >= cap)
//				reserve(n);
			arr = myallocator.allocate(n);
			for (size_t i = 0; i < n; i++) {
				myallocator.construct(arr + i, value);
			}
		};
		~vector() {
			myallocator.deallocate(arr, cap);
			myallocator.destroy(arr);
		};
		vector &operator=(const vector &rhs) {
			this->arr = rhs.arr;
			this->cap = rhs.cap;
			this->sz = rhs.sz;
			return (*this);
		};
		// ITERATORS




		// MEMBER FUNCTION -> CAPACITY

		void resize(size_t n, value_type val = value_type())
		{
			if (n < sz) {
				for (size_t i = n; i < sz; i++) {
					myallocator.destroy(arr + i);
				}
				sz = n;
			} else {
				if (cap < n) {
					reserve(cap * 2);
					for (size_t i = sz; i < cap; i++) {
						myallocator.construct(arr + i, val);
						++sz;
					}
				}
			}
//			(void)val;
//			T *newarr = myallocator.allocate(n);
//			if (n > cap)
//				reserve(n);
//			try {
//				std::uninitialized_copy(arr, arr+n, newarr);
//			}catch(...) {
//				myallocator.deallocate(newarr, n);
//			}
//			myallocator.deallocate(arr, n);
//			myallocator.destroy(arr);
//			arr = newarr;
//			sz = n;
		};

		void reserve(size_t n) {
			if (n < cap)
				return ;
			T *newarr = myallocator.allocate(n);
			try {
				std::uninitialized_copy(arr, arr+sz, newarr);
			}catch(...)
			{
				myallocator.deallocate(newarr, n);
			}
			myallocator.deallocate(arr, sz);
			myallocator.destroy(arr);
			arr = newarr;
			cap = n;
		}

		size_type size() {
			return (sz);
		}

		size_type capacity() {
			return (cap);
		}
		size_type max_size() {
			return (myallocator.max_size());
		}
		bool empty() {
			return (sz == 0);
		}
		// MODIFIERS
		void push_back(const value_type& value) {
			if (sz == cap) {
				reserve(2 * cap);
			}
			arr[sz] = value;
			++sz;
		}

		reference operator[](size_type n) {
			return (arr[n]);
		}
	};

}

#endif