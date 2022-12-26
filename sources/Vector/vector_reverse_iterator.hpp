/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reverse_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:33:03 by gkehren           #+#    #+#             */
/*   Updated: 2022/12/26 16:22:54 by gkehren          ###   ########.fr       */
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
			vectorreverseiterator() {};
			vectorreverseiterator(T* ptr) : _ptr(ptr) {};
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

			T& operator*() const {
				return (*_ptr);
			};
			T* operator->() const {
				return (_ptr);
			};
			T& operator[](std::ptrdiff_t n) const {
				return (*(_ptr + n));
			};

			vectorreverseiterator& operator+=(std::ptrdiff_t n) {
				_ptr -= n;
				return (*this);
			};
			vectorreverseiterator& operator-=(std::ptrdiff_t n) {
				_ptr += n;
				return (*this);
			};
			std::ptrdiff_t operator+(vectorreverseiterator other) {
				return (_ptr - other._ptr);
			};
			std::ptrdiff_t operator-(vectorreverseiterator other) {
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
