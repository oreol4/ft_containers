#ifndef BTREE_HPP
# define BTREE_HPP

template < typename T >

typedef struct Node {
	struct Node *_left;
	struct Node *_right;
	struct Node *_parent;
	bool		red;
	T			data;

} Btree;



#endif