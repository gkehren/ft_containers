/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:05:14 by gkehren           #+#    #+#             */
/*   Updated: 2022/12/30 21:16:52 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_containers.hpp"
#include "vector.hpp"

int	choose_test()
{
	int	choice;

	std::cout << BOLD << UNDER << GREEN << "To select a test enter the corresponding number:" << RESET << std::endl;
	std::cout << "1:  size" << std::endl;
	std::cout << "2:  max_size" << std::endl;
	std::cout << "3:  resize" << std::endl;
	std::cout << "4:  capacity" << std::endl;
	std::cout << "5:  empty" << std::endl;
	std::cout << "6:  reserve" << std::endl;
	std::cout << "7:  at" << std::endl;
	std::cout << "8:  front" << std::endl;
	std::cout << "9:  back" << std::endl;
	std::cout << "10: assign" << std::endl;
	std::cout << "11: push_back" << std::endl;
	std::cout << "12: pop_back" << std::endl;
	std::cout << "13: insert" << std::endl;
	std::cout << "14: erase" << std::endl;
	std::cout << "15: swap" << std::endl;
	std::cout << "16: clear" << std::endl;
	std::cout << CYAN << UNDER << "Enter a number:" << RESET << " ";
	if (!(std::cin >> choice))
	{
		std::cout << RED << "Error: Invalid input. Please enter an integer." << RESET << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return (-1);
	}
	else if (choice < 1 || choice > 16)
	{
		std::cout << RED << "the number must be included in the choices" << RESET << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return (-1);
	}
	return (choice);

}

int	get_size()
{
	int	size = -1;

	while (size < 0)
	{
		std::cout << CYAN << UNDER << "Enter the size of the vector:" << RESET << " ";
		if (!(std::cin >> size))
		{
			std::cout << RED << "Error: Invalid input. Please enter an integer." << RESET << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return (-1);
		}
	}
	return (size);
}

void	main_vector(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	std::cout << BOLD << UNDER << GREEN << "To generate a vector enter the following values:" << RESET << std::endl;
	int	size = get_size();
	while (size == -1)
		size = get_size();
	ft::vector<int> vector(size, 42);

	int choice = choose_test();
	while (choice == -1)
		choose_test();
	if (choice == 1)
	{
		std::cout << vector.size() << std::endl;
		return ;
	}
	else if (choice == 2)
	{
		std::cout << vector.max_size() << std::endl;
		return ;
	}
	else if (choice == 3)
	{
		vector.resize(42);
		return ;
	}
	else if (choice == 4)
	{
		std::cout << vector.capacity() << std::endl;
		return ;
	}
	else if (choice == 5)
	{
		std::cout << vector.empty() << std::endl;
		return ;
	}
	else if (choice == 6)
	{
		vector.reserve(42);
		return ;
	}
	else if (choice == 7)
	{
		std::cout << vector.at(42) << std::endl;
		return ;
	}
	else if (choice == 8)
	{
		std::cout << vector.front() << std::endl;
		return ;
	}
	else if (choice == 9)
	{
		std::cout << vector.back() << std::endl;
		return ;
	}
	else if (choice == 10)
	{
		vector.assign(42, 5);
		return ;
	}
	else if (choice == 11)
	{
		vector.push_back(91);
		return ;
	}
	else if (choice == 12)
	{
		vector.pop_back();
		return ;
	}
	else if (choice == 13)
	{
		std::cout << "You choose the test number 13" << std::endl;
		return ;
	}
	else if (choice == 14)
	{
		std::cout << "You choose the test number 14" << std::endl;
		return ;
	}
	else if (choice == 15)
	{
		std::cout << "You choose the test number 15" << std::endl;
		return ;
	}
	else if (choice == 16)
	{
		vector.clear();
		return ;
	}
	else
	{
		std::cout << "Error: please choose a test again" << std::endl;
	}







	//std::cout << "---===| My Vector |===---" << std::endl;
	//ft::vector<int>	v;

	//v.push_back(42);
	//v.push_back(5);
	//v.push_back(9);
	//v.pop_back();
	////for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	////	std::cout << *it << std::endl;
	////std::cout << "Reverse" << std::endl;
	////for (ft::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
	////	std::cout << *it << std::endl;
	//std::cout << v.size() << std::endl;

	//try
	//{
	//	std::cout << v.at(2) << std::endl;
	//}
	//catch(const std::exception& e)
	//{
	//	std::cerr << e.what() << '\n';
	//}
	//v.back() = 91;
	//for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//	std::cout << *it << std::endl;

	//std::cout << std::endl << "---===| STL Vector |===---" << std::endl;
	//std::vector<int>	v1;

	//v1.push_back(42);
	//v1.push_back(5);
	//v1.push_back(9);
	//v1.pop_back();
	////for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	////	std::cout << *it << std::endl;
	////std::cout << "Reverse" << std::endl;
	////for (std::vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); ++it)
	////	std::cout << *it << std::endl;
	//std::cout << v1.size() << std::endl;

	//try
	//{
	//	std::cout << v1.at(2) << std::endl;
	//}
	//catch(const std::exception& e)
	//{
	//	std::cerr << e.what() << '\n';
	//}
	//v1.back() = 91;
	//for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	//	std::cout << *it << std::endl;
}
