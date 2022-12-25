/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:04:29 by gkehren           #+#    #+#             */
/*   Updated: 2022/12/25 15:11:44 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <iterator>
#include <stdexcept>
#include "Vector_Iterator.hpp"

namespace ft
{
	template<typename T>
	class Vector
	{
		private:
			T		*_data; // pointer to memory
			size_t	_size; // number of elements
			size_t	_capacity; // current maximal number of elements

		public:
			Vector();
			Vector(size_t size);
			Vector(const Vector &other);
			~Vector();

			T		&operator[](size_t index);
			const T	&operator[](size_t index) const;

			void	push_back(const T &value);
			void	pop_back();

			size_t	size() const;
			size_t	capacity() const;
			bool	empty() const;

			typedef typename ft::VectorIterator<T> iterator;
			iterator	begin() { return (iterator(_data)); };
			iterator	end() { return (iterator(_data + _size)); };
	};

	/*======|=============|======*/
	/*---===| Constructor |===---*/
	/*======|=============|======*/
	template<typename T>
	Vector<T>::Vector() : _data(NULL), _size(0), _capacity(0)
	{}

	template<typename T>
	Vector<T>::Vector(size_t size) : _size(size), _capacity(size)
	{
		this->_data = new T[size];
	}

	template<typename T>
	Vector<T>::Vector(const Vector &other) : _size(other._size), _capacity(other._capacity)
	{
		this->_data = new T[_capacity];

		for (int i = 0; i < this->_size; i++)
			this->_data[i] = other._data[i];
	}

	template<typename T>
	Vector<T>::~Vector()
	{
		delete[] _data;
	}

	/*======|==========|======*/
	/*---===| Accessor |===---*/
	/*======|==========|======*/
	template<typename T>
	size_t	Vector<T>::size() const
	{
		return (this->_size);
	}

	template<typename T>
	size_t	Vector<T>::capacity() const
	{
		return (this->_capacity);
	}

	template<typename T>
	bool	Vector<T>::empty() const
	{
		return (this->_size == 0);
	}

	/*======|================|======*/
	/*---===| Element access |===---*/
	/*======|================|======*/
	template<typename T>
	T	&Vector<T>::operator[](size_t index)
	{
		if (index > this->_size)
			throw std::out_of_range("Index out of range");
		return (this->_data[index]);
	}

	template<typename T>
	const T	&Vector<T>::operator[](size_t index) const
	{
		if (index > this->_size)
			throw std::out_of_range("Index out of range");
		return (this->_data[index]);
	}

	/*======|===========|======*/
	/*---===| Modifiers |===---*/
	/*======|===========|======*/
	template<typename T>
	void	Vector<T>::push_back(const T &value)
	{
		if (this->_size == this->_capacity)
		{
			size_t new_capacity = (this->_capacity == 0) ? 1 : this->_capacity * 2;
			T	*new_data = new T[new_capacity];
			for (size_t i = 0; i < this->_size; i++)
				new_data[i] = this->_data[i];
			delete[] this->_data;
			this->_data = new_data;
			this->_capacity = new_capacity;
		}
		this->_data[this->_size] = value;
		this->_size++;
	}

	template<typename T>
	void	Vector<T>::pop_back()
	{
		if (this->_size > 0)
			this->_size--;
	}
}


#endif
