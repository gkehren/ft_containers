/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:05:14 by gkehren           #+#    #+#             */
/*   Updated: 2022/12/28 01:12:29 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "../ft_containers.hpp"

void	main_vector(void)
{
	std::cout << "---===| My Vector |===---" << std::endl;
	ft::vector<int>	v;

	v.push_back(42);
	v.push_back(5);
	v.push_back(9);
	v.pop_back();
	//for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//	std::cout << *it << std::endl;
	//std::cout << "Reverse" << std::endl;
	//for (ft::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
	//	std::cout << *it << std::endl;
	std::cout << v.size() << std::endl;

	try
	{
		std::cout << v.at(2) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	v.back() = 91;
	for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;

	std::cout << std::endl << "---===| STL Vector |===---" << std::endl;
	std::vector<int>	v1;

	v1.push_back(42);
	v1.push_back(5);
	v1.push_back(9);
	v1.pop_back();
	//for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	//	std::cout << *it << std::endl;
	//std::cout << "Reverse" << std::endl;
	//for (std::vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); ++it)
	//	std::cout << *it << std::endl;
	std::cout << v1.size() << std::endl;

	try
	{
		std::cout << v1.at(2) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	v1.back() = 91;
	for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		std::cout << *it << std::endl;
}
