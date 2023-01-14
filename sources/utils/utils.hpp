/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:00:07 by gkehren           #+#    #+#             */
/*   Updated: 2023/01/14 21:30:12 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <limits>

namespace ft
{
	// The type T is enabled as member type enable_if::type if Cond is true.
	template<bool Cond, typename T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	template<class T, T v>
	struct is_integral_res
	{
		static const T value = v;
		operator T() const { return value; }
	};

	// Trait class that identifies whether T is an integral type.
	template<class T>
	struct is_integral: is_integral_res<bool, std::numeric_limits<T>::is_integer> {};


	// Returns true if the range [first1,last1) compares lexicographically less than the range [first2,last2).
	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (comp(*first1, *first2))
				return true;
			if (comp(*first2, *first1))
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	// Compares the elements in the range [first1,last1) with those in the range beginning at first2,
	// and returns true if all of the elements in both ranges match.
	template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return false;
			}
		}
		return true;
	}

	template<class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!p(*first1, *first2)) {
				return false;
			}
		}
		return true;
	}

	template<class T>
	void	swap(T & a, T & b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	// This class couples together a pair of values, which may be of different types (T1 and T2).
	// The individual values can be accessed through its public members first and second.
	template <class T1, class T2>
	struct pair
	{
		T1 first;
		T2 second;

		pair() : first(), second() {};
		pair(const T1 &x, const T2 &y) : first(x), second(y) {};

		template < class U1, class U2 >
		pair(const pair<U1,U2> &x) : first(x.first), second(x.second) {};

		template< class V1, class V2 >
		pair<V1,V2>	&operator=(const pair<V1,V2> &x)
		{
			if (this == &x)
				return (*this);
			first = x.first;
			second = x.second;
			return (*this);
		}
	};

	// Constructs a pair object with its first element set to x and its second element set to y.
	template <class T1, class T2>
	pair<T1,T2>	make_pair(T1 x, T2 y)
	{
		return (pair<T1,T2>(x,y));
	};

	template<class T1, class T2>
	bool operator==(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return (x.first == y.first && x.second == y.second);
	}

	template<class T1, class T2>
	bool operator!=(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return !(x == y);
	}

	template<class T1, class T2>
	bool operator<(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return (x.first < y.first || (!(x.first < y.first) && x.second < y.second));
	}

	template<class T1, class T2>
	bool operator>(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return (y < x);
	}

	template<class T1, class T2>
	bool operator<=(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return !(y < x);
	}

	template<class T1, class T2>
	bool operator>=(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return !(x < y);
	}
}


#endif
