#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "utils.hpp"
#include "Vector.hpp"

namespace ft {
	template <typename Iterator>
	class reverse_iterator {
	public:
		typedef Iterator iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer pointer;
		typedef typename ft::iterator_traits<Iterator>::reference reference;


		reverse_iterator() : m_ptr(NULL) {};

		explicit reverse_iterator(iterator_type it) : m_ptr(it) {};

		reverse_iterator(iterator_type &copy)
		{
			Iterator tmp = copy;
			m_ptr = tmp;
		};

		reference	operator*() const {
			iterator_type tmp = m_ptr;
			return *(--tmp);
		}

		reverse_iterator	operator++(int) {
			reverse_iterator tmp = *this;
			++(*this);
			return tmp;
		}

		reverse_iterator&	operator++() {
			m_ptr++;
			return (*this);
		}

		reverse_iterator	operator--(int) {
			reverse_iterator tmp = *this;
			--(*this);
			return (tmp);
		}

		reverse_iterator&	operator--() {
			m_ptr--;
			return (*this);
		}

		reverse_iterator	operator+ (difference_type n) const {
			return reverse_iterator(this->m_ptr - n);
		}

		reverse_iterator	operator- (difference_type n) const {
			return reverse_iterator(this->m_ptr + n);
		}

		reverse_iterator	operator+= (difference_type n) const {
			m_ptr -= n;
			return reverse_iterator(m_ptr);
		}

		reverse_iterator	operator-= (difference_type n) const {
			m_ptr += n;
			return reverse_iterator(m_ptr);
		}

		pointer operator-> () const {
			return &(operator*());
		}

		reference operator[] (difference_type n) const {
			return *(m_ptr -n);
		}

		iterator_type base() const {
			return (this->m_ptr);
		};

		template < typename Iter >
		bool	operator== (const reverse_iterator<Iter>& rhs) {
			return (this->base() == rhs.base());
		}
//
		template < typename Iter >
		bool	operator!= (const reverse_iterator<Iter>& rhs) {
			return (this->base()!=rhs.base());
		}
//
		template < typename Iter >
		bool operator< (const reverse_iterator<Iter>& rhs) {
			return (this->base() < rhs.base());
		}

		template < typename Iter >
		bool operator> (const reverse_iterator<Iter>& rhs) {
			return (this->base() > rhs.base());
		}

		template < typename Iter >
		bool operator>= (const reverse_iterator<Iter>& rhs) {
			return (this->base() >= rhs.base());
		}

		template < typename Iter >
		bool operator<= (const reverse_iterator<Iter>& rhs) {
			return (this->base() <= rhs.base());
		}
	private:
		Iterator m_ptr;
	};

}







#endif