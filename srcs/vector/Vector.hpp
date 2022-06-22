#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>
#include <exception>
//#include <vector>
#include "iterator.hpp"
#include <memory>
#include <cassert>
#include <iterator>
#include "utils.hpp"
#include "reverse_iterator.hpp"
namespace ft {

	template<typename T, typename Allocator = std::allocator <T> >
	class vector {
	public:
		//						MEMBER TYPES
		typedef T 																	value_type;
		typedef Allocator 															allocator_type;
		typedef typename allocator_type::reference 									reference;
		typedef typename allocator_type::const_reference 							const_reference;
		typedef typename allocator_type::pointer 									pointer;
		typedef typename allocator_type::const_pointer 								const_pointer;
		// iterators member types
		typedef typename allocator_type::size_type 									size_type;
		typedef typename allocator_type::difference_type 							difference_type;
		typedef RAIterator< std::random_access_iterator_tag, value_type >				iterator; // can use pointer from allocator
		typedef RAIterator< std::random_access_iterator_tag, const value_type>			const_iterator;
//		typedef reverse_iterator<iterator>											reverse_iterator;
		// iterators member types

		explicit vector(const allocator_type& alloc = allocator_type()):_arr(nullptr), sz(0), cap(0),
			allocator(alloc){};

		explicit vector(size_type n, const value_type& val = value_type(),
			   const allocator_type& alloc = allocator_type()):_arr(0), sz(n),cap(n),allocator(alloc) {
			   //: sz(n), cap(n),
//			   allocator(alloc){
//			_arr = allocator.allocate(n);
//			for (size_t i = 0; i < n; i++) { allocator.construct(_arr + i, val);
				_arr = allocator.allocate(n);
				try
				{
					for (size_type i = 0; i < sz; i++)
						allocator.construct(_arr + i, val);
				}
				catch (...)
				{
					allocator.deallocate(_arr, n);
					_arr = nullptr;
					throw std::logic_error("Error: _alloc failed");
				}
		}
//		template < typename InputIterator >
//			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()):_arr(0), sz(0), cap(0), allocator(alloc) {
//			sz = ft::distance(first, last);
//			cap = sz;
//			_arr = allocator.allocate(cap);
//			for (;first != last;first++) {
//				allocator.construct(_arr + first);
//			}
//		}
		~vector(){
			for (size_t i = 0; i < cap; i++) {
				allocator.destroy(_arr + i);
			}
			if (cap)
				allocator.deallocate(_arr, cap);
		}

		vector(const vector<T> &rhs):_arr(rhs._arr), allocator(rhs.allocator), cap(rhs.cap), sz(rhs.sz){};

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

		iterator insert (iterator position, const value_type& val) {
			std::cout << sz << " " << cap << std::endl;
			if (position == begin())
			{
				if (sz == cap)
					reserve(cap * 2);
				T *newPtr;
				newPtr = allocator.allocate(cap);
				sz++;
				allocator.construct(newPtr, val);
				try {
					std::uninitialized_copy(_arr, _arr + sz, newPtr + 1);
				} catch(...) {
					allocator.deallocate(newPtr, cap);
				}
				allocator.deallocate(_arr, sz);
				for (size_t i = 0;i < sz; i++) {
					allocator.destroy(_arr + i);
				}
				_arr = newPtr;
				for (size_t i = 0;i < sz; i++) {
					std::cout << _arr[i] << std::endl;
				}
			}
			else if (position == end()) {
				if (sz == cap)
					reserve(cap * 2);

				std::cout << "END " << val << std::endl;
			}
			return (iterator(_arr));
		}

//		void	dispVector() {
//			ft::RAIterator<std::random_access_iterator_tag, T> ite = this->end();
//			for (ft::RAIterator<std::random_access_iterator_tag, T> it = this->begin(); it < ite; it++) {
//				std::cout << *it << " ";
//			}
//			std::cout << std::endl;
//		}

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
				}
				sz = n;
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
			++sz;
		}

		void pop_back() {
			if (sz == 0) return;
			allocator.destroy(_arr + sz - 1);
			sz--;
		}


