/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:05:14 by gkehren           #+#    #+#             */
/*   Updated: 2022/12/28 15:22:39 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#if 1 //CREATE A REAL STL EXAMPLE
	#include "vector.hpp"
	//#include <vector>
	//namespace ft = std;
#else
	#include <vector>
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

int main_vector(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::vector<Buffer> vector_buffer;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	return (0);
}

//void	main_vector(void)
//{
//	std::cout << "---===| My Vector |===---" << std::endl;
//	ft::vector<int>	v;

//	v.push_back(42);
//	v.push_back(5);
//	v.push_back(9);
//	v.pop_back();
//	//for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	//	std::cout << *it << std::endl;
//	//std::cout << "Reverse" << std::endl;
//	//for (ft::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
//	//	std::cout << *it << std::endl;
//	std::cout << v.size() << std::endl;

//	try
//	{
//		std::cout << v.at(2) << std::endl;
//	}
//	catch(const std::exception& e)
//	{
//		std::cerr << e.what() << '\n';
//	}
//	v.back() = 91;
//	for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
//		std::cout << *it << std::endl;

//	std::cout << std::endl << "---===| STL Vector |===---" << std::endl;
//	std::vector<int>	v1;

//	v1.push_back(42);
//	v1.push_back(5);
//	v1.push_back(9);
//	v1.pop_back();
//	//for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
//	//	std::cout << *it << std::endl;
//	//std::cout << "Reverse" << std::endl;
//	//for (std::vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); ++it)
//	//	std::cout << *it << std::endl;
//	std::cout << v1.size() << std::endl;

//	try
//	{
//		std::cout << v1.at(2) << std::endl;
//	}
//	catch(const std::exception& e)
//	{
//		std::cerr << e.what() << '\n';
//	}
//	v1.back() = 91;
//	for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
//		std::cout << *it << std::endl;
//}
