#ifndef COMP_HPP
# define COMP_HPP


namespace ft {

	template < typename T >
struct less {
		T	first_argument_type;
		T	second_argument_type;
		bool	result_type;
		bool	operator()(const T& x, const T& y) const {
			return x<y;
		};	
	};
};
#endif 
