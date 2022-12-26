/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:09:39 by gkehren           #+#    #+#             */
/*   Updated: 2022/12/26 16:21:33 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR
#define VECTOR_ITERATOR

namespace ft
{
	template<typename T>
	class vectoriterator
	{
		private:
			T*	_ptr;

		public:
			vectoriterator() {};
			vectoriterator(T* ptr) : _ptr(ptr) {};
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

			T& operator*() const {
				return (*_ptr);
			};
			T* operator->() const {
				return (_ptr);
			};
			T& operator[](std::ptrdiff_t n) const {
				return (*(_ptr + n));
			};

			vectoriterator& operator+=(std::ptrdiff_t n) {
				_ptr += n;
				return (*this);
			};
			vectoriterator& operator-=(std::ptrdiff_t n) {
				_ptr -= n;
				return (*this);
			};
			vectoriterator operator+(std::ptrdiff_t other) {
				return(vectoriterator(_ptr + other));
			};
			vectoriterator operator-(std::ptrdiff_t other) {
				return(vectoriterator(_ptr - other));
			};
			std::ptrdiff_t operator+(vectoriterator other) {
				return (_ptr + other._ptr);
			};
			std::ptrdiff_t operator-(vectoriterator other) {
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

