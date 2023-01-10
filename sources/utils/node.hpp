/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:09:28 by gkehren           #+#    #+#             */
/*   Updated: 2023/01/09 22:19:23 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

namespace ft
{
	enum node_color {black = true, red = false};

	template <typename T>
	struct RBnode
	{
		typedef T							value_type;
		typedef RBnode<value_type>*			node_ptr;
		typedef const RBnode<value_type>*	const_node_ptr;

		value_type	_value;
		node_ptr	_parent;
		node_ptr	_left;
		node_ptr	_right;
		node_color	_color;

		RBnode() : _value(), _parent(), _left(), _right(), _color(black) {};
		RBnode(const RBnode& other) : _value(other._value), _parent(other._parent), _left(other._left), _right(other._right), _color(other._color) {};
		~RBnode() {};

		RBnode&	operator=(const RBnode& other)
		{
			if (this != &other)
			{
				_value = other._value;
				_parent = other._parent;
				_left = other._left;
				_right = other._right;
				_color = other._color;
			}
			return (*this);
		};

		void	flip_color()
		{
			_color = (_color == red ? black : red);
		};

		node_ptr	tree_min(node_ptr root)
		{
			while (root->_left != NULL)
				root = root->_left;
			return (root);
		};


		const_node_ptr	const_tre_min(const_node_ptr root) const
		{
			while (root->_left != NULL)
				root = root->_left;
			return (root);
		};

		node_ptr	tree_max(node_ptr root)
		{
			while (root->_right != NULL)
				root = root->_right;
			return (root);
		};

		const_node_ptr	const_tree_max(const_node_ptr root) const
		{
			while (root->_right != NULL)
				root = root->_right;
			return (root);
		};
	};
};

#endif
