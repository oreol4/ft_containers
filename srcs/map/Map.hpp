#ifndef MAP_HPP
# define MAP_HPP

#include "pair.hpp"
#include <memory>
#include <cstddef>
namespace ft {

	// Compare - ключи сравниваются обычным оператором меньше (<)
	template  < class Key,
				class T,
	        	class Compare = std::less<Key>,
	        	class Allocator = std::allocator<std::pair<const Key, T> > >
	class map {
	public:
		typedef Key										key_type;
		typedef T										mapped_type;
		typedef typename 								ft::pair<const Key, T> value_type;
		typedef Compare									key_compare;
		typedef  Allocator								allocator_type;
		typedef typename Allocator::reference			reference;
		typedef typename Allocator::const_reference 	const_reference;
		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;
		typedef ptrdiff_t 								difference_type;
		typedef size_t									size_type;

	};

}

#endif