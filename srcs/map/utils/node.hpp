#ifndef NODE_HPP
# define NODE_HPP

#include <memory>
#include <cstddef>
#include "pair.hpp"
#include "comp.hpp"
#include <iostream>

namespace ft {
	template < typename T >

	class Node {
		public:
		typedef T	value_type;
		typedef T*	node_pointer;
		typedef const Node* const_node_pointer;
		typedef Node&	node_reference;
		typedef const Node& const_node_reference;
		//typedef value_type	value;
//		private:
		value_type	data;	
		node_pointer	__parent;
		node_pointer	__left;
		node_pointer	__right;
		bool		is_red;
	
		public:
		Node(): data(), __parent(NULL), __left(NULL), __right(NULL){
		};
		Node(const value_type val, node_pointer __parent, node_pointer __left, node_pointer __right) {
			this->__parent = __parent;
			this->__left = __left;
			this->__right = __right;
		};
		Node(const_node_reference rhs) { // list_copy?
			this->data = rhs.data;
			this->__parent = rhs.__parent;
			this->__left = rhs.__left;
			this->right = rhs.right;
			this->is_red = rhs.is_red;
		};

		const_node_reference	operator=(const_node_reference rhs) {
			if (*this == rhs) return (*this);
			this->data = rhs.data;
			this->__parent = rhs.__parent;
			this->__left = rhs.__left;
			this->__right = rhs.__right;
			this->is_red = rhs.is_red;
			return (*this);
		};
		bool	operator==(const_node_reference rhs) {
			return this->data = rhs.data;
		};
	};

	template < typename T, typename Compare = ft::less<T>, typename Node = Node<T>, typename Type_alloc = std::allocator < T >,
		typename Node_alloc = std::allocator<ft::pair<T, Node> > >
	class RBTree {
		friend Node;
		public:
			typedef T					value_type;
			typedef Compare					key_compare;
			typedef value_type			key_type;
			typedef value_type			mapped_type;
			typedef Type_alloc				allocator_type;
			typedef typename allocator_type::size_type	size_type;
			typedef Node_alloc			node_allocator;
			typedef	typename Node::node_pointer		node_pointer;
			typedef typename Node::const_node_pointer	const_node_pointer;
			typedef typename Node::node_reference		node_reference;
			typedef typename Node::const_node_reference	const_node_reference;
//		private:
		node_pointer	__root;
		node_allocator	__alloc;
		key_compare	__comp;

		public:
			RBTree(): __root(NULL), __comp(key_compare()), __alloc(node_allocator()) {
				std::cout << "aAA" << std::endl;
				__root = new Node;
			};

	};	
		 
		 










};
#endif
