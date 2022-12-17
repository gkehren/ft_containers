/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:05:14 by gkehren           #+#    #+#             */
/*   Updated: 2022/12/18 00:40:16 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include "../ft_containers.hpp"

void	main_vector(void)
{
	std::cout << "---===| My Vector |===---" << std::endl;
	ft::Vector<int>	v;

	std::cout << "size = " << v.size() << std::endl;
	std::cout << "capacity = " << v.capacity() << std::endl;
	std::cout << "empty = " << v.empty() << std::endl;
	v.push_back(42);
	v.push_back(5);
	v.push_back(9);
	v.pop_back();
	for (size_t i = 0; i < v.size(); i++)
		std::cout << "[" << i << "] = " << v[i] << std::endl;
	std::cout << "size = " << v.size() << std::endl;
	std::cout << "capacity = " << v.capacity() << std::endl;
	std::cout << "empty = " << v.empty() << std::endl;
	//try
	//{
	//	std::cout << "element 0 = " << v[94] << std::endl;
	//}
	//catch(const std::exception& e)
	//{
	//	std::cerr << e.what() << '\n';
	//}

	std::cout << std::endl << "---===| STL Vector |===---" << std::endl;
	std::vector<int>	v1;

	std::cout << "size = " << v1.size() << std::endl;
	std::cout << "capacity = " << v1.capacity() << std::endl;
	std::cout << "empty = " << v1.empty() << std::endl;
	v1.push_back(42);
	v1.push_back(9);
	v1.push_back(5);
	v1.pop_back();
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << "[" << i << "] = " << v1[i] << std::endl;
	std::cout << "size = " << v1.size() << std::endl;
	std::cout << "capacity = " << v1.capacity() << std::endl;
	std::cout << "empty = " << v1.empty() << std::endl;
	//try
	//{
	//	std::cout << "element 0 = " << v1.at(94) << std::endl;
	//}
	//catch(const std::exception& e)
	//{
	//	std::cerr << e.what() << '\n';
	//}
}
