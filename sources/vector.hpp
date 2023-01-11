/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:04:29 by gkehren           #+#    #+#             */
/*   Updated: 2023/01/11 15:42:57 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <cstddef>
#include <sstream>
#include <limits>
#include "utils/utils.hpp"
#include "utils/iterator.hpp"

namespace ft
{
	template< typename T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef				T							value_type;
			typedef				Allocator					allocator_type;
			typedef	typename	Allocator::reference		reference;
			typedef	typename	Allocator::const_reference	const_reference;
			typedef	typename	Allocator::pointer			pointer;
			typedef	typename	Allocator::const_pointer	const_pointer;
			typedef	typename	std::ptrdiff_t				difference_type;
			typedef	typename	std::size_t					size_type;

			typedef	ft::iterator<T*>						iterator;
			typedef	ft::iterator<const T*>					const_iterator;
			typedef	ft::reverse_iterator<iterator>			reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			/*-----|-------------|-----*/
			/*-----| Constructor |-----*/
			/*-----|-------------|-----*/

			// empty container constructor (default constructor)
			// Constructs an empty container, with no elements.
			explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _data(0), _size(0), _capacity(0) {};

			// fill constructor
			// Constructs a container with n elements, Each element is a copy of val.
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _data(0), _size(0), _capacity(0)
			{
				this->reserve(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_data + i, val);
				_size = n;
				_capacity = n;
			};

			// range constructor
			// Constructs a container with as many elements as the range [first, last),
			// with each element constructed form its correspongind element in that range, in the same order.
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type* = 0)
			: _alloc(alloc), _data(0), _size(0), _capacity(0)
			{
				while (first != last)
				{
					this->push_back(*first);
					first++;
				}
			};

			// copy constructor
			// Constructs a container with a copy of each of the elements in x, in the same order.
			vector(const vector& x) : _alloc(x._alloc), _size(0), _capacity(0) { this->operator=(x); };

			// vector destructor
			// Destroys the container object.
			~vector()
			{
				this->clear();
				if (_capacity > 0)
				{
					_alloc.deallocate(_data, _capacity);
					_capacity = 0;
				}
			};

			// Assign content
			// Assins new contents to the container, replacing its current contents, and modifying its size accordingly.
			vector&	operator=(const vector& x)
			{
				if (this == &x)
					return (*this);
				this->clear();
				for (const_iterator it = x.begin(); it != x.end(); it++)
					this->push_back(*it);
				return (*this);
			};

			/*-----|-----------|-----*/
			/*-----| Iterators |-----*/
			/*-----|-----------|-----*/

			// Return iterator to beginning
			iterator	begin() { return (iterator(_data)); };
			const_iterator	begin() const { return (const_iterator(_data)); };
			// Return iterator to end
			iterator	end() { return (iterator(_data + _size)); };
			const_iterator	end() const { return (const_iterator(_data + _size)); };
			// Return reverse iterator to reverse beginning
			reverse_iterator	rbegin() { return(reverse_iterator(_data + _size - 1)); };
			const_reverse_iterator	rbegin() const { return(const_reverse_iterator(_data + _size - 1)); };
			// Return reverse iterator to reverse end
			reverse_iterator	rend() { return(reverse_iterator(_data - 1)); };
			const_reverse_iterator	rend() const { return(const_reverse_iterator(_data - 1)); };

			/*-----|----------|-----*/
			/*-----| Capacity |-----*/
			/*-----|----------|-----*/

			// Returns the number of elements in the vector.
			size_type	size() const
			{
				return (_size);
			};

			// Returns the maximum number of elements that the vector can hold.
			size_type	max_size() const
			{
				return (std::numeric_limits<size_type>::max());
			};

			// Resizes the container so that it contains n elements.
			void	resize(size_type n, value_type val = value_type())
			{
				value_type*	new_data;

				new_data = _alloc.allocate(n);
				if (n > _size)
				{
					for (size_t i = 0; i < _size; i++)
						_alloc.construct(new_data + i, *(_data + i));
					for (size_t i = 0; i < n - _size; i++)
						_alloc.construct(new_data + _size + i, val);
				}
				else
				{
					for (size_t i = 0; i < n; i++)
						_alloc.construct(new_data + i, *(_data + i));
				}
				if ( _size)
				{
					_alloc.destroy(_data);
					_alloc.deallocate(_data, _capacity);
				}
				_capacity = n;
				_size = n;
				_data = new_data;
			};

			// Returns the size of the storage currently allocated for the vector, expressed in terms of elements.
			size_type	capacity() const
			{
				return (_capacity);
			}

			// Returns whether the vector is empty (i.e. whether its size is 0).
			bool	empty() const
			{
				return ((_size == 0));
			}

			// Requests that the vector capacity be at least enough to contain n elements.
			void	reserve(size_type n)
			{
				value_type	*new_data;

				if (n <= _capacity)
					return ;
				new_data = _alloc.allocate(n);
				for (size_t i = 0; i < _size; i++)
					_alloc.construct(new_data + i, *(_data + i));
				_capacity = n;
				_data = new_data;
			};

			/*-----|----------------|-----*/
			/*-----| Element access |-----*/
			/*-----|----------------|-----*/

			// Returns a reference to the element at position n in the vector container (don't check bounds).
			reference		operator[](size_type n) { return (_data[n]); };
			const_reference	operator[](size_type n) const { return (_data[n]); };

			// Returns a reference to the element at position n in the vector (check bounds).
			reference		at(size_type n)
			{
				if (n >= _size)
					throw _out_of_range(n);
				return (_data[n]);
			};
			const_reference	at(size_type n) const
			{
				if (n >= _size)
					throw _out_of_range(n);
				return (_data[n]);
			};

			// Returns a reference to the first element in the vector
			reference		front()
			{
				return (_data[0]);
			};
			const_reference	front() const
			{
				return (_data[0]);
			};

			// Returns a reference to the last element in the vector
			reference		back()
			{
				return (_data[_size - 1]);
			};
			const_reference	back() const
			{
				return (_data[_size - 1]);
			};

			/*-----|-----------|-----*/
			/*-----| Modifiers |-----*/
			/*-----|-----------|-----*/

			// Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
			template <class InputIterator>
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
			assign(InputIterator first, InputIterator last)
			{
				this->clear();
				for (iterator it = first; it != last; it++)
					this->push_back(*it);
			};
			void	assign(size_type n, const value_type& val)
			{
				this->clear();
				for (size_type i = 0; i < n; i++)
					this->push_back(val);
			};

			// Adds a new element at the end of the vectorm after its current last element.
			// The Content of val is copied to the new element.
			void	push_back(const value_type& val)
			{
				if (_capacity == 0)
				{
					_data = _alloc.allocate(1);
					_capacity++;
				}
				if (_size == _capacity)
					_extend();
				_alloc.construct(_data + _size, val);
				_size++;
			};

			// Removes the last element in the vectorm effectively reducing the container size by one.
			void	pop_back()
			{
				if (_size > 0)
				{
					_alloc.destroy(_data + (_size - 1));
					_size--;
				}
			};

			// The vector is extended by inserting new elements before the element at the specifed position
			// effectively increasing the container size by the number of elements inserted.
			iterator	insert(iterator position, const value_type& val)
			{
				iterator		it;
				difference_type	int_position = position - this->begin();

				if (this->capacity() == this->size())
					_extend();
				it = this->begin() + int_position;

				vector	tmp(it, this->end());
				for (size_t i = 0; i < tmp.size(); i++)
					this->pop_back();

				this->push_back(val);
				it = tmp.begin();
				for (size_t i = 0; i < tmp.size(); i++, it++)
					this->push_back(*it);
				return (this->begin() + int_position);
			};
			void	insert(iterator position, size_type n, const value_type& val)
			{
				difference_type	int_position = position - this->begin();

				while (_capacity - _size < n)
					_extend();

				vector	tmp(this->begin() + int_position, this->end());
				for (size_t i = 0; i < tmp.size(); i++)
					this->pop_back();
				while (n > 0)
				{
					this->push_back(val);
					n--;
				}
				for (iterator it = tmp.begin(); it != tmp.end(); it++)
					this->push_back(*it);
			};
			template <class InputIterator>
			void	insert(iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<InputIterator::input_iterator, InputIterator>::type = NULL)
			{
				size_t			n = 0;
				difference_type	int_position = position - this->begin();

				while (first != last)
				{
					first++;
					n++;
				}
				first -= n;

				while (_capacity - _size < n)
					_extend();

				vector	tmp(this->begin() + int_position, this->end());
				for (size_t i = 0; i < tmp.size(); i++)
					this->pop_back();
				while (first != last)
				{
					this->push_back(*first);
					first++;
				}
				for (iterator it = tmp.begin(); it != tmp.end(); it++)
					this->push_back(*it);
			};

			// Removes from the vector either a single element (position) or a range of elements ([first, last)).
			iterator	erase(iterator position)
			{
				vector	tmp(position + 1, this->end());

				for (size_t i = 0; i < tmp.size(); i++)
					this->pop_back();
				this->pop_back();
				for (iterator it = tmp.begin(); it != tmp.end(); it++)
					this->push_back(*it);
				return (position);
			};
			iterator	erase(iterator first, iterator last)
			{
				iterator	tmp(first);

				while (tmp != last)
				{
					erase(first);
					tmp++;
				}
				return (first);
			};

			// Exchanges the content of the container by the content of x, which is another vector object of the same type, Sizes may differ.
			void	swap(vector& x)
			{
				value_type*	tmp_data = x._data;
				size_t		tmp_size = x._size;
				size_t		tmp_capacity = x._capacity;

				x._data = _data;
				x._size = _size;
				x._capacity = _capacity;
				_data = tmp_data;
				_size = tmp_size;
				_capacity = tmp_capacity;
			};

			// Removes all elements from the vector (which are destroyed), leavin the container with a size of 0.
			void	clear()
			{
				if (_size > 0)
				{
					for (iterator it = this->begin(); it != this->end(); it++)
						_alloc.destroy(&(*it));
					_size = 0;
				}
			};

		private:
			Allocator	_alloc;
			T			*_data; // pointer to memory
			size_t		_size; // number of elements
			size_t		_capacity; // current maximal number of elements

			// allocate to new_data the double of _data and deallocate _data then new_data becomes _data
			void	_extend()
			{
				if (_capacity == 0)
				{
					_data = _alloc.allocate(1);
					_capacity++;
				}
				else
				{
					pointer new_data = _alloc.allocate(_capacity * 2);
					for (size_t i = 0; i < _size; i++)
					{
						_alloc.construct(new_data + i, *(_data + i));
						_alloc.destroy(_data + i);
					}
					_alloc.deallocate(_data, _capacity);
					_data = new_data;
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

/*-----|-------------------------------|-----*/
/*-----| Non-member function overloads |-----*/
/*-----|-------------------------------|-----*/

// Relational operators for vector
// Performs the appropriate comparison operation between the vector containers lhs and rhs.
template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	typename ft::vector<T>::const_iterator	it_lhs = lhs.begin();
	typename ft::vector<T>::const_iterator	it_rhs = rhs.begin();

	if (lhs.size() != rhs.size())
		return (false);
	while (it_lhs != lhs.end() && it_rhs != rhs.end() && *it_lhs == *it_rhs)
	{
		it_lhs++;
		it_rhs++;
	}
	return (it_lhs == lhs.end() && it_rhs == rhs.end());
};

template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!(lhs == rhs));
};

template <class T, class Alloc>
bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
};

template <class T, class Alloc>
bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!(rhs < lhs));
};

template <class T, class Alloc>
bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (rhs < lhs);
};

template <class T, class Alloc>
bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!(lhs < rhs));
};

// The content fo container x are exchanged with those of y,
// Both container objects must be of the same type (same template parameters), although sizes may differ
template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
{
	x.swap(y);
};

}

#endif
