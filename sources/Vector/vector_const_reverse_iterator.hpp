/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_const_reverse_iterator.hpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:33:03 by gkehren           #+#    #+#             */
/*   Updated: 2022/12/27 19:41:32 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CONST_REVERSE_ITERATOR
#define VECTOR_CONST_REVERSE_ITERATOR

#include "vector_iterator.hpp"
#include "vector.hpp"

namespace ft
{
	template<typename T>
	class vectorconstreverseiterator
	{
		private:
			T*	_ptr;

		public:
			typedef	const		T				value_type;
			typedef				value_type&		reference;
			typedef	const		value_type&		const_reference;
			typedef				value_type*		pointer;
			typedef	const		value_type*		const_pointer;
			typedef	typename	std::ptrdiff_t	difference_type;

			vectorconstreverseiterator() {};
			vectorconstreverseiterator(pointer ptr) : _ptr(ptr) {};
			vectorconstreverseiterator(vectorconstreverseiterator const &other) { *this = other; };

			virtual ~vectorconstreverseiterator() {};

			bool	operator==(const vectorconstreverseiterator& other) const {
				return (_ptr == other._ptr);
			};
			bool	operator!=(const vectorconstreverseiterator& other) const {
				return (_ptr != other._ptr);
			};
			bool	operator<(const vectorconstreverseiterator& other) const {
				return (_ptr < other._ptr);
			};
			bool	operator>(const vectorconstreverseiterator& other) const {
				return (_ptr > other._ptr);
			};
			bool	operator<=(const vectorconstreverseiterator& other) const {
				return (_ptr <= other._ptr);
			};
			bool	operator>=(const vectorconstreverseiterator& other) const {
				return (_ptr >= other._ptr);
			};

			void	operator+=(difference_type n) {
				_ptr -= n;
			};
			void	operator-=(difference_type n) {
				_ptr += n;
			};
			vectorconstreverseiterator operator+(difference_type other) {
				return(vectorconstreverseiterator(_ptr - other));
			};
			vectorconstreverseiterator operator-(difference_type other) {
				return(vectorconstreverseiterator(_ptr + other));
			};
			difference_type operator+(vectorconstreverseiterator other) {
				return (_ptr - other._ptr);
			};
			difference_type operator-(vectorconstreverseiterator other) {
				return (_ptr + other._ptr);
			};

			const_reference	operator*() const {
				return (*_ptr);
			};
			pointer	operator->() const {
				return (_ptr);
			};
			const_reference	operator[](difference_type n) const {
				return (*(_ptr + n));
			};
	};
}

#endif
