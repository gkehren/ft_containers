/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:05:48 by gkehren           #+#    #+#             */
/*   Updated: 2023/01/11 15:52:45 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_HPP
#define FT_CONTAINERS_HPP

#include <iostream>
#include <ctime>
#include "../utils/ANSI_codes.hpp"

int		test_map();
void	time_test_map(int n);
int		test_vector();
void	time_test_vector(int n);
int		test_stack();
void	time_test_stack(int n);
int		test_set();
void	time_test_set(int n);

#endif
