/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:16:10 by gkehren           #+#    #+#             */
/*   Updated: 2023/01/09 14:16:51 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <cstddef>
#include <sstream>
#include <limits>
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
			typedef	T&										reference;
			typedef	const T&								const_reference;
			typedef	T*										pointer;
			typedef	const T*								const_pointer;
			//typedef	iterator
			//typedef	const_iterator
			//typedef	reverse_iterator
			//typedef	const_reverse_iterator
			typedef	ptrdiff_t								difference_type;
			typedef	size_t									size_type;

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

		public:
	};
}

#endif