//		template < typename InputIterator >
//		void	assign(InputIterator first, InputIterator last)
//		{
//			(void)first;
//			(void)last;
//			std::cout << "AA" << std::endl;
//		}; // ????

		void	assign(size_type n, const value_type& val) {
			if (n > cap) {
				resize(n);
			}
			else if (n < sz) {
				resize(n);
			}
			for (size_t i = 0;i < n; i++) {
				*(_arr + i) = val;
			}
		};
//

		iterator 			begin() { return (iterator (_arr));}

		const_iterator		begin() const {return(const_iterator (_arr));} ;

		iterator			end() { return (iterator (_arr + sz)); }

		const_iterator 		end() const {return (const_iterator (_arr + sz));}

		size_type 			size() const { return (this->sz);}

		size_type 			capacity() const { return (this->cap);}

		size_type 			max_size() const { return (allocator.max_size());}

		bool empty() 		const {return (sz > 0 ? 0 : 1);}

		reference 			operator[](size_type n) { return (_arr[n]); }

		reference 			at(size_type n) { return *(_arr + n);}

		const_reference 	at(size_type n) const { return *(_arr + n); }

		reference			front() { return *(_arr); }

		const_reference 	front() const { return *(_arr); }

		reference			back() { return *(_arr + sz - 1); }

		const_reference 	back() const {return *(_arr + sz - 1); }

		template < typename value_type, typename Alloc >
		friend bool operator== (const ft::vector<value_type , Alloc>& rhs, const ft::vector<value_type, Alloc>& lhs);

		template < typename value_type , typename Alloc >
		friend bool operator!= (const ft::vector<value_type, Alloc>& rhs, const ft::vector<value_type, Alloc>& lhs);

		template < typename value_type , typename Alloc >
		friend bool operator< (const ft::vector<value_type, Alloc>& rhs, const ft::vector<value_type, Alloc>& lhs);

		template < typename value_type , typename Alloc >
		friend bool operator<= (const ft::vector<value_type, Alloc>& rhs, const ft::vector<value_type, Alloc>& lhs);

		template < typename value_type , typename Alloc >
		friend bool operator> (const ft::vector<value_type , Alloc>& rhs, const ft::vector<value_type , Alloc>& lhs);

		template < typename value_type , typename Alloc >
		friend bool operator>= (const ft::vector<value_type , Alloc>& rhs, const ft::vector<value_type , Alloc>& lhs);

	protected:
		pointer _arr;
		size_t sz;
		size_t cap;
		Allocator allocator;
	};

	template < typename InputIterator1, typename InputIterator2 >
	bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
		while (first1 != last1) {
			if ((*first1 != *first2)) return (false);
			++first1; ++first2;
		}
		return (true);
	}

	template < typename InputIterator1, typename InputIterator2 >
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
		while (first1 != last1) {
			if (first2==last2 || *first2<*first1) return (false);
			else if (*first1<*first2) return (true);
			++first1; ++first2;
		}
		return (first2!=last2);
	}

	template < typename T, typename Alloc >
	bool operator== (const ft::vector<T, Alloc>& rhs, const ft::vector<T, Alloc>& lhs) {
		return (rhs.size() == lhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()) ? true : false);
	}

	template < typename T, typename Alloc >
	bool operator!= (const ft::vector<T, Alloc>& rhs, const ft::vector<T, Alloc>& lhs) {
		if (rhs.size() != lhs.size() || !ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
			return (true);
		return (false);
	}

	template < typename T, typename Alloc >
	bool operator< (const ft::vector<T, Alloc>& rhs, const ft::vector<T, Alloc>& lhs) {
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template < typename T, typename Alloc >
	bool operator<= (const ft::vector<T, Alloc>& rhs, const ft::vector<T, Alloc>& lhs) {
		return (!(lhs < rhs));
	}

	template < typename T, typename Alloc >
	bool operator> (const ft::vector<T, Alloc>& rhs, const ft::vector<T, Alloc>& lhs) {
		return (rhs < lhs);
	}

	template < typename T, typename Alloc >
	bool operator>= (const ft::vector<T, Alloc>& rhs, const ft::vector<T, Alloc>& lhs) {
		return (!(lhs < rhs));
	}
}

#endif