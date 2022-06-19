#ifndef UTILS_HPP
# define UTILS_HPP

#include <cstddef>
#include "Vector.hpp"
#include "utils.hpp"
struct input_iterator_tag{};
struct output_iterator_tag{};
struct forward_iterator_tag: public input_iterator_tag{};
struct bidirection_iterator_tag:public forward_iterator_tag {};
struct random_access_iterator_tag:public bidirection_iterator_tag{};

namespace  ft {

	template<typename Iter>
	struct iterator_traits {
		typedef typename Iter::value_type value_type;
		typedef typename Iter::difference_type difference_type;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::reference reference;
		typedef typename Iter::iterator_category iterator_category;
	};

	template<typename T>
	struct iterator_traits<T *> {
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T *pointer;
		typedef T &reference;
		typedef random_access_iterator_tag iterator_category;
	};


	template<typename InputIterator>
	typename iterator_traits<InputIterator*>::difference_type distance(InputIterator first, InputIterator last) {
		size_t dist = 0;
		for (; first != last; first++) {
			dist++;
		}
		return (dist);
	}

	template < typename T >
	struct is_integral {static const bool value = false;};

	template <>
	struct	is_integral<bool>					{static const bool value = true;};
	template <>
	struct	is_integral<char>					{static const bool value = true;};
	template <>
	struct	is_integral<char16_t>				{static const bool value = true;};
	template <>
	struct	is_integral<char32_t>				{static const bool value = true;};
	template <>
	struct	is_integral<wchar_t>				{static const bool value = true;};
	template <>
	struct	is_integral<signed char>			{static const bool value = true;};
	template <>
	struct 	is_integral<short int>				{static const bool value = true;};
	template <>
	struct	is_integral<int>					{static const bool value = true;};
	template <>
	struct	is_integral<long int>				{static const bool value = true;};
	template <>
	struct	is_integral<long long int>			{static const bool value = true;};
	template <>
	struct	is_integral<unsigned char>			{static const bool value = true;};
	template <>
	struct	is_integral<unsigned short int>		{static const bool value = true;};
	template <>
	struct 	is_integral<unsigned int>			{static const bool value = true;};
	template <>
	struct 	is_integral<unsigned long int>		{static const bool value = true;};
	template <>
	struct 	is_integral<unsigned long long int>	{static const bool value = true;};

	template < bool B, typename T = void >
	struct enable_if {};

	template < typename T >
	struct enable_if<true, T> {typedef T type;};

}



#endif