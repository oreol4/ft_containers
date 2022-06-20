#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "utils.hpp"


//namespace ft {
	template<typename Iterator>
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

		reverse_iterator(const reverse_iterator &copy) { *this = copy; };


		reverse_iterator base() const { return (m_ptr); }


	private:
		pointer m_ptr;
	};

//}







#endif