#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>
#include <exception>
#include <vector>
#include "iterator.hpp"
#include <memory>
namespace ft {

	template<typename T, typename Allocator = std::allocator <T> >

	class vector {
	private:
		T *_arr;
		size_t sz;
		size_t cap;
		Allocator allocator;
	public:
		//						MEMBER TYPES
		typedef T 												value_type;
		typedef Allocator 										allocator_type;
		typedef typename allocator_type::reference 				reference;
		typedef typename allocator_type::const_reference 		const_reference;
		typedef typename allocator_type::pointer 				pointer;
		typedef typename allocator_type::const_pointer 			const_pointer;
		// iterators member types
		typedef typename allocator_type::size_type 				size_type;
		typedef typename allocator_type::difference_type 		difference_type;
		// iterators member types


		vector(const allocator_type& alloc = allocator_type()):_arr(0), sz(0), cap(0),
			allocator(alloc){}

		vector(size_type n, const value_type& val = value_type(),
			   const allocator_type& alloc = allocator_type()): sz(n), cap(n),
			   allocator(alloc){
			_arr = allocator.allocate(n);
			for (size_t i = 0; i < n; i++) {
				allocator.construct(_arr + i, val);
			}
		}
		~vector(){
			for (size_t i = 0; i < cap; i++) {
				allocator.destroy(_arr + i);
			}
			allocator.deallocate(_arr, cap);
		}

		vector(const vector<T> &rhs)
		{
			this->_arr = rhs._arr;
			this->allocator = rhs.allocator;
			this->cap = rhs.cap;
			this->sz = rhs.sz;
		}

		void reserve(size_type n) {
			if (n < cap) return;
			T *newPtr;
			newPtr = allocator.allocate(n);
			try {
				std::uninitialized_copy(_arr, _arr + sz, newPtr);
			} catch(...) {
				allocator.deallocate(newPtr, n);
			}
			allocator.deallocate(_arr, sz);
			for (size_t i = 0;i < sz; i++) {
				allocator.destroy(_arr + i);
			}
			_arr = newPtr;
			cap = n;
		}

		void resize (size_type n, value_type val = value_type()) {
			if (n < sz) {
				for (size_t i = n; i < sz;i++) {
					allocator.destroy(_arr + i);
				}
				sz = n;
			} else if (n > sz) {
				if (n > cap)
					reserve(n);
				for (size_t i = sz; i < n; i++) {
					allocator.construct(_arr + i, val);
					++sz;
				}
			}
		}

		void push_back (const value_type& val) {
			if (sz == cap) {
				if (sz == 0)
					reserve(1);
				else
					reserve(cap * 2);
			}
			allocator.construct(_arr + sz, val);
			sz++;
		}

		void pop_back() {
			if (sz == 0) return;
			allocator.destroy(_arr + sz - 1);
			sz--;
		}

		size_type size() const {
			return (this->sz);
		}

		size_type capacity() const {
			return (this->cap);
		}

		size_type max_size() const {
			return (allocator.max_size());
		}

		reference 	operator[](size_type n) {
			return (_arr[n]);
		}
	};

}

#endif