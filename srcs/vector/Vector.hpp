#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>
#include <exception>

namespace ft {
	template< typename T , typename Aloc = std::allocator<T> >

	class vector {
	private:
		T *arr;
		size_t sz;
		size_t cap;
		Aloc myallocator;
	public:
		// EXCEPTION
		class LargeTooHighIndex:public std::exception {
		public:
			virtual const char * what() const throw() {
				return ("error: large index.");
			};
		};
		// MEMBER TYPES
		typedef T value_type;
		typedef Aloc allocator_type;
		typedef typename Aloc::reference reference;
		typedef typename Aloc::const_reference const_reference;
		typedef typename Aloc::pointer pointer;
		typedef typename Aloc::const_pointer const_pointer;
		// this place for iterators
		typedef size_t size_type;

		vector(const allocator_type& alloc = allocator_type()): arr(0), sz(0), cap(0), myallocator(alloc){};
		vector(size_t n, const value_type& value = value_type(), const Aloc& alloc = Aloc()):
		sz(n), cap(n), myallocator(alloc){
			arr = myallocator.allocate(n);
			for (size_t i = 0; i < n; i++) {
				myallocator.construct(arr + i, value);
			}
		};

		~vector() {
			for (size_t i = 0; i < cap; i++) {
				myallocator.destroy(arr + i);
			}
			if (cap)
				myallocator.deallocate(arr, cap);
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
			for (size_t i = 0; i < cap; i++) {
				myallocator.destroy(arr);
			}
			arr = newarr;
			cap = n;
		};

		size_type size() const {
			return (sz);
		};

		size_type capacity() const {
			return (cap);
		};

		size_type max_size() const {
			return (myallocator.max_size());
		};

		bool empty() const {
			return (sz == 0);
		};

		// MODIFIERS
		void push_back(const value_type& value) {
			if (sz == cap) {
				reserve(2 * cap);
			}
			myallocator.construct(arr + sz, value);
			sz++;
		};

		void pop_back() {
			if (sz == 0) return ;
			myallocator.destroy(arr + sz - 1);
			sz--;
		};

		// ELEMENT ACCESS
		reference operator[](size_type n) {
			return (arr[n]);
		};

		const_reference operator[] (size_type n) const {
			return (arr[n]);
		};

		reference at(size_type n) {
			if (n > cap)
				throw LargeTooHighIndex();
			return (arr[n]);
		};

		const_reference at (size_type n) const {
			if (n > cap)
				throw LargeTooHighIndex();
			return (arr[n]);
		};

		reference front() {
			return (arr[0]);
		};

		const_reference front() const {
			return (arr[0]);
		};

		reference back() {
			return (arr[sz]);
		};

		const_reference back() const {
			return (arr[sz]);
		};

		void clear() {
			for (size_t i = 0; i < cap; i++) {
				myallocator.destroy(arr);
			}
			sz = 0;
		};
		template <class A, class Alloc>
			friend bool operator== (const ft::vector<A,Alloc>& lhs, const ft::vector<A,Alloc>& rhs);

		template <class A, class Alloc>
			friend bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

		template <class A, class Alloc>
			friend bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

		template <class A, class Alloc>
			friend bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

		template <class A, class Alloc>
			friend bool operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

		template <class A, class Alloc>
			friend bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);
	};
}
template <class A, class Alloc>
bool operator== (const ft::vector<A,Alloc>& lhs, const ft::vector<A,Alloc>& rhs) {
	return (lhs == rhs);
};

template <class A, class Alloc>
bool operator!= (const ft::vector<A,Alloc>& lhs, const ft::vector<A,Alloc>& rhs) {
	return (lhs != rhs);
};

template <class A, class Alloc>
bool operator<  (const ft::vector<A,Alloc>& lhs, const ft::vector<A,Alloc>& rhs) {
	return (lhs < rhs);
};

template <class A, class Alloc>
bool operator<= (const ft::vector<A,Alloc>& lhs, const ft::vector<A,Alloc>& rhs) {
	return (lhs <= rhs);
};

template <class A, class Alloc>
bool operator>  (const ft::vector<A,Alloc>& lhs, const ft::vector<A,Alloc>& rhs) {
	return (lhs > rhs);
};

template <class A, class Alloc>
bool operator>= (const ft::vector<A,Alloc>& lhs, const ft::vector<A,Alloc>& rhs) {
	return (lhs >= rhs);
};

#endif