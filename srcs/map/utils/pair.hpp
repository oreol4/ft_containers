#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

	template <typename T1, typename T2>

	struct pair {
		T1	first_args;
		T2	second_args;

		pair(): first_args(), second_args() {};

		pair(const T1& a, const T2& b) : first_args(a), second_args(b){};

		~pair(){};

		template < class U, class V >
		pair(const pair<U, V>& other): first_args(other.first_args), second_args(other.second_args){
			this->first_args = other.first_args;
			this->second_args = other.second_args;
		};
		pair<T1,T2> &operator=(const pair& other){
			this->first_args = other.first_args;
			this->second_args = other.second_args;
			return (*this);
		}
	};

	template < typename T1, typename T2 >

	pair<T1, T2>	make_pair(T1 x, T2 y) { // work with different type T1 and T2 -> fix this.
		return pair<T1, T2>(x,y);
	}

	template < class T1, class T2 >
	bool	operator== (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (lhs.first_args==rhs.first_args && lhs.second_args == rhs.second_args);
	}

	template < class T1, class T2 >
	bool	operator!= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (lhs.first_args!= rhs.first_args || lhs.second_args != rhs.second_args);
	}

	template < class T1, class T2 >
	bool	operator< (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
	}

	template < class T1, class T2 >
	bool	operator> (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return rhs<lhs;
	}

	template < class T1, class T2 >
	bool	operator<= (const pair<T1, T2>&lhs, const pair<T1, T2>& rhs) {
		return !(rhs<=lhs);
	}

	template < class T1, class T2 >
	bool	operator>= (const pair<T1, T2>&lhs, const pair<T1, T2>& rhs) {
		return !(lhs<rhs);
	}

}

#endif
