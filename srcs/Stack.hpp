#ifndef STACK_HPP
# define STACK_HPP

#include <vector>
template <typename T>
class Stack
{
private:
	std::vector<T> _ptr;
public:
	Stack(){};
	~Stack(){};
	Stack &operator=(Stack const &rhs);
	Stack(Stack const &rhs)
	{
//		for (int i = 0; i < rhs._ptr.size(); i++) {
//			this->_ptr[i] = rhs._ptr[i];
//		}
	};
	void	push(T elems)
	{
		if (!elems) {
			std::cout << "Empty argument" << std::endl;
			return ;
		}
		this->_ptr.push_back(elems);
	};

	int	top()
	{
		int i = 0;
		for (;i < _ptr.size(); i++)
			if (i == _ptr.size() - 1)
				break ;
		return (_ptr[i]);
	};

	void	pop() {_ptr.pop_back();}

	int empty()
	{
		if (_ptr.size() == 0)
			return (0);
		return (1);
	};
	int	size() { return (this->_ptr.size());}
};

#endif