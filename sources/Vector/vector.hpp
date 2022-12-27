/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:04:29 by gkehren           #+#    #+#             */
/*   Updated: 2022/12/27 16:54:00 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <cstddef>
#include <sstream>
#include "vector_iterator.hpp"
#include "vector_reverse_iterator.hpp"

namespace ft
{
	template< typename T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T value_type;
			typedef Allocator allocator_type;
			typedef typename std::size_t size_type;
			typedef typename Allocator::reference reference;
			typedef typename Allocator::const_reference const_reference;

			explicit vector(const Allocator& alloc = Allocator()) : _alloc(alloc), _data(0), _size(0), _capacity(0) {};

			vector(vector &other) : _alloc(allocator_type()), _size(0), _capacity(0) { *this = other; };

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _data(0), _size(0), _capacity(0)
			{
				this->reserve(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_data + i, val);
				_size = n;
				_capacity = n;
			};

			virtual ~vector()
			{
				this->clear();
				if (_capacity > 0)
				{
					_alloc.deallocate(_data, _capacity);
					_capacity = 0;
				}
			};

			typedef typename ft::vectoriterator<T> iterator;
			iterator	begin() { return (iterator(_data)); };
			iterator	end() { return (iterator(_data + _size)); };

			typedef typename ft::vectorreverseiterator<T> reverse_iterator;
			reverse_iterator	rbegin() { return(reverse_iterator(_data + _size - 1)); };
			reverse_iterator	rend() { return(reverse_iterator(_data - 1)); };

			reference		operator[](size_type n) { return (_data[n]); };
			const_reference	operator[](size_type n) const { return (_data[n]); };

			void	reserve(size_type n)
			{
				value_type	*new_arr;

				if (n <= _capacity)
					return ;
				new_arr = _alloc.allocate(n);
				for (size_t i = 0; i < _size; i++)
					_alloc.construct(new_arr + i, *(_data + i));
				_capacity = n;
				_data = new_arr;
			};

			void	clear()
			{
				if (_size > 0)
				{
					for (iterator it = this->begin(); it != this->end(); it++)
						_alloc.destroy(&(*it));
					_size = 0;
				}
			};

			size_type	size() const
			{
				return (_size);
			};

			reference	at(size_type n)
			{
				if (n >= _size)
					throw	_out_of_range(n);
				return (_data[n]);
			};

			reference	front()
			{
				return (_data[0]);
			};

			reference	back()
			{
				return (_data[_size - 1]);
			};

			void	push_back(const T& value)
			{
				if (_capacity == 0)
				{
					_data = _alloc.allocate(1);
					_capacity++;
				}
				if (_size == _capacity)
					_extend();
				_alloc.construct(_data + _size, value);
				_size++;
			};

			void	pop_back()
			{
				if (_size > 0)
				{
					_alloc.destroy(_data + (_size - 1));
					_size--;
				}
			};

		private:
			Allocator	_alloc;
			T			*_data; // pointer to memory
			size_t		_size; // number of elements
			size_t		_capacity; // current maximal number of elements

			// allocate to new_arr the double of _data and deallocate _data then new_arr becomes _data
			void	_extend()
			{
				if (_capacity == 0)
				{
					_data = _alloc.allocate(1);
					_capacity++;
				}
				else
				{
					T* new_arr = _alloc.allocate(_capacity * 2);
					for (size_t i = 0; i < _size; i++)
					{
						_alloc.construct(new_arr + i, *(_data + i));
						_alloc.destroy(_data + i);
					}
					_alloc.deallocate(_data, _capacity);
					_data = new_arr;
					_capacity *= 2;
				}
			};

			std::out_of_range	_out_of_range(size_type pos)
			{
				std::stringstream ss;

				ss << "vecotr::_M_range_check: __n (which is " << pos << ")" << " >= this->size() (whis is " << _size << ")";
				return (std::out_of_range(ss.str()));
			};
	};
}

#endif
