#ifndef BTREE_HPP
# define BTREE_HPP
#include <iostream>
#include <memory>


namespace ft {

	template < typename T >
	struct Node {
		struct Node *_left;
		struct Node *_right;
		struct Node *_p;
		T			data;
		bool 		is_red;
	} ;

	template < 	typename Value,
				typename Compare = std::less< Value >,
				typename Alloc = std::allocator <Value> >
	class RBtree {
	public:
		typedef Value			value_type;
		typedef Compare					key_compare;
		typedef Alloc					allocator_type;
		typedef typename Alloc::pointer			pointer;
		typedef typename Alloc::size_type		size_type;
	public: // private
		Node<Value>	_root;
	public:
		RBtree():_root(NULL){
			_root = new RBtree<Value>;
		};
		Value&	minimum(){};
		Value&	maximum() {};
		RBtree*	search() {};
	};


}

#endif