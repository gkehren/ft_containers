/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:05:14 by gkehren           #+#    #+#             */
/*   Updated: 2023/01/03 15:37:42 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_containers.hpp"
#include "vector.hpp"
#include <iomanip>

static void	test_1()
{
	ft::vector<int> test;
	std::vector<int> stdtest;

	std::cout << CYAN << BOLD "---==--------| BASIC |-------==---" << RESET << std::endl;

	std::cout << CYAN << UNDER << "       FT       |       STD      " << RESET << std::endl;

	std::cout << "Empty() = " << std::boolalpha << test.empty() << "  | Empty() = " << std::boolalpha << stdtest.empty() << std::endl;

	std::cout << CYAN << "------------PUSH DATA------------" << RESET << std::endl;
	test.push_back(32);
	test.push_back(64);
	stdtest.push_back(32);
	stdtest.push_back(64);
	std::cout << "Push : " << test[0] << "       | Push : " << stdtest[0] << std::endl;
	std::cout << "Push : " << test[1] << "       | Push : " << stdtest[1] << std::endl;

	std::cout << CYAN << "------------INFOS----------------" << RESET << std::endl;
	std::cout << "Size = " <<  test.size() << "        | Size = " <<  stdtest.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << "    | Capacity = " << stdtest.capacity() << std::endl;

	std::cout << CYAN << "------------PUSH DATA------------" << RESET << std::endl;
	test.push_back(128);
	test.push_back(256);
	test.push_back(512);
	stdtest.push_back(128);
	stdtest.push_back(256);
	stdtest.push_back(512);
	std::cout << "Push : " << test[2] << "      | Push : " << stdtest[2] << std::endl;
	std::cout << "Push : " << test[3] << "      | Push : " << stdtest[3] << std::endl;
	std::cout << "Push : " << test[4] << "      | Push : " << stdtest[4] << std::endl;

	std::cout << CYAN << "------------INFOS----------------" << RESET << std::endl;
	std::cout << "Size = " <<  test.size() << "        | Size = " <<  stdtest.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << "    | Capacity = " << stdtest.capacity() << std::endl;
	std::cout << CYAN << BOLD << "---==------------------------==---" << RESET << std::endl << std::endl;
}

static void	test_2()
{
	ft::vector<int> test;
	std::vector<int> stdtest;

	std::cout << CYAN << BOLD "---==---| ELEMENT ACCESS |---==---" << RESET << std::endl;
	std::cout << "For a vector<int> = {43, 1, 2, 3, 56}" << std::endl;
	std::cout << CYAN << UNDER << "       FT       |       STD      " << RESET << std::endl;

	test.push_back(43);
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(56);
	stdtest.push_back(43);
	stdtest.push_back(1);
	stdtest.push_back(2);
	stdtest.push_back(3);
	stdtest.push_back(56);

	std::cout << CYAN << "------------TEST AT()------------" << RESET << std::endl;
	std::cout << "at(0) = " << test.at(0) << "      | at(0) = " << stdtest.at(0) << std::endl;
	std::cout << "at(1) = " << test.at(1) << "       | at(1) = " << stdtest.at(1) << std::endl;
	std::cout << "at(3) = " << test.at(3) << "       | at(3) = " << stdtest.at(3) << std::endl;
	std::cout << "at(4) = " << test.at(4) << "      | at(4) = " << stdtest.at(4) << std::endl;
	std::cout << "at(6) = ";
	try
	{
		std::cout << test.at(6);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "at(6) = ";
	try
	{
		std::cout << stdtest.at(6) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << CYAN << BOLD << "---==------------------------==---" << RESET << std::endl << std::endl;
}

static void	test_3()
{

	std::cout << CYAN << BOLD "---==--------| RESERVE |--------==---" << RESET << std::endl;
	std::cout << "For a vector<int> = empty" << std::endl;
	std::cout << CYAN << UNDER << "         FT        |       STD      " << RESET << std::endl;

	ft::vector<int> v;
	std::vector<int> stdv;

	std::cout << "v.capacity() = " << v.capacity() << "   | v.capacity() = " << stdv.capacity() << std::endl;
	v.reserve(100);
	stdv.reserve(100);
	std::cout << "v.reserve(100)" << "     | v.reserve(100)" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << " | v.capacity() = " << stdv.capacity() << std::endl;
	v.reserve(1);
	stdv.reserve(1);
	std::cout << "v.reserve(1)"  << "       | v.reserve(1)" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << " | v.capacity() = " << stdv.capacity() << std::endl;
	std::cout << CYAN << BOLD << "---==--------------------------==---" << RESET << std::endl << std::endl;
	std::cout << CYAN << BOLD "---==--------| RESIZE |--------==---" << RESET << std::endl;
	std::cout << "For a vector<int> = empty" << std::endl;

	ft::vector<int> v2;
	ft::vector<int> stdv2;

	std::cout << "v.capacity() = " << v2.capacity() << "   | v.capacity() = " << stdv2.capacity() << std::endl;
	std::cout << "v.size() = " << v2.size() << "       | v.size() = " << stdv2.size() << std::endl;

	v2.resize(10);
	stdv2.resize(10);
	std::cout << "v.resize(10);      | v.resize(10);" << std::endl;
	for (size_t i = 0; i < v2.size(); i++)
		std::cout<< std::setfill(' ') << std::setw(18) << v2[i] << " | " << stdv2[i] << std::endl;
	std::cout << std::endl;

	v2.resize(15, 15);
	stdv2.resize(15, 15);
	std::cout << "v.resize(15, 15);  | v.resize(15, 15);" << std::endl;
	for (size_t i = 0; i < v2.size(); i++)
		std::cout<< std::setfill(' ') << std::setw(18) << v2[i] << " | " << stdv2[i] << std::endl;
	std::cout << std::endl;

	v2.resize(3);
	stdv2.resize(3);
	std::cout << "v.resize(3);       | v.resize(3);" << std::endl;
	for (size_t i = 0; i < v2.size(); i++)
		std::cout<< std::setfill(' ') << std::setw(18) << v2[i] << " | " << stdv2[i] << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << BOLD << "---==--------------------------==---" << RESET << std::endl << std::endl;

}

static void	test_4()
{
	std::cout << CYAN << BOLD "---==------| POP BACK |------==---" << RESET << std::endl;
	std::cout << "For a vector<std::string> empty" << std::endl;
	std::cout << CYAN << BOLD << "---==------------------------==---" << RESET << std::endl << std::endl;

	ft::vector<std::string> v;

	v.resize(10, "hello !");
	std::cout << "v.resize(10, \"hello !\");" << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << CYAN << BOLD << "---==------------------------==---" << RESET << std::endl << std::endl;
	std::cout << MAGENTA << BOLD "---==------| STD |------==---" << RESET << std::endl;
	std::cout << "For a vector<std::string> empty" << std::endl;
	std::cout << MAGENTA << BOLD << "---==------------------------==---" << RESET << std::endl << std::endl;

	std::vector<std::string> stdv;

	stdv.resize(10, "hello !");
	std::cout << "v.resize(10, \"hello !\");" << std::endl;
	std::cout << "v.size() = " << stdv.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < stdv.size() - 1; i++)
		std::cout << stdv[i] << ", ";
	std::cout << stdv[stdv.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	stdv.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << stdv.capacity() << std::endl;
	std::cout << "v.size() = " << stdv.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < stdv.size() - 1; i++)
		std::cout << stdv[i] << ", ";
	std::cout << stdv[stdv.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	stdv.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << stdv.capacity() << std::endl;
	std::cout << "v.size() = " << stdv.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < stdv.size() - 1; i++)
		std::cout << stdv[i] << ", ";
	std::cout << stdv[stdv.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	stdv.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << stdv.capacity() << std::endl;
	std::cout << "v.size() = " << stdv.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < stdv.size() - 1; i++)
		std::cout << stdv[i] << ", ";
	std::cout << stdv[stdv.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	stdv.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << stdv.capacity() << std::endl;
	std::cout << "v.size() = " << stdv.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < stdv.size() - 1; i++)
		std::cout << stdv[i] << ", ";
	std::cout << stdv[stdv.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	stdv.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << stdv.capacity() << std::endl;
	std::cout << "v.size() = " << stdv.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < stdv.size() - 1; i++)
		std::cout << stdv[i] << ", ";
	std::cout << stdv[stdv.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	stdv.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << stdv.capacity() << std::endl;
	std::cout << "v.size() = " << stdv.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < stdv.size() - 1; i++)
		std::cout << stdv[i] << ", ";
	std::cout << stdv[stdv.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	stdv.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << stdv.capacity() << std::endl;
	std::cout << "v.size() = " << stdv.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < stdv.size() - 1; i++)
		std::cout << stdv[i] << ", ";
	std::cout << stdv[stdv.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	stdv.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << stdv.capacity() << std::endl;
	std::cout << "v.size() = " << stdv.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < stdv.size() - 1; i++)
		std::cout << stdv[i] << ", ";
	std::cout << stdv[stdv.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	stdv.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << stdv.capacity() << std::endl;
	std::cout << "v.size() = " << stdv.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < stdv.size() - 1; i++)
		std::cout << stdv[i] << ", ";
	std::cout << stdv[stdv.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << MAGENTA << BOLD << "---==------------------------==---" << RESET << std::endl << std::endl;
}

static void	test_5()
{
	ft::vector<int>				v;
	ft::vector<int>::iterator	it;

	std::cout << CYAN << BOLD "---==------| ITERATOR |------==---" << RESET << std::endl;

	std::cout << CYAN << "-----------INCREMENTERS-----------" << RESET << std::endl;
	std::cout << CYAN << "---------i++ ++i --i i-- ---------" << RESET << std::endl;
	std::cout << CYAN << "--------------- FT ---------------" << RESET << std::endl;
	std::cout << "For a vector : ";
	v.push_back(5);
	v.push_back(42);
	v.push_back(56);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << "*(v.begin()) = " << *(v.begin()) << std::endl;

	it = v.begin();
	std::cout << "it = v.begin();" << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(it++) = " << *(it++) << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(it--) = " << *(it--) << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(++it) = " << *(++it) << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(--it) = " << *(--it) << std::endl;
	std::cout << "*it = " << *it << std::endl << std::endl;

	std::cout << CYAN << BOLD << "---==------------------------==---" << RESET << std::endl << std::endl;

	std::vector<int>			stdv;
	std::vector<int>::iterator	stdit;

	std::cout << MAGENTA << "--------------- STD --------------" << RESET << std::endl;
	std::cout << "For a vector : ";
	stdv.push_back(5);
	stdv.push_back(42);
	stdv.push_back(56);
	stdv.push_back(1);
	stdv.push_back(2);
	stdv.push_back(3);
	std::cout << "{";
	for (size_t i = 0; i < stdv.size() - 1; i++)
		std::cout << stdv[i] << ", ";
	std::cout << stdv[stdv.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << "*(v.begin()) = " << *(stdv.begin()) << std::endl;

	stdit = stdv.begin();
	std::cout << "it = v.begin();" << std::endl;
	std::cout << "*it = " << *stdit << std::endl;
	std::cout << "*(it++) = " << *(stdit++) << std::endl;
	std::cout << "*it = " << *stdit << std::endl;
	std::cout << "*(it--) = " << *(stdit--) << std::endl;
	std::cout << "*it = " << *stdit << std::endl;
	std::cout << "*(++it) = " << *(++stdit) << std::endl;
	std::cout << "*it = " << *stdit << std::endl;
	std::cout << "*(--it) = " << *(--stdit) << std::endl;
	std::cout << "*it = " << *stdit << std::endl << std::endl;

	std::cout << CYAN << BOLD << "---==------------------------==---" << RESET << std::endl << std::endl;

	std::cout << CYAN << "-----------ARITHMETICS------------" << RESET << std::endl;
	std::cout << CYAN << "--------------- FT ---------------" << RESET << std::endl;
	std::cout << "For a vector : ";
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	it = v.begin();
	std::cout << "it = v.begin();" << std::endl;
	std::cout << "*(it + 0) = " << *(it + 0) << std::endl;
	std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
	std::cout << "*(it + 5) = " << *(it + 5) << std::endl << std::endl;

	it = v.end() - 1;
	std::cout << "it = v.end() - 1;" << std::endl;
	std::cout << "*(it - 0) = " << *(it - 0) << std::endl;
	std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
	std::cout << "*(it - 5) = " << *(it - 5) << std::endl << std::endl;

	std::cout << CYAN << BOLD << "---==------------------------==---" << RESET << std::endl << std::endl;

	std::cout << MAGENTA << "--------------- STD --------------" << RESET << std::endl;
	std::cout << "For a vector : ";
	std::cout << "{";
	for (size_t i = 0; i < stdv.size() - 1; i++)
		std::cout << stdv[i] << ", ";
	std::cout << stdv[stdv.size() - 1];
	std::cout << "}" << std::endl;

	stdit = stdv.begin();
	std::cout << "it = v.begin();" << std::endl;
	std::cout << "*(it + 0) = " << *(stdit + 0) << std::endl;
	std::cout << "*(it + 1) = " << *(stdit + 1) << std::endl;
	std::cout << "*(it + 5) = " << *(stdit + 5) << std::endl << std::endl;

	stdit = stdv.end() - 1;
	std::cout << "it = v.end() - 1;" << std::endl;
	std::cout << "*(it - 0) = " << *(stdit - 0) << std::endl;
	std::cout << "*(it - 1) = " << *(stdit - 1) << std::endl;
	std::cout << "*(it - 5) = " << *(stdit - 5) << std::endl << std::endl;

	std::cout << CYAN << BOLD << "---==------------------------==---" << RESET << std::endl << std::endl;

	std::cout << CYAN << "------------BOOLEANS--------------" << RESET << std::endl;
	std::cout << CYAN << "--------------- FT ---------------" << RESET << std::endl;
	v.clear();
	std::cout << "For a vector : ";
	v.push_back(5);
	v.push_back(42);
	v.push_back(56);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	ft::vector<int>::iterator	it_beg = v.begin();
	ft::vector<int>::iterator	it_end = v.end();
	std::cout << "For an iterator it_beg = v.begin()" << std::endl;
	std::cout << "For an iterator it_end = v.end()" << std::endl << std::endl;

	std::cout << "it_beg < it_end is " << std::boolalpha << (it_beg < it_end) << std::endl;
	std::cout << "it_end < it_beg is " << std::boolalpha << (it_end < it_beg) << std::endl;
	std::cout << "it_beg > it_end is " << std::boolalpha << (it_beg > it_end) << std::endl;
	std::cout << "it_end > it_beg is " << std::boolalpha << (it_end > it_beg) << std::endl << std::endl;

	std::cout << "it_beg == it_end is " << std::boolalpha << (it_beg == it_end) << std::endl;
	std::cout << "it_beg == it_beg is " << std::boolalpha << (it_beg == it_beg) << std::endl;
	std::cout << "it_beg != it_end is " << std::boolalpha << (it_beg != it_end) << std::endl;
	std::cout << "it_beg != it_beg is " << std::boolalpha << (it_beg != it_beg) << std::endl << std::endl;

	std::cout << "it_beg <= it_end is " << std::boolalpha << (it_beg <= it_end) << std::endl;
	std::cout << "it_end <= it_beg is " << std::boolalpha << (it_end <= it_beg) << std::endl;
	std::cout << "it_end <= it_end is " << std::boolalpha << (it_end <= it_end) << std::endl;
	std::cout << "it_beg >= it_end is " << std::boolalpha << (it_beg >= it_end) << std::endl;
	std::cout << "it_end >= it_beg is " << std::boolalpha << (it_end >= it_beg) << std::endl;
	std::cout << "it_end >= it_end is " << std::boolalpha << (it_end >= it_end) << std::endl << std::endl;

	std::cout << CYAN << BOLD << "---==------------------------==---" << RESET << std::endl << std::endl;

	std::cout << CYAN << "--------------- STD ---------------" << RESET << std::endl;
	stdv.clear();
	std::cout << "For a vector : ";
	stdv.push_back(5);
	stdv.push_back(42);
	stdv.push_back(56);
	stdv.push_back(1);
	stdv.push_back(2);
	stdv.push_back(3);
	stdv.push_back(1);
	stdv.push_back(4);
	std::cout << "{";
	for (size_t i = 0; i < stdv.size() - 1; i++)
		std::cout << stdv[i] << ", ";
	std::cout << stdv[v.size() - 1];
	std::cout << "}" << std::endl;

	std::vector<int>::iterator	stdit_beg = stdv.begin();
	std::vector<int>::iterator	stdit_end = stdv.end();
	std::cout << "For an iterator it_beg = v.begin()" << std::endl;
	std::cout << "For an iterator it_end = v.end()" << std::endl << std::endl;

	std::cout << "it_beg < it_end is " << std::boolalpha << (stdit_beg < stdit_end) << std::endl;
	std::cout << "it_end < it_beg is " << std::boolalpha << (stdit_end < stdit_beg) << std::endl;
	std::cout << "it_beg > it_end is " << std::boolalpha << (stdit_beg > stdit_end) << std::endl;
	std::cout << "it_end > it_beg is " << std::boolalpha << (stdit_end > stdit_beg) << std::endl << std::endl;

	std::cout << "it_beg == it_end is " << std::boolalpha << (stdit_beg == stdit_end) << std::endl;
	std::cout << "it_beg == it_beg is " << std::boolalpha << (stdit_beg == stdit_beg) << std::endl;
	std::cout << "it_beg != it_end is " << std::boolalpha << (stdit_beg != stdit_end) << std::endl;
	std::cout << "it_beg != it_beg is " << std::boolalpha << (stdit_beg != stdit_beg) << std::endl << std::endl;

	std::cout << "it_beg <= it_end is " << std::boolalpha << (stdit_beg <= stdit_end) << std::endl;
	std::cout << "it_end <= it_beg is " << std::boolalpha << (stdit_end <= stdit_beg) << std::endl;
	std::cout << "it_end <= it_end is " << std::boolalpha << (stdit_end <= stdit_end) << std::endl;
	std::cout << "it_beg >= it_end is " << std::boolalpha << (stdit_beg >= stdit_end) << std::endl;
	std::cout << "it_end >= it_beg is " << std::boolalpha << (stdit_end >= stdit_beg) << std::endl;
	std::cout << "it_end >= it_end is " << std::boolalpha << (stdit_end >= stdit_end) << std::endl << std::endl;

	std::cout << CYAN << BOLD << "---==------------------------==---" << RESET << std::endl << std::endl;

	std::cout << CYAN << "------------DEREF--------------" << RESET << std::endl;
	std::cout << CYAN << "--------------- FT ---------------" << RESET << std::endl;
	v.clear();
	std::cout << "For a vector : ";
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	it = v.begin();
	std::cout << "it = v.begin()" << std::endl;

	std::cout << "### * ###" << std::endl;
	std::cout << "cout *it = " << *it << std::endl;
	*it = 5;
	std::cout << "*it = 5" << std::endl;
	std::cout << "cout *it = " << *it << std::endl << std::endl;

	std::cout << "### [] ###" << std::endl;
	std::cout << "cout it[3] = " << it[3] << std::endl;
	it[3] = 42;
	std::cout << "it[3] = 42" << std::endl;
	std::cout << "cout it[3] = " << it[3] << std::endl;

	std::cout << "### *i++ *i-- ###" << std::endl;
	std::cout << "For a vector v : ";
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;
	it = v.begin() + 3;
	std::cout << "it = v.begin() + 3" << std::endl;
	std::cout << "cout *it = " << *it << std::endl;

	*it++ = 345879;
	std::cout << "*it++ = 345879;" << std::endl;
	std::cout << "cout *(it - 1) = " << *(it - 1) << std::endl;
	*it-- = 999;
	std::cout << "*it-- = 999;" << std::endl;
	std::cout << "cout *(it + 1) = " << *(it + 1) << std::endl << std::endl;
	std::cout << "now v  : ";
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl << std::endl;
	std::cout << "it = v.begin() + 0" << std::endl;
	std::cout << "cout *it = " << *it << std::endl;
	it += 4;
	std::cout << "it += 4" << *it << std::endl;
	std::cout << "cout *it = " << *it << std::endl;
	it -= 4;
	std::cout << "it -= 4" << *it << std::endl;
	std::cout << "cout *it = " << *it << std::endl << std::endl;
	ft::vector<int>::iterator it_cpy(it);
	std::cout << "iterator it_cpy(it);" << std::endl;
	std::cout << "cout *it_cpy = " << *it_cpy << std::endl << std::endl;

	std::cout << CYAN << BOLD << "---==------------------------==---" << RESET << std::endl << std::endl;

	std::cout << MAGENTA << "--------------- STD ---------------" << RESET << std::endl;
	stdv.clear();
	std::cout << "For a vector : ";
	stdv.push_back(1);
	stdv.push_back(2);
	stdv.push_back(3);
	stdv.push_back(4);
	stdv.push_back(5);
	stdv.push_back(6);
	stdv.push_back(7);
	stdv.push_back(8);
	std::cout << "{";
	for (size_t i = 0; i < stdv.size() - 1; i++)
		std::cout << stdv[i] << ", ";
	std::cout << stdv[stdv.size() - 1];
	std::cout << "}" << std::endl;

	stdit = stdv.begin();
	std::cout << "it = v.begin()" << std::endl;

	std::cout << "cout *it = " << *stdit << std::endl;
	*stdit = 5;
	std::cout << "*it = 5" << std::endl;
	std::cout << "cout *it = " << *stdit << std::endl << std::endl;

	std::cout << "cout it[3] = " << stdit[3] << std::endl;
	stdit[3] = 42;
	std::cout << "it[3] = 42" << std::endl;
	std::cout << "cout it[3] = " << stdit[3] << std::endl;

	std::cout << "For a vector v : ";
	std::cout << "{";
	for (size_t i = 0; i < stdv.size() - 1; i++)
		std::cout << stdv[i] << ", ";
	std::cout << stdv[stdv.size() - 1];
	std::cout << "}" << std::endl;
	stdit = stdv.begin() + 3;
	std::cout << "it = v.begin() + 3" << std::endl;
	std::cout << "cout *it = " << *stdit << std::endl;

	*stdit++ = 345879;
	std::cout << "*it++ = 345879;" << std::endl;
	std::cout << "cout *(it - 1) = " << *(stdit - 1) << std::endl;
	*stdit-- = 999;
	std::cout << "*it-- = 999;" << std::endl;
	std::cout << "cout *(it + 1) = " << *(stdit + 1) << std::endl << std::endl;
	std::cout << "now v  : ";
	std::cout << "{";
	for (size_t i = 0; i < stdv.size() - 1; i++)
		std::cout << stdv[i] << ", ";
	std::cout << stdv[stdv.size() - 1];
	std::cout << "}" << std::endl << std::endl;
	std::cout << "it = v.begin() + 0" << std::endl;
	std::cout << "cout *it = " << *stdit << std::endl;
	stdit += 4;
	std::cout << "it += 4" << *stdit << std::endl;
	std::cout << "cout *it = " << *stdit << std::endl;
	stdit -= 4;
	std::cout << "it -= 4" << *stdit << std::endl;
	std::cout << "cout *it = " << *stdit << std::endl << std::endl;
	std::vector<int>::iterator stdit_cpy(stdit);
	std::cout << "iterator it_cpy(it);" << std::endl;
	std::cout << "cout *it_cpy = " << *stdit_cpy << std::endl << std::endl;

	std::cout << CYAN << BOLD << "---==------------------------==---" << RESET << std::endl << std::endl;
}

static void	test_6()
{
	ft::vector<int>	v;
	ft::vector<int>::reverse_iterator	it;

	std::cout << CYAN << BOLD "---==------| REVERSE ITERATOR |------==---" << RESET << std::endl;

	std::cout << CYAN << "--------------- FT ---------------" << RESET << std::endl;
	std::cout << "For a vector : ";
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << "for it = v.rbegin(); it != v.rend(); it++" << std::endl;
	std::cout << "	std::cout << *it << std::endl;" << std::endl;
	for (ft::vector<int>::reverse_iterator it2 = v.rbegin(); it2 != v.rend(); it2++)
		std::cout << *it2 << std::endl;

	it = v.rbegin();
	std::cout << "*it = v.rbegin()" << std::endl;
	std::cout << "cout *it = " << *it << std::endl;
	it += 4;
	std::cout << "it += 4" << std::endl;
	std::cout << "cout *it = " << *it << std::endl;
	it -= 4;
	std::cout << "it -= 4" << std::endl;
	std::cout << "cout *it = " << *it << std::endl << std::endl;

	it = v.rbegin();
	std::cout << "cout *(it + 0) = " << *(it + 0) << std::endl;
	std::cout << "cout *(it + 1) = " << *(it + 1) << std::endl;
	std::cout << "cout *(it + 2) = " << *(it + 2) << std::endl;
	std::cout << "cout *(it + 3) = " << *(it + 3) << std::endl;
	std::cout << "cout *(it + 4) = " << *(it + 4) << std::endl << std::endl;

	std::cout << CYAN << BOLD << "---==------------------------==---" << RESET << std::endl << std::endl;

	std::vector<int>	stdv;
	std::vector<int>::reverse_iterator	stdit;

	std::cout << MAGENTA << "--------------- STD ---------------" << RESET << std::endl;
	std::cout << "For a vector : ";
	stdv.push_back(1);
	stdv.push_back(2);
	stdv.push_back(3);
	stdv.push_back(4);
	stdv.push_back(5);
	std::cout << "{";
	for (size_t i = 0; i < stdv.size() - 1; i++)
		std::cout << stdv[i] << ", ";
	std::cout << stdv[stdv.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << "for it = v.rbegin(); it != v.rend(); it++" << std::endl;
	std::cout << "	std::cout << *it << std::endl;" << std::endl;
	for (std::vector<int>::reverse_iterator stdit2 = stdv.rbegin(); stdit2 != stdv.rend(); stdit2++)
		std::cout << *stdit2 << std::endl;

	stdit = stdv.rbegin();
	std::cout << "*it = v.rbegin()" << std::endl;
	std::cout << "cout *it = " << *stdit << std::endl;
	stdit += 4;
	std::cout << "it += 4" << std::endl;
	std::cout << "cout *it = " << *stdit << std::endl;
	stdit -= 4;
	std::cout << "it -= 4" << std::endl;
	std::cout << "cout *it = " << *stdit << std::endl << std::endl;

	stdit = stdv.rbegin();
	std::cout << "cout *(it + 0) = " << *(stdit + 0) << std::endl;
	std::cout << "cout *(it + 1) = " << *(stdit + 1) << std::endl;
	std::cout << "cout *(it + 2) = " << *(stdit + 2) << std::endl;
	std::cout << "cout *(it + 3) = " << *(stdit + 3) << std::endl;
	std::cout << "cout *(it + 4) = " << *(stdit + 4) << std::endl << std::endl;

	std::cout << CYAN << BOLD << "---==------------------------==---" << RESET << std::endl << std::endl;
}

static void test_7()
{
	std::cout << CYAN << BOLD "---==------| CONSTRUCTORS |------==---" << RESET << std::endl;

	ft::vector<int>		v;
	std::vector<int>	stdv;

	std::cout << CYAN << "---------DEFAULT CONSTRUCTOR----------" << RESET << std::endl;
	std::cout << CYAN << "---------FT----------" << RESET << std::endl;
	std::cout << "ft::vector<int> v;" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	v.push_back(42);
	v.push_back(1);
	v.push_back(56);
	v.push_back(123);
	std::cout << "v.push_back(42);" << std::endl;
	std::cout << "v.push_back(1);" << std::endl;
	std::cout << "v.push_back(56);" << std::endl;
	std::cout << "v.push_back(123);" << std::endl;
	std::cout << MAGENTA << "---------STD---------" << RESET << std::endl;
	std::cout << "std::vector<int> v;" << std::endl;
	std::cout << "v.capacity() = " << stdv.capacity() << std::endl;
	std::cout << "v.size() = " << stdv.size() << std::endl;
	stdv.push_back(42);
	stdv.push_back(1);
	stdv.push_back(56);
	stdv.push_back(123);
	std::cout << "v.push_back(42);" << std::endl;
	std::cout << "v.push_back(1);" << std::endl;
	std::cout << "v.push_back(56);" << std::endl;
	std::cout << "v.push_back(123);" << std::endl;
	std::cout << CYAN << "--------ITERATORS CONSTRUCTOR---------" << RESET << std::endl;
	std::cout << CYAN << "---------FT----------" << RESET << std::endl;
	std::cout << "ft::vector<int> v_it(v.begin(), v.end());" << std::endl;
	ft::vector<int> v_it(v.begin(), v.end());

	std::cout << "for (ft::vector<int>::iterator it = v_it.begin(); it != v_it.end(); it++)" << std::endl;
	std::cout << "    std::cout << *it << std::endl;" << std::endl;
	for (ft::vector<int>::iterator it = v_it.begin(); it != v_it.end(); it++)
		std::cout << *it << std::endl;
	std::cout << MAGENTA << "---------STD---------" << RESET << std::endl;
	std::cout << "std::vector<int> v_it(v.begin(), v.end());" << std::endl;
	std::vector<int> stdv_it(stdv.begin(), stdv.end());

	std::cout << "for (std::vector<int>::iterator it = v_it.begin(); it != v_it.end(); it++)" << std::endl;
	std::cout << "    std::cout << *it << std::endl;" << std::endl;
	for (std::vector<int>::iterator stdit = stdv_it.begin(); stdit != stdv_it.end(); stdit++)
		std::cout << *stdit << std::endl;

	std::cout << CYAN << "----------COPY CONSTRUCTOR------------" << RESET << std::endl;
	std::cout << CYAN << "---------FT----------" << RESET << std::endl;
	std::cout << "ft::vector<int> v_cpy(v_it);" << std::endl;
	ft::vector<int> v_cpy(v_it);

	std::cout << "for (ft::vector<int>::iterator it = v_cpy.begin(); it != v_cpy.end(); it++)" << std::endl;
	std::cout << "std::cout << *it << std::endl;" << std::endl;
	for (ft::vector<int>::iterator it = v_cpy.begin(); it != v_cpy.end(); it++)
		std::cout << *it << std::endl;
	std::cout << MAGENTA << "---------STD---------" << RESET << std::endl;
	std::cout << "std::vector<int> v_cpy(v_it);" << std::endl;
	std::vector<int> stdv_cpy(stdv_it);

	std::cout << "for (std::vector<int>::iterator it = v_cpy.begin(); it != v_cpy.end(); it++)" << std::endl;
	std::cout << "std::cout << *it << std::endl;" << std::endl;
	for (std::vector<int>::iterator it = stdv_cpy.begin(); it != stdv_cpy.end(); it++)
		std::cout << *it << std::endl;

	std::cout << CYAN << "----------FILL CONSTRUCTOR------------" << RESET << std::endl;
	std::cout << CYAN << "---------FT----------" << RESET << std::endl;
	std::cout << "ft::vector<int> v_fill(25, 42);" << std::endl;
	ft::vector<int> v_fill(25, 42);

	std::cout << "for (ft::vector<int>::iterator it = v_fill.begin(); it != v_fill.end(); it++)" << std::endl;
	std::cout << "std::cout << *it << std::endl;" << std::endl;
	for (ft::vector<int>::iterator it = v_fill.begin(); it != v_fill.end(); it++)
		std::cout << *it << std::endl;
	std::cout << MAGENTA << "---------STD---------" << RESET << std::endl;
	std::cout << "std::vector<int> v_fill(25, 42);" << std::endl;
	std::vector<int> stdv_fill(25, 42);

	std::cout << "for (std::vector<int>::iterator it = v_fill.begin(); it != v_fill.end(); it++)" << std::endl;
	std::cout << "std::cout << *it << std::endl;" << std::endl;
	for (std::vector<int>::iterator stdit = stdv_fill.begin(); stdit != stdv_fill.end(); stdit++)
		std::cout << *stdit << std::endl;
}

static void	test_8()
{
	std::cout << CYAN << BOLD "---==------| ASSIGN |------==---" << RESET << std::endl;

	std::cout << CYAN << "---------FT----------" << RESET << std::endl;
	ft::vector<int> v1;
	v1.push_back(42);
	v1.push_back(1);
	v1.push_back(56);
	v1.push_back(123);
	std::cout << "ft::vector<int> v1;" << std::endl;
	std::cout << "For a vector v1 = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	ft::vector<int> v2;
	v2.push_back(420);
	v2.push_back(9999);
	v2.push_back(66666);
	v2.push_back(1234567);
	v2.push_back(507317);
	v2.push_back(2147483640);
	std::cout << "ft::vector<int> v2;" << std::endl;
	std::cout << "For a vector v2 = ";
	std::cout << "{";
	for (size_t i = 0; i < v2.size() - 1; i++)
		std::cout << v2[i] << ", ";
	std::cout << v2[v2.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	v1.assign(v2.begin(), v2.end());
	std::cout << "v1.assign(v2.begin(), v2.end())" << std::endl;
		std::cout << "v1 = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	v2.assign(10, 8);
	std::cout << "v2.assign(10, 8);" << std::endl;
		std::cout << "v2 = ";
	std::cout << "{";
	for (size_t i = 0; i < v2.size() - 1; i++)
		std::cout << v2[i] << ", ";
	std::cout << v2[v2.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << MAGENTA << "---------STD---------" << RESET << std::endl;

	std::vector<int> stdv1;
	stdv1.push_back(42);
	stdv1.push_back(1);
	stdv1.push_back(56);
	stdv1.push_back(123);
	std::cout << "std::vector<int> v1;" << std::endl;
	std::cout << "For a vector v1 = ";
	std::cout << "{";
	for (size_t i = 0; i < stdv1.size() - 1; i++)
		std::cout << stdv1[i] << ", ";
	std::cout << stdv1[stdv1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::vector<int> stdv2;
	stdv2.push_back(420);
	stdv2.push_back(9999);
	stdv2.push_back(66666);
	stdv2.push_back(1234567);
	stdv2.push_back(507317);
	stdv2.push_back(2147483640);
	std::cout << "std::vector<int> v2;" << std::endl;
	std::cout << "For a vector v2 = ";
	std::cout << "{";
	for (size_t i = 0; i < stdv2.size() - 1; i++)
		std::cout << stdv2[i] << ", ";
	std::cout << stdv2[stdv2.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	stdv1.assign(stdv2.begin(), stdv2.end());
	std::cout << "v1.assign(v2.begin(), v2.end())" << std::endl;
		std::cout << "v1 = ";
	std::cout << "{";
	for (size_t i = 0; i < stdv1.size() - 1; i++)
		std::cout << stdv1[i] << ", ";
	std::cout << stdv1[stdv1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	stdv2.assign(10, 8);
	std::cout << "v2.assign(10, 8);" << std::endl;
		std::cout << "v2 = ";
	std::cout << "{";
	for (size_t i = 0; i < stdv2.size() - 1; i++)
		std::cout << stdv2[i] << ", ";
	std::cout << stdv2[stdv2.size() - 1];
	std::cout << "}" << std::endl << std::endl;
}

static void	clearscreen()
{
	for (int i = 0; i < 100; i++)
		std::cout << std::endl;
}

static int	choose_test()
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
				test_2();
				break;
			case 3:
				test_3();
				break;
			case 4:
				test_4();
				break;
			case 5:
				test_5();
				break;
			case 6:
				test_6();
				break;
			case 7:
				test_7();
				break;
			case 8:
				test_8();
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
