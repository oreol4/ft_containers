#ifndef BTREE_HPP
# define BTREE_HPP
#include <iostream>
#include <memory>

#define RED 1
#define BLACK 0

namespace ft {

	/*template < typename T >
	struct Node {
		T data;
		struct Node *__left;
		struct Node *__right;
		struct Node *__parent;
		int	    is_red;	
	};*/
	
	template < typename Key, typename T, typename Compare = std::less<Key> ,
		 typename Alloc = std::allocator< std::pair<const Key, T> > >
	class map {
		public:
		typedef Key	key_type;
		typedef T	mapped_type;
		typedef	Alloc	value_type;
		typedef Compare	key_compare;
		//typedef		value_compare; todo this
		typedef Alloc					allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer	  pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		//iterators .
		// difference_type
		// size_type
	//	private:

	//	template < typename T >
		struct Node {
			T data;
			struct Node *__left;
			struct Node *__right;
			struct Node *__parent;
			int	    is_red;	
		};
		//private:
		size_t		__size;
		allocator_type	__alloc;
		Node	*__root;
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
			__root = new Node;
			__alloc = alloc;
			__size = 0;
			__root->is_red = BLACK;
		};
		public:
		
		struct Node	*insertNode(Node *__root, const value_type& data) {
			
			Node *__tmpNode = __root;
			if (!__tmpNode) {
				__tmpNode = new Node;
			}
			if (__root->data > data) {
				__tmpNode = insertNode(__tmpNode->right, data);
			}  else if (__root->data < data) {
				insertNode(__tmpNode->left, data);
			}
			__tmpNode->data = data;
			    
		}
	};

}

#endif
