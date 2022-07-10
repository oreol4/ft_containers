#ifndef STACK_HPP
# define STACK_HPP
#include <vector>
#include "../vector/Vector.hpp"
namespace  ft {
	template<typename T, typename Container = ft::vector<T> >
	class stack {
	protected:
		Container c;
	public:
		typedef Container container_type;
		typedef typename Container::value_type value_type;
		typedef typename container_type::reference reference;
		typedef typename container_type::const_reference const_reference;
		typedef size_t	size_type;

		explicit stack() {};

		~stack() {};
		stack(const stack &rhs) { this->c = rhs.c;}
		stack	&operator=(const stack &rhs) {
			this->c = rhs.c;
			return (*this);
		}
		//MEMBER FUNCTION
		void 		push(const value_type &elems) { this->c.push_back(elems);}
		void 		pop() { this->c.pop_back();}
		reference 	top() { return (this->c.back()); }
		const_reference top() const { return (this->c.back());}
		size_type 	size() { return (this->c.size());}
		bool		empty() const {return (this->c.size() == 0 ? true : false);}
		void	dispStack() {
			for (size_t i = 0;i < c.size();i++) {
				std::cout << c[i] <<  " ";
			}
			std::cout << std::endl;
		}
		//NON MEMBER FUNCTION

		/*Дружественные функции в C++ — это функции, объявленные вне класса, но
		 * способные обращаться к закрытым и защищенным членам класса.
		 * В программировании могут быть ситуации, когда мы хотим, чтобы два класса делили своих членов.
		 * Эти элементы могут быть элементами данных, функциями класса или шаблонами функций.
		 * В таких случаях мы делаем нужную функцию другом для обоих этих классов, которая позволит получить доступ
		 * к закрытым и защищенным данным членов класса.
		 * Как правило, функции, не являющиеся членами, не могут получить доступ к закрытым членам определенного класса.
		 * После объявления функции друга функция может получить доступ к закрытым и защищенным членам этих классов.*/
		template < typename A , typename B>
		friend bool operator==(const ft::stack<A , B>&lhs, const ft::stack<A, B>&rhs);
		template < typename A , typename B>
		friend bool operator >= (const ft::stack<A, B> &lhs, const ft::stack<A, B> &rhs);
		template < typename A , typename B>
		friend bool operator <= (const ft::stack<A, B> &lhs, const ft::stack<A, B> &rhs);
		template < typename A , typename B>
		friend bool operator > (const ft::stack<A, B> &lhs, const ft::stack<A, B> &rhs);
		template < typename A , typename B>
		friend bool operator < (const ft::stack<A, B> &lhs, const ft::stack<A, B> &rhs);
		template < typename A , typename B>
		friend bool operator != (const ft::stack<A, B> &lhs, const ft::stack<A, B> &rhs);
	};
		template < typename A , typename B>
			bool operator==(const ft::stack<A , B>&lhs, const ft::stack<A, B>&rhs) {
			return (lhs.c==rhs.c);
		}

		template < typename A, typename B >
			bool operator >= (const ft::stack<A, B> &lhs, const ft::stack<A, B> &rhs) {
			return (lhs.c >= rhs.c);
		}

		template < typename A, typename B >
			bool operator <= (const ft::stack<A, B> &lhs, const ft::stack<A, B> &rhs) {
			return (lhs.c <= rhs.c);
		}

		template < typename A, typename B >
			bool operator > (const ft::stack<A, B> &lhs, const ft::stack<A, B> &rhs) {
			return (lhs.c > rhs.c);
		}

		template < typename A, typename B >
			bool operator < (const ft::stack<A, B> &lhs, const ft::stack<A, B> &rhs) {
			return (lhs.c < rhs.c);
		}

		template < typename A, typename B >
			bool operator != (const ft::stack<A, B> &lhs, const ft::stack<A, B> &rhs) {
			return (lhs.c != rhs.c);
		}
}

#endif