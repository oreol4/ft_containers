#ifndef	ITERATOR_HPP
# define ITERATOR_HPP

#include "utils.hpp"
#include "Vector.hpp"
namespace ft {

	template < typename Category , typename RAI, typename Distance = ptrdiff_t,
	        typename Pointer = RAI*, typename Reference = RAI&>
	class	RAIterator {
	public:
		//							MEMBER TYPES			//
		typedef RAI	value_type;
		typedef Distance	different_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;

		//							MEMBER OPERATORS		//
		RAIterator():m_ptr(NULL){};

		RAIterator(pointer ptr):m_ptr(ptr){};

		RAIterator(const RAIterator	& copy) { *this = copy;}

		RAIterator&	operator++() { this->m_ptr++; return(*this); }
		RAIterator	operator++(int) { RAIterator	tmp(*this); this->m_ptr++; return(tmp); }

		RAIterator&	operator--() {this->m_ptr--; return RAIterator(*this); }

		RAIterator&	operator--(int) { RAIterator	tmp(*this); this->m_ptr--; return (tmp);}

		RAIterator	operator-(different_type n) const { return RAIterator(this->m_ptr - n);}

		RAIterator	operator+(different_type n) const { return RAIterator(this->m_ptr + n);}

		reference 	operator[](different_type n) { return *(this + n); } // bad work

		RAIterator operator+=(different_type n) { return RAIterator(this->m_ptr += n); }

		RAIterator	operator-=(different_type n) { return RAIterator(this->m_ptr -= n);}

		template < typename U >
		RAIterator&	operator=(const RAIterator<random_access_iterator_tag, U> &rhs) { *this = rhs; return (*this);}

		reference 	operator*() { return (*m_ptr);}

		pointer operator->() { return (this->m_ptr); }

		template < typename U >
		bool operator<(const RAIterator<random_access_iterator_tag, U> &rhs) { return ( this->m_ptr < rhs.m_ptr); }

		template < typename U >
		bool operator<=(const RAIterator<random_access_iterator_tag, U> &rhs) { return ( this->m_ptr <= rhs.m_ptr); }

		template < typename U >
		bool operator>(const RAIterator<random_access_iterator_tag, U> &rhs) {return ( this->m_ptr > rhs.m_ptr); }

		template < typename U >
		bool	operator>=(const RAIterator<random_access_iterator_tag, U> &rhs) { return (this->m_ptr >= rhs.m_ptr); }

		template < typename U >
		bool operator==(const RAIterator<random_access_iterator_tag, U> &rhs) {return (this->m_ptr == rhs.m_ptr); }

		template < typename U >
		bool operator!=(const RAIterator<random_access_iterator_tag, U> &rhs) { return (this->m_ptr != rhs.m_ptr); }

//		friend class vector;
	protected:
		pointer m_ptr;
	};


}
#endif