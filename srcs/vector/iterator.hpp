#ifndef	ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef>


struct input_iterator_tag{};
struct output_iterator_tag{};
struct forward_iterator_tag: public input_iterator_tag{};
struct bidirectional_iterator_tag: public forward_iterator_tag{};
struct random_access_iterator_tag: public bidirectional_iterator_tag {};


namespace ft {

		template < typename Iter >
		struct iterator_traits {
			typedef typename Iter::difference_type difference_type;
			typedef typename Iter::value_type	value_type;
			typedef typename Iter::pointer		pointer;
			typedef typename Iter::reference	reference;
			typedef typename Iter::iterator_category	iterator_category;
		};

		template < typename T >
		struct iterator_traits< T* > {
			typedef ptrdiff_t			difference_type;
			typedef T					value_type;
			typedef T*					pointer;
			typedef T&					reference;
			typedef random_access_iterator_tag iterator_category;
		};
		template < typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
		class Iterator {
			typedef T			value_type;
			typedef Distance different_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
		};
		template < typename T >
		class RAIterator: public {
		public:
			typedef typename Iterator<random_access_iterator_tag, T>::value_type 	value_type;
			typedef typename Iterator<random_access_iterator_tag, T>::pointer 		pointer;
			typedef typename Iterator<random_access_iterator_tag, T>::reference 	reference;
			typedef typename Iterator<random_access_iterator_tag, T>::different_type different_type;
			typedef typename Iterator<random_access_iterator_tag, T>::iterator_category iterator_category;
		protected:
			pointer	_ptr;
		};
}

#endif