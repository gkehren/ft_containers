/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:53:43 by gkehren           #+#    #+#             */
/*   Updated: 2023/01/14 23:08:50 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include "../utils/red_black_tree.hpp"
#include "../utils/tree_iterator.hpp"
#include "../utils/iterator.hpp"
#include "../utils/utils.hpp"
#include <functional>
#include <memory>

namespace ft
{
	// Sets are containers that store unique elements following a specific order.
	template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set
	{
		public:
			typedef	T												key_type;
			typedef	Compare											key_compare;
			typedef	Alloc											allocator_type;
		private:
			typedef	ft::rbTree<T,Compare,Alloc>						tree_type;
			tree_type	_set;

		public:
			typedef typename tree_type::value_type					value_type;
			typedef typename tree_type::value_compare				value_compare;
			typedef typename tree_type::reference					reference;
			typedef typename tree_type::const_reference				const_reference;
			typedef typename tree_type::pointer						pointer;
			typedef typename tree_type::const_pointer				const_pointer;
			typedef typename tree_type::size_type					size_type;
			typedef typename tree_type::difference_type				difference_type;
			typedef typename tree_type::iterator					iterator;
			typedef typename tree_type::const_iterator				const_iterator;
			typedef typename tree_type::reverse_iterator			reverse_iterator;
			typedef typename tree_type::const_reverse_iterator		const_reverse_iterator;
			typedef value_type										Key;

			/*-----|-------------|-----*/
			/*-----| Constructor |-----*/
			/*-----|-------------|-----*/
			explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
			_set(comp, alloc) {};

			template <typename InputIterator>
			set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
			_set(comp, alloc) { this->insert(first, last); };

			set(const set& other) : _set(other._set) {};
			~set() {};

			set&	operator=(const set& rhs)
			{
				if (this != &rhs)
					this->_set = rhs._set;
				return (*this);
			};

			/*-----|-----------|-----*/
			/*-----| Iterators |-----*/
			/*-----|-----------|-----*/

			// Return iterator to beginning
			iterator				begin() { return(_set.begin()); };
			const_iterator			begin() const { return(_set.begin()); };
			// Return iterator to end
			iterator				end() { return(_set.end()); };
			const_iterator			end() const { return(_set.end()); };
			// Return reverse iterator to reverse beginning
			reverse_iterator		rbegin() { return(_set.rbegin()); };
			const_reverse_iterator	rbegin() const { return(_set.rbegin()); };
			// Return reverse iterator to reverse end
			reverse_iterator		rend() { return(_set.rend()); };
			const_reverse_iterator	rend() const { return(_set.rend()); };

			/*-----|----------|-----*/
			/*-----| Capacity |-----*/
			/*-----|----------|-----*/

			// Returns whether the set container is empty (i.e. whether its size is 0).
			bool	empty() const { return(_set.empty()); };

			// Returns the number of elements in the set container.
			size_type	size() const { return(_set.size()); };

			// Returns the maximum number of elements that the set container can hold.
			size_type	max_size() const
			{
				return ((std::numeric_limits<size_type>::max() / sizeof(ft::RBnode<key_type>)) / 2);
			};

			/*-----|-----------|-----*/
			/*-----| Modifiers |-----*/
			/*-----|-----------|-----*/

			// Extends the container by inserting new elements,
			// effectively increasing the container size by the number of elements inserted.
			ft::pair<iterator,bool>	insert(const value_type& val) { return(_set.insert(val)); };

			iterator	insert(iterator hint, const value_type& val)
			{
				(void)hint;
				return (_set.insert(val).first);
			};

			template <class InputIterator>
			void	insert(InputIterator first, InputIterator last) { _set.insert(first, last); };

			// Removes from the set container either a single element or a range of elements ([first,last)).
			void	erase(iterator pos) { _set.erase(*pos); };

			void	erase(iterator first, iterator last)
			{
				while (first != last)
					_set.erase(*(first++));
			};

			size_type	erase(const Key& key) { return(_set.erase(key)); };

			// Exchanges the content of the container by the content of x, which is another set of the same type. Sizes may differ.
			void	swap(set& other) { std::swap(_set, other._set); };

			// Removes all elements from the set container (which are destroyed), leaving the container with a size of 0.
			void	clear() { _set.clear(); };

			/*-----|-----------|-----*/
			/*-----| Observers |-----*/
			/*-----|-----------|-----*/

			// Returns a copy of the comparison object used by the container.
			key_compare	key_comp() const { return(key_compare()); };

			// Returns a copy of the comparison object used by the container.
			value_compare	value_comp() const { return(_set.value_comp()); };

			/*-----|------------|-----*/
			/*-----| Operations |-----*/
			/*-----|------------|-----*/

			// Searches the container for an element equivalent to val and returns an iterator to it if found,
			// otherwise it returns an iterator to set::end.
			iterator	find(const Key& key) { return(_set.find(key)); };
			const_iterator	find(const Key& key) const { return(_set.find(key)); };

			// Searches the container for elements equivalent to val and returns the number of matches.
			size_type	count(const Key& key) const { return(_set.count(key)); };

			// Returns an iterator pointing to the first element in the container which is not considered to go before val (i.e., either it is equivalent or goes after).
			iterator	lower_bound(const Key& key) { return(_set.lower_bound(key)); };
			const_iterator	lower_bound(const Key& key) const { return(_set.lower_bound(key)); };

			// Returns an iterator pointing to the first element in the container which is considered to go after val.
			iterator	upper_bound(const Key& key) { return(_set.upper_bound(key)); };
			const_iterator	upper_bound(const Key& key) const { return(_set.upper_bound(key)); };

			// Returns the bounds of a range that includes all the elements in the container that are equivalent to val.
			ft::pair<const_iterator,const_iterator>	equal_range(const Key& key) const { return(_set.equal_range(key)); };
			ft::pair<iterator,iterator>	equal_range(const Key& key) { return(_set.equal_range(key)); };

			// Returns a copy of the allocator object associated with the set.
			allocator_type	get_allocator() const { return(_set.get_allocator()); };
	};

template< class Key, class Compare, class Alloc >
void swap( ft::set<Key,Compare,Alloc>& lhs, ft::set<Key,Compare,Alloc>& rhs )
{
	lhs.swap(rhs);
};

template< class Key, class Compare, class Alloc >
bool operator==( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
{
	if(lhs.size() != rhs.size())
		return (false);
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
};

template< class Key, class Compare, class Alloc >
bool operator!=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
{
	return (!(lhs == rhs));
};


template< class Key, class Compare, class Alloc >
bool operator<( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
};


template< class Key, class Compare, class Alloc >
bool operator<=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
{
	return !(rhs < lhs);
};

template< class Key, class Compare, class Alloc >
bool operator>( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
{
	return (rhs < lhs);
};

template< class Key, class Compare, class Alloc >
bool operator>=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
{
	return !(lhs < rhs);
};


};


#endif
