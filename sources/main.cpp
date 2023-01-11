/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:52:54 by gkehren           #+#    #+#             */
/*   Updated: 2023/01/11 15:20:25 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

int main()
{
	test_map();
	time_test_map(1);
	test_vector();
	time_test_vector(1);
	test_stack();
	time_test_stack(1);
	test_set();
	time_test_set(1);
	//main_vector();
	return 0;
}
