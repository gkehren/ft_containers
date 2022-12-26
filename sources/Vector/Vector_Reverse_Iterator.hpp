/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector_Reverse_Iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:33:03 by gkehren           #+#    #+#             */
/*   Updated: 2022/12/26 01:12:49 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_REVERSE_ITERATOR
#define VECTOR_REVERSE_ITERATOR

#include "Vector_Iterator.hpp"
#include "Vector.hpp"

namespace ft
{
	template<typename T>
	class VectorReverseIterator
	{
		private:
			T*	_ptr;

		public:
			VectorReverseIterator() {};
			VectorReverseIterator(T* ptr) : _ptr(ptr) {};
			VectorReverseIterator(VectorReverseIterator const &other) { *this = other; };

			virtual ~VectorReverseIterator() {};

			VectorReverseIterator	operator++() {
				_ptr--;
				return(*this);
			};
			VectorReverseIterator	operator++(int) {
				_ptr--;
				return (VectorReverseIterator(_ptr + 1));
			};
			VectorReverseIterator	operator--() {
				_ptr++;
				return (*this);
			};
			VectorReverseIterator	operator--(int) {
				_ptr++;
				return (VectorReverseIterator(_ptr - 1));
			};

			bool	operator==(const VectorReverseIterator& other) const {
				return (_ptr == other._ptr);
			};
			bool	operator!=(const VectorReverseIterator& other) const {
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

			VectorReverseIterator& operator+=(std::ptrdiff_t n) {
				_ptr -= n;
				return (*this);
			};
			VectorReverseIterator& operator-=(std::ptrdiff_t n) {
				_ptr += n;
				return (*this);
			};
			std::ptrdiff_t operator+(VectorReverseIterator other) {
				return (_ptr - other._ptr);
			};
			std::ptrdiff_t operator-(VectorReverseIterator other) {
				return (_ptr + other._ptr);
			};

			bool	operator<(const VectorReverseIterator& other) const {
				return (_ptr < other._ptr);
			};
			bool	operator>(const VectorReverseIterator& other) const {
				return (_ptr > other._ptr);
			};
			bool	operator<=(const VectorReverseIterator& other) const {
				return (_ptr <= other._ptr);
			};
			bool	operator>=(const VectorReverseIterator& other) const {
				return (_ptr >= other._ptr);
			};
	};
}

#endif
