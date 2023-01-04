/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_const_iterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:09:39 by gkehren           #+#    #+#             */
/*   Updated: 2023/01/04 01:16:20 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CONST_ITERATOR
#define VECTOR_CONST_ITERATOR

#include <cstddef>
#include "vector_iterator.hpp"

namespace ft
{
	template<typename T>
	class vectorconstiterator
	{
		public:
			typedef	const		T				value_type;
			typedef				value_type&		reference;
			typedef	const		value_type&		const_reference;
			typedef				value_type*		pointer;
			typedef	typename	std::ptrdiff_t	difference_type;

			vectorconstiterator() {};
			vectorconstiterator(pointer ptr) { _ptr = ptr; };
			vectorconstiterator(vectoriterator<T> const &other) { _ptr = other.operator->(); };
			vectorconstiterator(vectorconstiterator const &other) { *this = other; };

			virtual ~vectorconstiterator() {};

			vectorconstiterator &operator=(vectorconstiterator const &other) {
				_ptr = other.operator->();
				return (*this);
			};

			vectorconstiterator	operator++() {
				_ptr++;
				return(*this);
			};
			vectorconstiterator	operator++(int) {
				vectorconstiterator tmp(*this);
				operator++();
				return (tmp);
			};
			vectorconstiterator	operator--() {
				_ptr--;
				return (*this);
			};
			vectorconstiterator	operator--(int) {
				vectorconstiterator tmp(*this);
				operator--();
				return (tmp);
			};

			bool	operator==(const vectorconstiterator& other) const {
				return (_ptr == other._ptr);
			};
			bool	operator!=(const vectorconstiterator& other) const {
				return (_ptr != other._ptr);
			};
			bool	operator<(const vectorconstiterator& other) const {
				return (_ptr < other._ptr);
			};
			bool	operator>(const vectorconstiterator& other) const {
				return (_ptr > other._ptr);
			};
			bool	operator<=(const vectorconstiterator& other) const {
				return (_ptr <= other._ptr);
			};
			bool	operator>=(const vectorconstiterator& other) const {
				return (_ptr >= other._ptr);
			};

			void	operator+=(difference_type n) {
				_ptr += n;
			};
			void	operator-=(difference_type n) {
				_ptr -= n;
			};
			vectorconstiterator operator+(difference_type other) {
				return(vectorconstiterator(_ptr + other));
			};
			vectorconstiterator operator-(difference_type other) {
				return(vectorconstiterator(_ptr - other));
			};
			difference_type operator+(vectorconstiterator other) {
				return (_ptr + other._ptr);
			};
			difference_type operator-(vectorconstiterator other) {
				return (_ptr - other._ptr);
			};

			const_reference	operator*() const {
				return (*_ptr);
			};
			pointer	operator->() {
				return (_ptr);
			};
			pointer	operator->() const {
				return (_ptr);
			};
			const_reference	operator[](difference_type n) const {
				return (*(_ptr + n));
			};

			static const bool input_iterator = true;

		private:
			pointer	_ptr;
	};
}

#endif

