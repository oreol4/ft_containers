#ifndef	ITERATOR_HPP
# define ITERATOR_HPP





#include <cstddef>
namespace ft {

//	template < typename T >
//	class BidirectionalIterator {
//
//	};

template <class Category, class T, class Distance = ptrdiff_t,
		class Pointer = T*, class Reference = T&>
class Iterator {
public:
	typedef T	value_type;
	typedef Distance difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};



	struct Input_iterator_tag {};
	struct Output_iterator_tag{};
	struct Forward_iterator_tag:public Input_iterator_tag{};
	struct Bidirectional_iterator_tag:public Forward_iterator_tag{};
	struct RandomAccess_iterator_tag:public Bidirectional_iterator_tag{};




template < typename T >
class RandomAccess_iterator
{
public:
	typedef typename ft::Iterator<RandomAccess_iterator_tag, T >::value_type value_type;
	typedef typename ft::Iterator<RandomAccess_iterator_tag, T>::pointer 		pointer;
	typedef typename ft::Iterator<RandomAccess_iterator_tag, T>::difference_type difference_type;
	typedef typename ft::Iterator<RandomAccess_iterator_tag, T>::reference reference;
	typedef typename ft::Iterator<RandomAccess_iterator_tag, T>::iterator_category iterator_category;

	RandomAccess_iterator():_ptr(NULL){};
	RandomAccess_iterator(const RandomAccess_iterator<T>& rhs){
		_ptr = rhs._ptr;
	}
	bool	operator==(const RandomAccess_iterator<T> &lhs) const {
		return (this->_ptr == lhs._ptr);
	}
	~RandomAccess_iterator(){};

private:
	pointer *_ptr;
} ;


	template <typename T>
struct iterator_traits{
	typedef typename T::value_type				value_type;
	typedef typename T::difference_type       	difference_type;
	typedef typename T::pointer               	pointer;
	typedef typename T::reference             	reference;
	typedef typename T::iterator_category     	iterator_category;
	};
template < typename T >

struct iterator_traits<T *> {
	typedef	T				value_type;
	typedef ptrdiff_t		difference_type;
	typedef T*				pointer;
	typedef T&				reference;
	typedef RandomAccess_iterator_tag iterator_category;
};








}




#endif