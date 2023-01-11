/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:53:43 by gkehren           #+#    #+#             */
/*   Updated: 2023/01/11 15:44:54 by gkehren          ###   ########.fr       */
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
	template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set
	{
		public:
			typedef	T												key_type;
			typedef	Compare											key_compare;
			typedef	Alloc											allocator_type;
		private:
			typedef	ft::rbTree<T,Compare,Alloc>						tree_type;
			tree_type	_tree;

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

			explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
			_tree(comp, alloc) {};

			template <typename InputIterator>
			set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
			_tree(comp, alloc) { this->insert(first, last); };

			set(const set& other) : _tree(other._tree) {};
			~set() {};

			set&	operator=(const set& rhs)
			{
				if (this != &rhs)
					this->_tree = rhs._tree;
				return (*this);
			};

			allocator_type	get_allocator() const { return(_tree.get_allocator()); };

			iterator begin() { return(_tree.begin()); };
			const_iterator	begin() const { return(_tree.begin()); };
			iterator end() { return(_tree.end()); };
			const_iterator	end() const { return(_tree.end()); };
			reverse_iterator rbegin() { return(_tree.rbegin()); };
			const_reverse_iterator	rbegin() const { return(_tree.rbegin()); };
			reverse_iterator rend() { return(_tree.rend()); };
			const_reverse_iterator	rend() const { return(_tree.rend()); };

			bool	empty() const { return(_tree.empty()); };

			size_type	size() const { return(_tree.size()); };

			size_type	max_size() const
			{
				return ((std::numeric_limits<size_type>::max() / sizeof(ft::RBnode<key_type>)) / 2);
			};

			void	clear() { _tree.clear(); };

			ft::pair<iterator,bool>	insert(const value_type& val) { return(_tree.insert(val)); };

			iterator	insert(iterator hint, const value_type& val)
			{
				(void)hint;
				return (_tree.insert(val).first);
			};

			template <class InputIterator>
			void	insert(InputIterator first, InputIterator last) { _tree.insert(first, last); };

			void	erase(iterator pos) { _tree.erase(*pos); };

			void	erase(iterator first, iterator last)
			{
				while (first != last)
					_tree.erase(*(first++));
			};

			size_type	erase(const Key& key) { return(_tree.erase(key)); };

			void	swap(set& other) { std::swap(_tree, other._tree); };

			size_type	count(const Key& key) const { return(_tree.count(key)); };

			iterator	find(const Key& key) { return(_tree.find(key)); };

			const_iterator	find(const Key& key) const { return(_tree.find(key)); };

			ft::pair<iterator,iterator>	equal_range(const Key& key) { return(_tree.equal_range(key)); };

			ft::pair<const_iterator,const_iterator>	equal_range(const Key& key) const { return(_tree.equal_range(key)); };

			iterator	lower_bound(const Key& key) { return(_tree.lower_bound(key)); };

			const_iterator	lower_bound(const Key& key) const { return(_tree.lower_bound(key)); };

			iterator	upper_bound(const Key& key) { return(_tree.upper_bound(key)); };

			const_iterator	upper_bound(const Key& key) const { return(_tree.upper_bound(key)); };

			key_compare	key_comp() const { return(key_compare()); };

			value_compare	value_comp() const { return(_tree.value_comp()); };

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
