/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:09:39 by gkehren           #+#    #+#             */
/*   Updated: 2022/12/30 19:45:31 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR
#define VECTOR_ITERATOR

#include <cstddef>

namespace ft
{
	template<typename T>
	class vectoriterator
	{
		private:
			T*	_ptr;

		public:
			typedef	T			value_type;
			typedef	value_type&	reference;
			typedef	const		value_type&	const_reference;
			typedef	value_type*	pointer;
			typedef	const		value_type*	const_pointer;
			typedef	typename	std::ptrdiff_t	difference_type;

			vectoriterator() {};
			vectoriterator(pointer ptr) : _ptr(ptr) {};
			vectoriterator(vectoriterator const &other) { *this = other; };

			virtual ~vectoriterator() {};

			vectoriterator	operator++(int) {
				_ptr++;
				return(*this);
			};
			vectoriterator	operator++() {
				vectoriterator tmp(*this);
				operator++();
				return (tmp);
			};
			vectoriterator	operator--(int) {
				_ptr--;
				return (*this);
			};
			vectoriterator	operator--() {
				vectoriterator tmp(*this);
				operator--();
				return (tmp);
			};

			bool	operator==(const vectoriterator& other) const {
				return (_ptr == other._ptr);
			};
			bool	operator!=(const vectoriterator& other) const {
				return (_ptr != other._ptr);
			};

			reference	operator*() const {
				return (*_ptr);
			};
			pointer operator->() const {
				return (_ptr);
			};
			reference	operator[](difference_type n) const {
				return (*(_ptr + n));
			};

			vectoriterator& operator+=(difference_type n) {
				_ptr += n;
				return (*this);
			};
			vectoriterator& operator-=(difference_type n) {
				_ptr -= n;
				return (*this);
			};
			vectoriterator operator+(difference_type other) {
				return(vectoriterator(_ptr + other));
			};
			vectoriterator operator-(difference_type other) {
				return(vectoriterator(_ptr - other));
			};
			difference_type operator+(vectoriterator other) {
				return (_ptr + other._ptr);
			};
			difference_type operator-(vectoriterator other) {
				return (_ptr - other._ptr);
			};

			bool	operator<(const vectoriterator& other) const {
				return (_ptr < other._ptr);
			};
			bool	operator>(const vectoriterator& other) const {
				return (_ptr > other._ptr);
			};
			bool	operator<=(const vectoriterator& other) const {
				return (_ptr <= other._ptr);
			};
			bool	operator>=(const vectoriterator& other) const {
				return (_ptr >= other._ptr);
			};
	};
}

#endif

