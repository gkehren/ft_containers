/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:45:47 by gkehren           #+#    #+#             */
/*   Updated: 2023/01/11 16:23:50 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
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
			explicit stack(const container_type& ctnr = container_type()) : _ctnr(ctnr) {};

			stack(const stack& copy) { _ctnr = copy._ctnr; };
			virtual ~stack() {};

			stack	&operator=(stack const& rhs)
			{
				if (&rhs != this)
					_ctnr = rhs._ctnr;
				return (*this);
			};

			value_type&	top() { return(_ctnr.back()); };
			const value_type&	top() const { return (_ctnr.back()); };

			bool	empty() const { return(_ctnr.empty()); };

			size_type	size() const { return(_ctnr.size()); };

			void	push(const value_type& val) { return(_ctnr.push_back(val)); };

			void	pop() { return(_ctnr.pop_back()); };

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
