/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector_Iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:09:39 by gkehren           #+#    #+#             */
/*   Updated: 2022/12/26 00:57:09 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR
#define VECTOR_ITERATOR

namespace ft
{
	template<typename T>
	class VectorIterator
	{
		private:
			T*	_ptr;

		public:
			VectorIterator() {};
			VectorIterator(T* ptr) : _ptr(ptr) {};
			VectorIterator(VectorIterator const &other) { *this = other; };

			virtual ~VectorIterator() {};

			VectorIterator	operator++(int) {
				_ptr++;
				return(*this);
			};
			VectorIterator	operator++() {
				VectorIterator tmp(*this);
				operator++();
				return (tmp);
			};
			VectorIterator	operator--(int) {
				_ptr--;
				return (*this);
			};
			VectorIterator	operator--() {
				VectorIterator tmp(*this);
				operator--();
				return (tmp);
			};

			bool	operator==(const VectorIterator& other) const {
				return (_ptr == other._ptr);
			};
			bool	operator!=(const VectorIterator& other) const {
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

			VectorIterator& operator+=(std::ptrdiff_t n) {
				_ptr += n;
				return (*this);
			};
			VectorIterator& operator-=(std::ptrdiff_t n) {
				_ptr -= n;
				return (*this);
			};
			VectorIterator operator+(std::ptrdiff_t other) {
				return(VectorIterator(_ptr + other));
			};
			VectorIterator operator-(std::ptrdiff_t other) {
				return(VectorIterator(_ptr - other));
			};
			std::ptrdiff_t operator+(VectorIterator other) {
				return (_ptr + other._ptr);
			};
			std::ptrdiff_t operator-(VectorIterator other) {
				return (_ptr - other._ptr);
			};

			bool	operator<(const VectorIterator& other) const {
				return (_ptr < other._ptr);
			};
			bool	operator>(const VectorIterator& other) const {
				return (_ptr > other._ptr);
			};
			bool	operator<=(const VectorIterator& other) const {
				return (_ptr <= other._ptr);
			};
			bool	operator>=(const VectorIterator& other) const {
				return (_ptr >= other._ptr);
			};
	};
}

#endif

