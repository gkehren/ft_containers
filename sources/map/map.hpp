/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:16:10 by gkehren           #+#    #+#             */
/*   Updated: 2023/01/10 00:52:51 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <cstddef>
#include <sstream>
#include <limits>
#include "../utils/red_black_tree.hpp"
#include "../utils/utils.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			typedef	Key										key_type;
			typedef	T										mapped_type;
			typedef	ft::pair<const key_type, mapped_type>	value_type;
			typedef	Compare									key_compare;
			typedef	Alloc									allocator_type;

			class value_compare
			{
				friend class map;

				protected:
					key_compare comp;
					value_compare(Compare c) : comp(c) {}

				public:
					typedef	bool		result_type;
					typedef	value_type	first_argument_type;
					typedef	value_type	second_argument_type;

					bool	operator()(const value_type& x, const value_type& y) const
					{
						return (comp(x.first, y.first));
					}
			};

		private:
			typedef ft::rbTree<value_type,value_compare,allocator_type>	tree_type;

		public:
			typedef typename	allocator_type::reference				reference;
			typedef typename	allocator_type::const_reference		const_reference;
			typedef typename	allocator_type::pointer				pointer;
			typedef typename	allocator_type::const_pointer			const_pointer;
			typedef typename	allocator_type::size_type				size_type;
			typedef typename	allocator_type::difference_type		difference_type;
			typedef typename	tree_type::iterator					iterator;
			typedef typename	tree_type::const_iterator			const_iterator;
			typedef typename	tree_type::reverse_iterator			reverse_iterator;
			typedef typename	tree_type::const_reverse_iterator	const_reverse_iterator;

	};
}

#endif
