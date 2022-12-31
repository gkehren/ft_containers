/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:05:14 by gkehren           #+#    #+#             */
/*   Updated: 2022/12/31 16:55:30 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_containers.hpp"
#include "vector.hpp"

static void	test_1()
{
	ft::vector<int> test;

	std::cout << CYAN << BOLD "---== BASIC FT DEMONSTRATION ==---" << RESET << std::endl;

	std::cout << "Creating ft::vector test." << std::endl;

	std::cout << "Empty() = " << std::boolalpha << test.empty() << std::endl << std::endl;

	std::cout << CYAN << "---PUSH DATA---" << RESET << std::endl;
	test.push_back(32);
	std::cout << "Push : " << test[0] << std::endl;
	test.push_back(64);
	std::cout << "Push : " << test[1] << std::endl;

	std::cout << "Empty() = " << std::boolalpha << test.empty() << std::endl << std::endl;

	std::cout << CYAN << "---INFOS---" << RESET << std::endl;
	std::cout << "Size = " <<  test.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << std::endl;

	std::cout << CYAN << "---PUSH DATA---" << RESET << std::endl;
	test.push_back(128);
	std::cout << "Push : " << test[2] << std::endl;
	test.push_back(256);
	std::cout << "Push : " << test[3] << std::endl;
	test.push_back(512);
	std::cout << "Push : " << test[4] << std::endl;

	std::cout << CYAN << "---INFOS---" << RESET << std::endl;
	std::cout << "Size = " <<  test.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << std::endl;
	std::cout << CYAN << BOLD << "---==------------------------==---" << RESET << std::endl << std::endl;

	std::vector<int> stdtest;

	std::cout << MAGENTA << BOLD "---== BASIC STD COMPARISON ==---" << RESET << std::endl;

	std::cout << "Creating std::vector test." << std::endl;

	std::cout << "Empty() = " << std::boolalpha << stdtest.empty() << std::endl << std::endl;

	std::cout << MAGENTA << "---PUSH DATA---" << RESET << std::endl;
	stdtest.push_back(32);
	std::cout << "Push : " << stdtest[0] << std::endl;
	stdtest.push_back(64);
	std::cout << "Push : " << stdtest[1] << std::endl;

	std::cout << "Empty() = " << std::boolalpha << stdtest.empty() << std::endl << std::endl;

	std::cout << MAGENTA << "---INFOS---" << RESET << std::endl;
	std::cout << "Size = " <<  stdtest.size() << std::endl;
	std::cout << "Capacity = " << stdtest.capacity() << std::endl;

	std::cout << MAGENTA << "---PUSH DATA---" << RESET << std::endl;
	stdtest.push_back(128);
	std::cout << "Push : " << stdtest[2] << std::endl;
	stdtest.push_back(256);
	std::cout << "Push : " << stdtest[3] << std::endl;
	stdtest.push_back(512);
	std::cout << "Push : " << stdtest[4] << std::endl;

	std::cout << MAGENTA << "---INFOS---" << RESET << std::endl;
	std::cout << "Size = " <<  stdtest.size() << std::endl;
	std::cout << "Capacity = " << stdtest.capacity() << std::endl;
	std::cout << MAGENTA << BOLD << "---==------------------------==---" << RESET << std::endl << std::endl;
}

void	clearscreen()
{
	for (int i = 0; i < 100; i++)
		std::cout << std::endl;
}

int	choose_test()
{
	std::string	input;
	int			choice;

	std::cout << BOLD << UNDER << GREEN << "To select a test enter the corresponding number:" << RESET << std::endl;
	std::cout << BOLD << CYAN << "(exit | quit to leave)" << RESET << std::endl << std::endl;

	std::cout << "1:  empty() | operator[] | push() | size() | capacity() | max_size()" << std::endl;
	std::cout << "2:  at() | front() | back()" << std::endl;
	std::cout << "3:  resize() | reserve()" << std::endl;
	std::cout << "4:  pop_back()" << std::endl;
	std::cout << "5:  iterators" << std::endl;
	std::cout << "6:  reverse_iterators" << std::endl;
	std::cout << "7:  constructors" << std::endl;
	std::cout << "8:  assign()" << std::endl;
	std::cout << "9:  insert()" << std::endl;
	std::cout << "10: clear() | erase()" << std::endl;
	std::cout << "11: swap()" << std::endl;
	std::cout << "12: Non-member operators" << std::endl;
	std::cout << "13: Non-menber swap" << std::endl;

	std::cout << CYAN << UNDER << "Enter a number:" << RESET << std::endl << "> ";
	std::getline(std::cin, input);
	if (input == "exit" || input == "quit" || input == "q")
		return (42);
	clearscreen();
	try
	{
		std::istringstream(input) >> choice;
	}
	catch(const std::invalid_argument&)
	{
		std::cout << RED << "Error: Invalid input. Please enter an integer." << RESET << std::endl;
		std::cin.clear();
		return (-1);
	}
	if (choice < 1 || choice > 13)
	{
		std::cout << RED << "the number must be included in the choices" << RESET << std::endl;
		std::cin.clear();
		return (-1);
	}
	return (choice);

}

void	main_vector()
{

	while (1)
	{
		int choice = choose_test();
		switch (choice)
		{
			case 1:
				test_1();
				break;
			case 2:
				std::cout << "You choose the test number 2" << std::endl;
				break;
			case 3:
				std::cout << "You choose the test number 3" << std::endl;
				break;
			case 4:
				std::cout << "You choose the test number 4" << std::endl;
				break;
			case 5:
				std::cout << "You choose the test number 5" << std::endl;
				break;
			case 6:
				std::cout << "You choose the test number 6" << std::endl;
				break;
			case 7:
				std::cout << "You choose the test number 7" << std::endl;
				break;
			case 8:
				std::cout << "You choose the test number 8" << std::endl;
				break;
			case 9:
				std::cout << "You choose the test number 9" << std::endl;
				break;
			case 10:
				std::cout << "You choose the test number 10" << std::endl;
				break;
			case 11:
				std::cout << "You choose the test number 11" << std::endl;
				break;
			case 12:
				std::cout << "You choose the test number 12" << std::endl;
				break;
			case 13:
				std::cout << "You choose the test number 13" << std::endl;
				break;
			case 42:
				return;
			default:
				std::cout << "Error: please choose a test again" << std::endl;
				break;
		}
	}
}
