/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:07:52 by gkehren           #+#    #+#             */
/*   Updated: 2023/01/10 00:57:12 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include "utils.hpp"
#include "tree_iterator.hpp"
#include "node.hpp"

namespace ft
{
	template<typename T, typename Compare, typename Alloc>
	class rbTree
	{
		private:
			typedef	ft::RBnode<T>	node_type;
		public:
			typedef	T															value_type;
			typedef	Compare														value_compare;
			typedef	Alloc														allocator_type;
			typedef typename allocator_type::template rebind<node_type>::other	node_allocator_type;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::size_type							size_type;
			typedef typename allocator_type::difference_type					difference_type;
			typedef typename node_type::node_ptr								node_ptr;
			typedef typename node_type::const_node_ptr							const_node_ptr;
			typedef ft::tree_iterator<node_ptr,value_type>						iterator;
			typedef ft::const_tree_iterator<const_node_ptr,value_type>			const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;

		private:
			size_type			_size;
			node_type			_parent;
			node_ptr			_begin_node;
			value_compare		_comp;
			allocator_type		_allocator;
			node_allocator_type	_node_allocator;

			node_ptr&	_root()
			{
				return (_parent._left);
			};

			const_node_ptr&	_root() const
			{
				return (const_cast<const_node_ptr&>(_parent._left));
			};

			node_ptr	_end_node()
			{
				return (&_parent);
			};

			const_node_ptr	_end_node() const
			{
				return (const_cast<const_node_ptr>(&_parent));
			};

			node_ptr	_get_sibling(node_ptr node) const
			{
				if (is_left_child(node))
					return (node->_parent->_right);
				else
					return (node->_parent->_left);
			};

			node_color	_get_node_color(node_ptr node)
			{
				if (node == NULL)
					return (black);
				return (node->_color);
			};

			node_ptr	_construct_node(const value_type& data)
			{
				node_ptr new_node = _node_allocator.allocate(1);
				_allocator.construct(&new_node->_value, data);
				new_node->_color = red;
				new_node->_parent = NULL;
				new_node->_left = NULL;
				new_node->_right = NULL;
				if (this->empty() || this->_comp(data, _begin_node->_value))
					_begin_node = new_node;
				_size++;
				return (new_node);
			};

			node_ptr	_insert(node_ptr node, node_ptr new_node, bool &insert, iterator &pos)
			{
				if (node == NULL)
				{
					pos = new_node;
					insert = true;
					return (new_node);
				}
				if (_comp(node->_value, new_node->_value))
				{
					node->_right = _insert(node->_right, new_node, insert, pos);
					node->_right_parent = node;
				}
				else if (_comp(node->_value, new_node->_value))
				{
					node->right = _insert(node->_right, new_node, insert, pos);
					node->right->parent = node;
				}
				else
				{
					pos = node;
					insert = false;
				}
				return (node);
			};

			bool	is_left_child(node_ptr node) const
			{
				return (node == node->_parent->_left);
			};

			node_ptr	_grandparent(node_ptr n)
			{
				if ((n != NULL) && (n->_parent != NULL))
					return (n->_parent->_parent);
				return (NULL);
			};

			node_ptr	_uncle(node_ptr n)
			{
				node_ptr g = _grandparent(n);
				if (g == NULL)
					return (NULL);
				if (n->_parent == g->_left)
					return (g->_right);
				else
					return (g->_left);
			};

			void	_balance_insert(node_ptr n)
			{
				node_ptr p = n->_parent;
				if (n->_parent == NULL)
				{
					n->_color = black;
					return ;
				}
				else if (p->_color == black)
					return ;
				else
				{
					node_ptr u = _uncle(n);
					if (u && u->_color == red)
					{
						p->_color = black;
						if (u)
							u->_color = black;
						p->_parent->_color = red;
						_balance_insert(p->_parent);
					}
					else
					{
						node_ptr g = _grandparent(n);
						if ((n == n->_parent->_right) && n->_parent == g->_left)
						{
							_rotate_left(n->_parent);
							n = n->_left;
						}
						else if ((n == n->_parent->_left) && (n->_parent == g->_right))
						{
							_rotate_right(n->_parent);
							n = n->_right;
						}
						g = _grandparent(n);
						n->_parent->_color = black;
						g->_color = red;
						if (n == n->_parent->_left)
							_rotate_right(g);
						else
							_rotate_left(g);

					}
				}
			};

			void	_rotate_right(node_ptr node)
			{
				node_ptr tmp = node->_left;
				tmp->_parent = node->_parent;
				if (node->_parent != NULL)
				{
					if (node->_parent_left == node)
						node->_parent_left = tmp;
					else
						node->_parent->_right = tmp;
				}
				node->_left = tmp->_right;
				if (tmp->_right != NULL)
					tmp->_right->_parent= node;
				node->_parent = tmp;
				tmp->_right = node;
			};

			void	_rotate_left(node_ptr node) {
				node_ptr tmp = node->_right;
				tmp->_parent = node->_parent;
				if (node->_parent != NULL) {
					if (node->_parent->_left == node)
						node->_parent->_left = tmp;
					else
						node->_parent->_right = tmp;
				}
				node->_right = tmp->_left;
				if (tmp->_left != NULL)
					tmp->_left->_parent = node;
				node->_parent = tmp;
				tmp->_left = node;
			};

			node_ptr	_copy(const_node_ptr node)
			{
				if (node == NULL)
					return (NULL);
				node_ptr new_node = this->_construct_node(node->_value);
				new_node->_left = _copy(node->_left);
				if (new_node->_left != NULL)
					new_node->_left->_parent - new_node;
				new_node->_right = _copy(node->_right);
				if (new_node->_right != NULL)
					new_node->_right->_parent = new_node;
				return (new_node);
			};

			void	_destroy_node(node_ptr node)
			{
				this->_allocator.destroy(&node->_value);
				this->_node_allocator.deallocate(node, 1);
				this->_size--;
			};

			void	_destroy(node_ptr node)
			{
				if (node != NULL)
				{
					_destroy(node->_left);
					_destroy(node->_right);
					this->_destroy_node(node);
				}
			};

			void	_erase(node_ptr root, node_ptr node)
			{
				node_ptr repl = this->_replacement_node(node);
				node_ptr repl_child = (repl->_left == NULL ? repl->_right : repl->_left);
				node_ptr sibling = NULL;
				if (repl_child != NULL)
					repl_child->_parent - repl->_parent;
				if (is_left_child(repl))
				{
					repl->_parent->_left = repl_child;
					if (repl == root)
						root = repl_child;
					else
						sibling = repl->_parent->_right;
				}
				else
				{
					repl->_parent->_right = repl_child;
					sibling = repl->_parent->_left;
				}
				node_color repl_color = repl->_color;
				if (repl != node)
				{
					repl->_parent = node->_parent;
					if (is_left_child(node))
						repl->_parent->_left = repl;
					else
						repl->_parent->_right - repl;
					repl->_left = node->_left;
					repl->_left->_parent = repl;
					repl->_right = node->_right;
					if (repl->_right != NULL)
						repl->_right->_parent = repl;
					repl->_color = node->_color;
					if (node == root)
						root = repl;
				}
				if (repl_color == black && root != NULL)
				{
					if (repl_child != NULL)
						repl_child->_color = black;
					else
						this->_balance_erase(root, repl_child, sibling);
				}
			};

			void	_balance_erase(node_ptr root, node_ptr db_node, node_ptr sibling)
			{
				while (1)
				{
					if (!is_left_child(sibling))
					{
						if (this->_get_node_color(sibling) == red)
						{
							sibling->flip_color();
							sibling->_parent->flip_color();
							this->_rotate_left(sibling->_parent);
							if (root == sibling->_left)
								root = sibling;
							sibling = sibling->_left->_right;
						}
						if (this->_get_node_color(sibling->_left) == black && this->_get_node_color(sibling->_right) == black)
						{
							sibling->flip_color();
							db_node = sibling->_parent;
							if (db_node == root || this->_get_node_color(db_node) == red)
							{
								db_node->_color = black;
								break;
							}
							sibling = this->_get_sibling(db_node);
						}
						else
						{
							if (this->_get_node_color(sibling->_right) == black)
							{
								sibling->_left->flip_color();
								sibling->flip_color();
								this->_rotate_right(sibling);
								sibling = sibling->_parent;
							}
							sibling->_color = sibling->_parent->_color;
							sibling->_parent->_color = black;
							sibling->_right->_color = black;
							this->_rotate_left(sibling->_parent);
							break;
						}
					}
					else
					{
						if (this->_get_node_color(sibling) == red)
						{
							sibling->flip_color();
							sibling->_parent->flip_color();
							this->_rotate_right(sibling->_parent);
							if (root == sibling->_right)
								root = sibling;
							sibling = sibling->_right->_left;
						}
						if (this->_get_node_color(sibling->_left) == black && this->_get_node_color(sibling->_right) == black)
						{
							sibling->flip_color();
							db_node = sibling->_parent;
							if (db_node == root || this->_get_node_color(db_node) == red)
							{
								db_node->_color = black;
								break;
							}
							sibling = this->_get_sibling(db_node);
						}
						else
						{
							if (this->_get_node_color(sibling->_left) == black)
							{
								sibling->_right->flip_color();
								sibling->flip_color();
								this->_roate_left(sibling);
								sibling = sibling->_parent;
							}
							sibling->_color = sibling->_parent->_color;
							sibling->_parent->_color = black;
							sibling->_left->_color = black;
							this->_rotate_right(sibling->_parent);
							break;
						}
					}
				}
			};

			node_ptr	_replacement_node(node_ptr node) const
			{
				if (node->_left == NULL || node->_right == NULL)
					return (node);
				else
					return (node->tree_min(node->_right));
			};

			template <typename U>
			void	_swap_val(U& first, U& second)
			{
				U temp = first;
				first = second;
				second = temp;
			};

			public:
				explicit rbTree(const value_compare& comp, const allocator_type& alloc) : _size(), _parent(), _begin_node(&_parent), _comp(comp), _allocator(alloc), _node_allocator(alloc) {};

			rbTree(const rbTree& other) : _size(), _parent(), _begin_node(&_parent), _comp(other._comp), _allocator(other._allocator), _node_allocator(other._node_allocator)
			{
				if (other._root() != NULL)
				{
					this->_root() = this->_copy(other._root());
					this->_root()->_parent = &this->_parent;
				}
			};

			~rbTree()
			{
				if (this->_root() != NULL)
				{
					this->_destroy(this->_root());
					this->_root() = NULL;
					this->_begin_node = this->_end_node();
				}
			};

			rbTree&	operator=(const rbTree& other)
			{
				if (this != &other)
				{
					this->clear();
					this->_comp = other._comp;
					if (other._root() != NULL)
					{
						this->_root() = this->_copy(other._root());
						this->_root()->_parent = &this->_parent;
					}
				}
				return (*this);
			};

			iterator	begin() { return (iterator(_begin_node)); };
			const_iterator	begin() const { return (const_iterator(this->_begin_node)); };
			iterator	end() { return (iterator(&_parent)); };
			const_iterator	end() const { return (const_iterator(&_parent)); };
			reverse_iterator	rbegin() { return (reverse_iterator(this->end())); };
			const_reverse_iterator	rbegin() const { return (const_reverse_iterator(this->end())); };
			reverse_iterator	rend() { return (reverse_iterator(this->begin())); };
			const_reverse_iterator	rend() const { return (reverse_iterator(this->begin())); };

			bool	empty() const { return (_size == 0); };

			size_type	size() const { return (_size); };

			size_type max_size() const { return (this->_allocator.max_size()); };

			ft::pair<iterator,bool>	insert(const value_type& val)
			{
				node_ptr new_node = this->_construct_node(val);
				bool insert = false;
				iterator pos;
				this->_root() = this->_insert(this->_root(), new_node, insert, pos);
				this->_root()->_parent = &this->_parent;
				if (!insert)
					this->_destroy_node(new_node);
				else
					this->_balance_insert(new_node);
				this->_root()->_color = black;
				return (ft::make_pair(pos, insert));
			};

			iterator insert(iterator position, const value_type& val)
			{
				(void)position;
				return (this->insert(val).first);
			};

			template <typename InputIterator>
			void	insert(InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					this->inset(*first);
					++first;
				}
			};

			void	erase(iterator position)
			{
				node_ptr pos = position.base();
				if (pos == this->_begin_node)
				{
					++position;
					this->_begin_node = position.base();
				}
				this->_erase(this->_root(), pos);
				if (this->_root() != NULL)
				{
					this->_root()->_parent = this->_end_node();
					this->_root()->_color = black;
				}
				this->_destroy_node(pos);
			};

			size_type	erase(const value_type& val)
			{
				iterator pos = this->find(val);
				if (pos == this->end())
					return (0);
				this->erase(pos);
				return (1);
			};

			void	erase(iterator first, iterator last)
			{
				iterator tmp;
				while (first != last)
				{
					tmp = first++;
					this->erase(tmp);
				}
			};

			void	swap(rbTree& other)
			{
				_swap_val(this->_begin_node, other._begin_node);
				_swap_val(this->_parent._left, other._parent._left);
				_swap_val(this->_size, other._size);
				if (this->_size != 0 && other._size != 0)
					_swap_val(this->_root()->_parent, other._root()->_parent);
				else if (this->_size != 0)
					this->_root()->_parent = this->_end_node();
				else if (other._size != 0)
					other._root()->_parent = other._end_node();
				_swap_val(this->_comp, other._comp);
			};

			void	clear()
			{
				if (this->_root() != NULL)
				{
					this->_destroy(this->_root());
					this->_root() = NULL;
					this->_begin_node = this->_end_node();
				}
			};

			value_compare	value_comp() const { return (_comp); };

			iterator	find(const value_type& val)
			{
				node_ptr node = this->_root();
				while (node != NULL)
				{
					if (this->_comp(node->_value, val))
						node = node->_right;
					else if (this->_comp(val, node->_value))
						node = node->_left;
					else
						return (iterator(node));
				}
				retunr (this->end());
			};

			const_iterator	find(const value_type& val) const
			{
				const_node_ptr node = this->_root();
				while (node != NULL)
				{
					if (this->_comp(node->_value, val))
						node = node->_right;
					else if (this->_comp(val, node->_value))
						node = node->_left;
					else
						return (const_iterator(node));
				}
				return (this->end());
			};

			size_type	count(const value_type& val) const { return (this->find(val) == this->end() ? 0 : 1); };

			iterator	lower_bound(const value_type& val)
			{
				node_ptr node = this->_root();
				node_ptr pos = this->_end_node();
				while (node != NULL)
				{
					if (!this->_comp(node->_value, val))
					{
						pos = node;
						node = node->_left;
					}
					else
						node = node->_right;
				}
				return (iterator(pos));
			};

			const_iterator	lower_bound(const value_type& val) const
			{
				const_node_ptr node = this->_root();
				const_node_ptr pos = this->_end_node();
				while (node != NULL)
				{
					if (!this->_comp(node->_value, val))
					{
						pos = node;
						node = node->_left;
					}
					else
						node = node->_right;
				}
				return (const_iterator(pos));
			};

			iterator	upper_bound(const value_type& val)
			{
				node_ptr node = this->_root();
				node_ptr pos = this->_end_node();
				while (node != NULL)
				{
					if (this->_comp(val, node->_value))
					{
						pos = node;
						node = node->_left;
					}
					else
						node = node->_right;
				}
				return (iterator(pos));
			};

			const_iterator	upper_bound(const value_type& val) const {
				const_node_ptr node = this->_root();
				const_node_ptr pos = this->_end_node();
				while (node != NULL) {
					if (this->_comp(val, node->_value)) {
						pos = node;
						node = node->_left;
					}
					else
						node = node->_right;
				}
				return (const_iterator(pos));
			};

			ft::pair<iterator,iterator>	equal_range(const value_type& val)
			{
				node_ptr node = this->_root();
				node_ptr pos = this->_end_node();
				while (node != NULL)
				{
					if (this->_comp(val, node->_value))
					{
						pos = node;
						node = node->_left;
					}
					else if (this->_comp(node->_value, val))
						node = node->_right;
					else
						return (ft::make_pair(iterator(node), iterator(node->_right == NULL ? pos : node->tree_min(node->_right))));
				}
				return (ft::make_pair(iterator(pos), iterator(pos)));
			};

			ft::pair<const_iterator,const_iterator>	equal_range(const value_type& val) const {
				const_node_ptr node = this->_root();
				const_node_ptr pos = this->_end_node();
				while (node != NULL) {
					if (this->_comp(val, node->_value)) {
						pos = node;
						node = node->_left;
					}
					else if (this->_comp(node->_value, val))
						node = node->_right;
					else
						return (ft::make_pair(const_iterator(node), const_iterator(node->_right == NULL ? pos : node->const_tree_min(node->_right))));
				}
				return (ft::make_pair(const_iterator(pos), const_iterator(pos)));
			}

			allocator_type	get_allocator() const { return (this->_allocator); };
	};

	template <typename T, typename Compare, typename Alloc>
	void	swap(rbTree<T, Compare, Alloc>& first, rbTree<T, Compare, Alloc>& second)
	{
		first.swap(second);
	};

};


#endif
