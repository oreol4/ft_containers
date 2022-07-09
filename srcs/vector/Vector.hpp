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
		typedef ft::RAIterator< std::random_access_iterator_tag, value_type >				iterator; // can use pointer from allocator
		typedef ft::RAIterator< std::random_access_iterator_tag, const value_type>			const_iterator;
//		typedef reverse_iterator<iterator>											reverse_iterator;
		typedef ft::reverse_iterator<iterator>											reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>									const_reverse_iterator;
		// iterators member types

		explicit vector(const allocator_type& alloc = allocator_type()):_arr(0), sz(0), cap(0),
			allocator(alloc){
		};
//
		explicit vector(size_type n, const value_type& val = value_type(),
			   const allocator_type& alloc = allocator_type()): sz(n),cap(n),allocator(alloc) {
				_arr = allocator.allocate(n);
				for (size_type i = 0;i < n; i++) {
					allocator.construct(_arr + i, val);
				}
//				sz = n;
//				cap = n;
		}

		vector&	operator=(const vector& x){
			allocator.deallocate(_arr, cap);
			this->sz = x.sz;
			this->allocator = x.allocator;
			this->cap = x.cap;
			this->_arr = x._arr;
			this->_arr =  allocator.allocate(x.cap);
			for (size_type i = 0;i < sz; i++) {
				allocator.construct(_arr + i, *(x._arr + i));
			}
			return (*this);
		}


		template < typename InputIterator >
			vector(InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type& alloc = allocator_type()):_arr(0), sz(0), cap(0), allocator(alloc) {
			sz = ft::distance(first, last);
			cap = sz;
			T *newPtr;

			newPtr = allocator.allocate(sz);
			for (size_t i = 0;i < sz; i++) {allocator.construct(newPtr + i);}
			size_t i = 0;
			while (first != last) {
				newPtr[i] = *first;
				first++;
				i++;
			}
			_arr = newPtr;
		}

		~vector(){
			for (size_t i = 0; i < sz; i++)
				allocator.destroy(_arr + i);
			if (_arr || cap)
				allocator.deallocate(_arr, sz);
		}

		vector(const vector<value_type> &rhs):_arr(rhs._arr), sz(rhs.sz), cap(rhs.cap), allocator(rhs.allocator){
			_arr = allocator.allocate(rhs.sz);
			for (size_t i = 0;i < rhs.sz; i++) { allocator.construct(_arr + i, *(rhs._arr + i));}
		};
		// in vector constructor ^^^^^^^^
		void reserve(size_type n) {
			if (n > cap && n < max_size())
			{
				T *newPtr;
				newPtr = allocator.allocate(n);
				try {
					std::uninitialized_copy(_arr, _arr + sz, newPtr);
				} catch(...) {
					allocator.deallocate(newPtr, n);
					throw ;
				}
				allocator.deallocate(_arr, cap);
				_arr = newPtr;
				cap = n;
			}
		}

		iterator insert (iterator position, const value_type& val) {

			if (position < this->begin() || position > this->begin())
				std::logic_error("error");
			if (cap < sz + 1)
				reserve(cap * 2);
			size_t distValueAppend = 0;
			size_t i = 0;
			distValueAppend = static_cast<size_t>(ft::distance(begin(), position));
			for (i = 0; distValueAppend + i != sz ;i++) {
				allocator.construct(_arr + sz - i, *(_arr + sz - i - 1));
				allocator.destroy(_arr + sz - i - 1);
			}
			allocator.construct(_arr + distValueAppend, val);
			sz++;
			return iterator(begin() + distValueAppend);
		}

		void insert (iterator position, size_type n, const value_type& val) {
			pointer newPtr = NULL;
			size_t capacity = 0;
			if (sz + n > cap && sz + n > cap * 2)
				capacity = sz + n;
			else if (sz + n > cap && sz + n < cap * 2)
				capacity = cap + cap;
			else
				capacity = cap;
			newPtr = allocator.allocate(capacity);
			size_t distToAdd = static_cast<size_t>(ft::distance(begin(), position));
			size_t i = 0;
			for (;i < distToAdd; i++) {
				allocator.construct(newPtr + i, _arr[i]);
			}
			size_t j = i;
			for (size_t j = 0; j < n; j++) {
				allocator.construct(newPtr + i, val);
				i++;
			}
			for (;j < sz; j++) {
				allocator.construct(newPtr + i, _arr[j]);
				i++;
			}
			for (size_t j = 0;j < sz;j++) {
				allocator.destroy(_arr + j);
			}
			allocator.deallocate(_arr, cap);
			_arr = newPtr;
			sz = sz + n;
			cap = capacity;
		}

	/*	template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last) {
			if (position < this->begin() || position > this->begin())
				std::logic_error("error");
			size_t countNewElement = static_cast<size_t>(ft::distance(first, last));
			size_t distToAddElement = static_cast<size_t>(ft::distance(begin(), position));
			size_t countVector = sz - distToAddElement;
			size_t endElement = static_cast<size_t>(ft::distance(last, end()));

			if (countNewElement > cap * 2)
				reserve(countNewElement + sz);
			else if (countNewElement + sz > cap && countNewElement + sz < cap * 2)
				reserve(cap * 2);
			std::cout << endElement << std::endl;
			for (size_t i = 0;i < endElement;i++) {
				allocator.construct(_arr + sz + countNewElement + i, *(_arr + endElement + i));
				sz++;
			}
			for (size_t i = 0; i < countNewElement; i++) {
				allocator.construct(_arr + distToAddElement + i, *(first));
				first++;
			}
//			_arr = newPtr;
			std::cout << "distToAddElement " << distToAddElement << std::endl;
			std::cout << "countNewElement  " << countNewElement << std::endl;
			std::cout << "countVector      " << countVector << std::endl;


		}*/


		void	dispVector() {
			ft::RAIterator<std::random_access_iterator_tag, T> ite = this->end();
			for (ft::RAIterator<std::random_access_iterator_tag, T> it = this->begin(); it < ite; it++) {
				std::cout << *it << " ";
			}
			std::cout << std::endl;
		}

		void resize (size_type n, value_type val = value_type()) {
			if (n < sz) {
				for (size_t i = n; i < sz; i++) {
					allocator.destroy(_arr + i);
				}
				sz = n;
			}else if (n > sz && n < max_size()) {
				if (n > cap && n <= cap * 2)
					reserve(cap * 2);
				else if (n > cap * 2)
					reserve(n);
				for (;sz < n; sz++) {
					allocator.construct(_arr + sz, val);
				}
			}
		}

		iterator	erase(iterator position) {
			if (position < begin() || position > end())
				std::logic_error("error");
			if (position == end())
				return end();
			size_t dist = static_cast<size_t>(ft::distance(begin(), position));
			allocator.destroy(_arr + dist);
			size_t i = 0;
			while(dist + i != sz - 1) {
				allocator.construct(_arr + dist + i, *(_arr + dist + i + 1));
				allocator.destroy(_arr + dist + i + 1);
				++i;
			}
			sz--;
			return iterator(begin() + dist);
		}

		iterator	erase(iterator first, iterator last) {
			if (sz == 0)
				return end();
			size_t	deleteItems = static_cast<size_t>(ft::distance(first, last));
			size_t	replaceLastItem = static_cast<size_t>(ft::distance(last, end()));
			size_t 	startDeleteItems = static_cast<size_t>(ft::distance(begin(), first));
			size_t 	addedItems = static_cast<size_t>(ft::distance(begin(), last));
			for (size_t i = startDeleteItems;i < deleteItems;i++) {
				allocator.destroy(_arr + i);
			}
			size_t i = 0;
			for (;i < replaceLastItem;i++) {
				allocator.construct(_arr + startDeleteItems + i, *(_arr + addedItems + i));
			}
			sz -= deleteItems;
			return iterator(begin() + startDeleteItems);
		};

		void push_back (const value_type& val) {
			if (!sz)
				reserve(1);
			else if (sz == cap)
				reserve(cap * 2);
			allocator.construct(_arr + sz, val);
			sz++;
		}

		void pop_back() {
			if (sz == 0) return;
			allocator.destroy(_arr + sz - 1);
			sz--;
		}

		void	assign(size_type n, const value_type& val) {
			if (sz > 0)
				clear();
			if (n > cap)
				reserve(n);
			for (size_t i = 0;i < n; i++) {
				allocator.construct(_arr + i, val);
			}
			sz = n;
		};

		template < typename InputIterator >

		void	assign(InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last) {
			if (sz > 0)
			{
				allocator.deallocate(_arr, sz);
				for (size_t i = 0; i < sz;i++) {
					allocator.destroy(_arr + i);
				}
			}
			size_t i = 0;
			sz = ft::distance(first, last);
			cap = sz;
			_arr = allocator.allocate(sz);
			while (first != last) {
				allocator.construct(_arr + i, *first);
				first++;
				i++;
			}
//			for (size_t i = 0; i < sz;i++) {
//				allocator.destroy(_arr + i);
//			}
//			while (first != last) {
//				push_back(*first);
//				first++;
//			}
		}

		void	clear() {
			for (size_t i = 0;i < sz; i++) {
				allocator.destroy(_arr + i);
			}
			sz = 0;
		}

		void	swap(ft::vector<value_type> &x) {
			std::swap(this->allocator, x.allocator);
			std::swap(this->sz, x.sz);
			std::swap(this->cap, x.cap);
			std::swap(this->_arr, x._arr);
		}

		const_reverse_iterator rbegin() const {return const_reverse_iterator(end());}

		reverse_iterator	rbegin() { return reverse_iterator(end());}

		const_reverse_iterator rend() const {return const_reverse_iterator (_arr);}

		reverse_iterator	rend()	{return reverse_iterator(_arr);}

		iterator 			begin() { return (iterator (_arr));}

		const_iterator		begin() const {return(const_iterator (_arr));} ;

		iterator			end() { return (iterator (_arr + sz)); }

		const_iterator 		end() const { return (const_iterator (_arr + sz));}

		size_type 			size() const { return (this->sz);}

		size_type 			capacity() const { return (this->cap);}

		size_type 			max_size() const { return (allocator.max_size());}

		bool empty() 		const {return (sz > 0 ? 0 : 1);}

		reference 			operator[](size_type n) { return (_arr[n]); }

		reference 			at(size_type n) { if (n >= sz) std::out_of_range("Bad index"); return *(_arr + n);}

		const_reference 	at(size_type n) const { if (n >= sz) std::out_of_range("Bad index"); return *(_arr + n); }

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
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template < typename T, typename Alloc >
	bool operator<= (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return (!(rhs < lhs));
	}

	template < typename T, typename Alloc >
	bool operator> (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return (rhs < lhs);
	}

	template < typename T, typename Alloc >
	bool operator>= (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return (!(lhs < rhs));
	}
}

#endif