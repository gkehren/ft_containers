/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reverse_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:33:03 by gkehren           #+#    #+#             */
/*   Updated: 2023/01/03 02:24:34 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_REVERSE_ITERATOR
#define VECTOR_REVERSE_ITERATOR

#include "vector_iterator.hpp"
#include "vector.hpp"

namespace ft
{
	template<typename T>
	class vectorreverseiterator
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

			vectorreverseiterator() {};
			vectorreverseiterator(pointer ptr) : _ptr(ptr) {};
			vectorreverseiterator(vectoriterator<value_type> const &other) { _ptr = other.operator->(); };
			vectorreverseiterator(vectorreverseiterator const &other) { *this = other; };

			virtual ~vectorreverseiterator() {};

			vectorreverseiterator	operator++() {
				_ptr--;
				return(*this);
			};
			vectorreverseiterator	operator++(int) {
				_ptr--;
				return (vectorreverseiterator(_ptr + 1));
			};
			vectorreverseiterator	operator--() {
				_ptr++;
				return (*this);
			};
			vectorreverseiterator	operator--(int) {
				_ptr++;
				return (vectorreverseiterator(_ptr - 1));
			};

			bool	operator==(const vectorreverseiterator& other) const {
				return (_ptr == other._ptr);
			};
			bool	operator!=(const vectorreverseiterator& other) const {
				return (_ptr != other._ptr);
			};

			reference operator*() {
				return (*_ptr);
			};
			const_reference operator*() const {
				return (*_ptr);
			};
			pointer operator->() {
				return (_ptr);
			};
			const_pointer operator->() const {
				return (_ptr);
			};
			reference operator[](difference_type n) {
				return (*(_ptr + n));
			};
			const_reference operator[](difference_type n) const {
				return (*(_ptr + n));
			};

			vectorreverseiterator operator+(difference_type n) {
				return (vectorreverseiterator(_ptr - n));
			};

			vectorreverseiterator operator-(difference_type n) {
				return (vectorreverseiterator(_ptr + n));
			};

			vectorreverseiterator& operator+=(difference_type n) {
				_ptr -= n;
				return (*this);
			};
			vectorreverseiterator& operator-=(difference_type n) {
				_ptr += n;
				return (*this);
			};
			difference_type operator+(vectorreverseiterator other) {
				return (_ptr - other._ptr);
			};
			difference_type operator-(vectorreverseiterator other) {
				return (_ptr + other._ptr);
			};

			bool	operator<(const vectorreverseiterator& other) const {
				return (_ptr < other._ptr);
			};
			bool	operator>(const vectorreverseiterator& other) const {
				return (_ptr > other._ptr);
			};
			bool	operator<=(const vectorreverseiterator& other) const {
				return (_ptr <= other._ptr);
			};
			bool	operator>=(const vectorreverseiterator& other) const {
				return (_ptr >= other._ptr);
			};
	};
}

#endif
