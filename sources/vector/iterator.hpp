/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 01:16:15 by gkehren           #+#    #+#             */
/*   Updated: 2023/01/05 01:58:00 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft
{

	template <class Iter>
	struct iterator_traits {
		public:
			typedef typename Iter::value_type			value_type;
			typedef typename Iter::difference_type		difference_type;
			typedef typename Iter::pointer				pointer;
			typedef typename Iter::const_pointer		const_pointer;
			typedef typename Iter::reference			reference;
			typedef typename Iter::const_reference		const_reference;
			typedef typename Iter::iterator_category	iterator_category;
	};

	template <typename T>
	struct iterator_traits<T*>
	{
		public:
			typedef T									value_type;
			typedef T*									pointer;
			typedef const T*							const_pointer;
			typedef T&									reference;
			typedef const T&							const_reference;
			typedef ptrdiff_t							difference_type;
			typedef std::random_access_iterator_tag		iterator_category;
	};

	template <class T>
	class iterator
	{
		private:
			T value;

		public:
			typedef T															iterator_type;
			typedef typename iterator_traits<iterator_type>::value_type			value_type;
			typedef typename iterator_traits<iterator_type>::pointer			pointer;
			typedef typename iterator_traits<iterator_type>::const_pointer		const_pointer;
			typedef typename iterator_traits<iterator_type>::reference			reference;
			typedef typename iterator_traits<iterator_type>::const_reference	const_reference;
			typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
			typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;

			iterator(T value = NULL) : value(value) {};
			~iterator() {};

			T	base() const { return (value); };

			iterator	&operator=(const iterator &obj) {
				this->value = obj.value;
				return *this;
			}

			iterator	operator++(int)	{
				iterator tmp(*this);
				value++; return tmp;
			}
			iterator	operator--(int) {
				iterator tmp(*this);
				value--; return tmp;
			}
			iterator	&operator++() {
				value++;
				return *this;
			}
			iterator	&operator--() {
				value--;
				return *this;
			}

			int		operator-(iterator const &obj) const {
				return value - obj.value;
			}
			int		operator+(iterator const &obj) const {
				return value + obj.value;
			}
			iterator	operator-(int n) const {
				return iterator(this->value - n);
			}
			iterator	operator+(int n) const {
				return iterator(this->value + n);
			}
			iterator	&operator-=(int n) {
				this->value -= n;
				return (*this);
			}
			iterator	&operator+=(int n) {
				this->value += n;
				return (*this);
			}
			reference 	operator*() const {
				return *value;
			}
			pointer 	operator->() const {
				return &(*value);
			}
			reference	operator[](difference_type n) const {
				return (*(value + n));
			};

			bool	operator==(iterator const &obj) const	{ return value == obj.value; };
			bool	operator!=(iterator const &obj) const	{ return value != obj.value; };
			bool	operator<(iterator const &obj) const	{ return value < obj.value; };
			bool	operator>(iterator const &obj) const	{ return value > obj.value; };
			bool	operator<=(iterator const &obj) const	{ return value <= obj.value; };
			bool	operator>=(iterator const &obj) const	{ return value >= obj.value; };
	};

	template <class T>
	class reverse_iterator
	{
		private:
			T iterator;

		public:
			typedef	T												iterator_type;
			typedef	typename iterator_traits<T>::difference_type	difference_type;
			typedef	typename iterator_traits<T>::value_type			value_type;
			typedef	typename iterator_traits<T>::reference			reference;
			typedef	typename iterator_traits<T>::const_reference	const_reference;
			typedef	typename iterator_traits<T>::pointer			pointer;
			typedef	typename iterator_traits<T>::const_pointer		const_pointer;
			typedef	typename iterator_traits<T>::iterator_category	iterator_category;

			reverse_iterator(iterator_type value = NULL) : iterator(value) {};
			~reverse_iterator()	{};

			reverse_iterator	&operator=(const reverse_iterator &obj)	{
				iterator = obj.iterator;
				return *this;
			}

			iterator_type	base() const	{ return iterator; }
			reference		operator*()		{ return *iterator; }
			pointer			operator->()	{ return &(operator*()); }

			reverse_iterator	operator++(int)	{
				reverse_iterator tmp(*this);
				iterator++; return tmp;
			}
			reverse_iterator	operator--(int) {
				reverse_iterator tmp(*this);
				iterator--; return tmp;
			}
			reverse_iterator	&operator++() {
				iterator++;
				return *this;
			}
			reverse_iterator	&operator--() {
				iterator--;
				return *this;
			}

			int		operator-(reverse_iterator const &obj) const {
				return iterator - obj.iterator;
			}
			int		operator+(reverse_iterator const &obj) const {
				return iterator + obj.iterator;
			}
			reverse_iterator	operator-(int n) const {
				return reverse_iterator(this->iterator - n);
			}
			reverse_iterator	operator+(int n) const {
				return reverse_iterator(this->iterator + n);
			}
			reverse_iterator	&operator-=(int n) {
				this->iterator -= n;
				return (*this);
			}
			reverse_iterator	&operator+=(int n) {
				this->iterator += n;
				return (*this);
			}
			reference 	operator*() const {
				return *iterator;
			}
			pointer 	operator->() const {
				return &(*iterator);
			}
			reference	operator[](difference_type n) const {
				return (*(iterator + n));
			};

			bool	operator==(reverse_iterator const &obj) const	{ return iterator == obj.iterator; };
			bool	operator!=(reverse_iterator const &obj) const	{ return iterator != obj.iterator; };
			bool	operator<(reverse_iterator const &obj) const	{ return iterator < obj.iterator; };
			bool	operator>(reverse_iterator const &obj) const	{ return iterator > obj.iterator; };
			bool	operator<=(reverse_iterator const &obj) const	{ return iterator <= obj.iterator; };
			bool	operator>=(reverse_iterator const &obj) const	{ return iterator >= obj.iterator; };
	};
}

#endif
