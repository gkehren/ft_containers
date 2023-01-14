/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:45:47 by gkehren           #+#    #+#             */
/*   Updated: 2023/01/14 23:47:59 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
	/*-----|------------|-----*/
	/*-----| LIFO stack |-----*/
	/*-----|------------|-----*/

	// Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out),
	// where elements are inserted and extracted only from one end of the container.
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef	T			value_type;
			typedef	size_t		size_type;
			typedef	Container	container_type;

		protected:
			container_type	_ctnr;

		public:
			/*-----|-------------|-----*/
			/*-----| Constructor |-----*/
			/*-----|-------------|-----*/
			explicit stack(const container_type& ctnr = container_type()) : _ctnr(ctnr) {};

			stack(const stack& copy) { _ctnr = copy._ctnr; };
			virtual ~stack() {};

			stack	&operator=(stack const& rhs)
			{
				if (&rhs != this)
					_ctnr = rhs._ctnr;
				return (*this);
			};

			// Returns whether the stack is empty: i.e. whether its size is zero.
			bool	empty() const { return(_ctnr.empty()); };

			// Returns the number of elements in the stack.
			size_type	size() const { return(_ctnr.size()); };

			// Returns a reference to the top element in the stack.
			value_type&	top() { return(_ctnr.back()); };
			const value_type&	top() const { return (_ctnr.back()); };

			// Inserts a new element at the top of the stack, above its current top element.
			// The content of this new element is initialized to a copy of val.
			void	push(const value_type& val) { return(_ctnr.push_back(val)); };

			// Removes the element on top of the stack, effectively reducing its size by one.
			void	pop() { return(_ctnr.pop_back()); };

			// relational operators
			friend bool	operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
				{ return(lhs._ctnr == rhs._ctnr); };

			friend bool	operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
				{ return(lhs._ctnr != rhs._ctnr); };

			friend bool	operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
				{ return(lhs._ctnr < rhs._ctnr); };

			friend bool	operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
				{ return(lhs._ctnr <= rhs._ctnr); };

			friend bool	operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
				{ return(lhs._ctnr > rhs._ctnr); };

			friend bool	operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
				{ return(lhs._ctnr >= rhs._ctnr); };
	};
};

#endif
