/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:44:08 by gkehren           #+#    #+#             */
/*   Updated: 2023/01/11 16:47:06 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "containers/map.hpp"
	#include "containers/stack.hpp"
	#include "containers/vector.hpp"
#endif

#include <sstream>
#include <iomanip>
#include "utils/ANSI_codes.hpp"
#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))


static void	test_1()
{
	ft::vector<int> test;

	std::cout << CYAN << BOLD "---==--------| BASIC |-------==---" << RESET << std::endl;

	std::cout << CYAN << UNDER << "       FT       |       STD      " << RESET << std::endl;

	std::cout << "Empty() = " << std::boolalpha << test.empty() << "  |" << std::endl;

	std::cout << CYAN << "------------PUSH DATA------------" << RESET << std::endl;
	test.push_back(32);
	test.push_back(64);


	std::cout << "Push : " << test[0] << "       |" << std::endl;
	std::cout << "Push : " << test[1] << "       |" << std::endl;

	std::cout << CYAN << "------------INFOS----------------" << RESET << std::endl;
	std::cout << "Size = " <<  test.size() << "        |" << std::endl;
	std::cout << "Capacity = " << test.capacity() << "    |" << std::endl;

	std::cout << CYAN << "------------PUSH DATA------------" << RESET << std::endl;
	test.push_back(128);
	test.push_back(256);
	test.push_back(512);
	std::cout << "Push : " << test[2] << "      |" << std::endl;
	std::cout << "Push : " << test[3] << "      |" << std::endl;
	std::cout << "Push : " << test[4] << "      |" << std::endl;

	std::cout << CYAN << "------------INFOS----------------" << RESET << std::endl;
	std::cout << "Size = " <<  test.size() << "        |" << std::endl;
	std::cout << "Capacity = " << test.capacity() << "    |" << std::endl;
	std::cout << CYAN << BOLD << "---==------------------------==---" << RESET << std::endl << std::endl;
}

static void	test_2()
{
	ft::vector<int> test;

	std::cout << CYAN << BOLD "---==---| ELEMENT ACCESS |---==---" << RESET << std::endl;
	std::cout << "For a vector<int> = {43, 1, 2, 3, 56}" << std::endl;
	std::cout << CYAN << UNDER << "       FT       |       STD      " << RESET << std::endl;

	test.push_back(43);
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(56);

	std::cout << CYAN << "------------TEST AT()------------" << RESET << std::endl;
	std::cout << "at(0) = " << test.at(0) << "      |" << std::endl;
	std::cout << "at(1) = " << test.at(1) << "       |" << std::endl;
	std::cout << "at(3) = " << test.at(3) << "       |" << std::endl;
	std::cout << "at(4) = " << test.at(4) << "      |" << std::endl;
	std::cout << "at(6) = ";
	try
	{
		std::cout << test.at(6);
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

	std::cout << "v.capacity() = " << v.capacity() << "   |" << std::endl;
	v.reserve(100);
	std::cout << "v.reserve(100)" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	v.reserve(1);
	std::cout << "v.reserve(1)" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << CYAN << BOLD << "---==--------------------------==---" << RESET << std::endl << std::endl;
	std::cout << CYAN << BOLD "---==--------| RESIZE |--------==---" << RESET << std::endl;
	std::cout << "For a vector<int> = empty" << std::endl;

	ft::vector<int> v2;

	std::cout << "v.capacity() = " << v2.capacity() << std::endl;
	std::cout << "v.size() = " << v2.size() << std::endl;

	v2.resize(10);
	std::cout << "v.resize(10);" << std::endl;
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << v2[i] << std::endl;
	std::cout << std::endl;

	v2.resize(15, 15);
	std::cout << "v.resize(15, 15);" << std::endl;
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << v2[i] << std::endl;
	std::cout << std::endl;

	v2.resize(3);
	std::cout << "v.resize(3);" << std::endl;
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << v2[i] << std::endl;
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
}

static void	test_6()
{
	ft::vector<int>	v;
	ft::vector<int>::reverse_iterator	it;

	std::cout << CYAN << BOLD "---==------| REVERSE ITERATOR |------==---" << RESET << std::endl;

	std::cout << CYAN << "--------------- FT ---------------" << RESET << std::endl;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	std::cout << "For a vector : ";
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
}

static void test_7()
{
	std::cout << CYAN << BOLD "---==------| CONSTRUCTORS |------==---" << RESET << std::endl;

	ft::vector<int>		v;

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
	std::cout << CYAN << "--------ITERATORS CONSTRUCTOR---------" << RESET << std::endl;
	std::cout << CYAN << "---------FT----------" << RESET << std::endl;
	std::cout << "ft::vector<int> v_it(v.begin(), v.end());" << std::endl;

	ft::vector<int> v_it(v.begin(), v.end());

	std::cout << "for (ft::vector<int>::iterator it = v_it.begin(); it != v_it.end(); it++)" << std::endl;
	std::cout << "    std::cout << *it << std::endl;" << std::endl;
	for (ft::vector<int>::iterator it = v_it.begin(); it != v_it.end(); it++)
		std::cout << *it << std::endl;

	std::cout << CYAN << "----------COPY CONSTRUCTOR------------" << RESET << std::endl;
	std::cout << CYAN << "---------FT----------" << RESET << std::endl;
	std::cout << "ft::vector<int> v_cpy(v_it);" << std::endl;
	ft::vector<int> v_cpy(v_it);

	std::cout << "for (ft::vector<int>::iterator it = v_cpy.begin(); it != v_cpy.end(); it++)" << std::endl;
	std::cout << "std::cout << *it << std::endl;" << std::endl;
	for (ft::vector<int>::iterator it = v_cpy.begin(); it != v_cpy.end(); it++)
		std::cout << *it << std::endl;

	std::cout << CYAN << "----------FILL CONSTRUCTOR------------" << RESET << std::endl;
	std::cout << CYAN << "---------FT----------" << RESET << std::endl;
	std::cout << "ft::vector<int> v_fill(25, 42);" << std::endl;
	ft::vector<int> v_fill(25, 42);

	std::cout << "for (ft::vector<int>::iterator it = v_fill.begin(); it != v_fill.end(); it++)" << std::endl;
	std::cout << "std::cout << *it << std::endl;" << std::endl;
	for (ft::vector<int>::iterator it = v_fill.begin(); it != v_fill.end(); it++)
		std::cout << *it << std::endl;
	std::cout << CYAN << BOLD << "---==------------------------==---" << RESET << std::endl << std::endl;
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
}

static void	test_9()
{
	std::cout << CYAN << BOLD "---==------| INSERT |------==---" << RESET << std::endl;

	ft::vector<std::string>	v1;

	v1.push_back("hey");
	v1.push_back("how");
	v1.push_back("are");
	v1.push_back("you");

	std::cout << CYAN << "---------FT----------" << RESET << std::endl;
	std::cout << "--- Insert at the begining ---" << std::endl << std::endl;
	std::cout << "For a std::string vector v1 = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	v1.insert(v1.begin(), "hello world! ");
	std::cout << "insert(v1.begin(), \"hello world! \")" << std::endl;

	std::cout << "v1 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "--- Insert at the middle ---" << std::endl << std::endl;
	v1.insert(v1.begin() + 3, "hey buddy! ");
	std::cout << "insert(v1.begin(), \"hey buddy! \")" << std::endl;

	std::cout << "v1 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "--- Insert at the end ---" << std::endl << std::endl;
	v1.insert(v1.end(), "Anybody here? ");
	std::cout << "insert(v1.end(), \"Anybody here? \")" << std::endl;

	std::cout << "v1 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "--- Insert in empty vector ---" << std::endl << std::endl;
	ft::vector<std::string> v2;
	std::cout << "For a std::string vector v2 = {}" << std::endl << std::endl;

	v2.insert(v2.begin(), "I'm alone here!");
	std::cout << "insert(v2.begin(), \"I'm alone here!\")" << std::endl;

	std::cout << "v2 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v2.size() - 1; i++)
		std::cout << v2[i] << ", ";
	std::cout << v2[v2.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << CYAN << BOLD << "---==----------------------==---" << RESET << std::endl << std::endl;
}

static void	test_10()
{
	std::cout << CYAN << BOLD "---==------| CLEAR & ERASE |------==---" << RESET << std::endl;
	std::cout << CYAN << "---------FT----------" << RESET << std::endl;
	ft::vector<std::string> hey(20, "hey");

	std::cout << "---- Clear() ----" << std::endl;

	std::cout << "For a vector named hey = {";
	for (ft::vector<std::string>::iterator it = hey.begin(); it + 1 != hey.end(); it++)
		std::cout << *it << ", ";
	if (hey.empty() == false)
		std::cout << hey[hey.size() - 1] << "}" << std::endl;
	else
		std::cout << "}" << std::endl;

	std::cout << "ft::vector<std::string> hey(20, \"hey\");" << std::endl;
	std::cout << "hey.size() = " << hey.size() << std::endl;
	std::cout << "hey.capacity() = " << hey.capacity() << std::endl << std::endl;

	hey.clear();
	std::cout << "hey.clear();" << std::endl;
	std::cout << "hey = {";
	if (hey.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = hey.begin(); it + 1 != hey.end(); it++)
			std::cout << *it << ", ";
		std::cout << hey[hey.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << "hey.size() = " << hey.size() << std::endl;
	std::cout << "hey.capacity() = " << hey.capacity() << std::endl << std::endl;

	std::cout << "---- Erase() ----" << std::endl;

	ft::vector<std::string> hidden(10, "🌙");

	hidden.insert(hidden.begin() + 2, "👾");
	hidden.insert(hidden.begin() + 5, "👾");
	hidden.insert(hidden.begin() + 5, "👾");
	hidden.insert(hidden.begin() + 9, "👾");
	std::cout << "For a string vector hidden = {";
	if (hidden.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = hidden.begin(); it + 1 != hidden.end(); it++)
			std::cout << *it << ", ";
		std::cout << hidden[hidden.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << std::endl;

	hidden.erase(hidden.begin() + 2);
	std::cout << "hidden.erase(hidden.begin() + 2);" << std::endl;
	std::cout << "now hidden = {";
	if (hidden.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = hidden.begin(); it + 1 != hidden.end(); it++)
			std::cout << *it << ", ";
		std::cout << hidden[hidden.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << std::endl;

	hidden.erase(hidden.begin() + 8);
	std::cout << "hidden.erase(hidden.begin() + 8);" << std::endl;
	std::cout << "now hidden = {";
	if (hidden.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = hidden.begin(); it + 1 != hidden.end(); it++)
			std::cout << *it << ", ";
		std::cout << hidden[hidden.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << std::endl;

	hidden.erase(hidden.begin() + 4, hidden.begin() + 6);
	std::cout << "hidden.erase(hidden.begin() + 4, hidden.begin() + 6);" << std::endl;
	std::cout << "now hidden = {";
	if (hidden.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = hidden.begin(); it + 1 != hidden.end(); it++)
			std::cout << *it << ", ";
		std::cout << hidden[hidden.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << std::endl;

	hidden.erase(hidden.begin(), hidden.end());
	std::cout << "hidden.erase(hidden.begin(), hidden.end());" << std::endl;
	std::cout << "now hidden = {";
	if (hidden.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = hidden.begin(); it + 1 != hidden.end(); it++)
			std::cout << *it << ", ";
		std::cout << hidden[hidden.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << BOLD << "---==-----------------------------==---" << RESET << std::endl << std::endl;
}

static void	test_11()
{
	std::cout << CYAN << BOLD "---==------| SWAP |------==---" << RESET << std::endl;
	std::cout << CYAN << "---------FT----------" << RESET << std::endl;
	ft::vector<std::string> argent(10, "💿");
	std::cout << "For a string vector argent = {";
	if (argent.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = argent.begin(); it + 1 != argent.end(); it++)
			std::cout << *it << ", ";
		std::cout << argent[argent.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	ft::vector<std::string> gold(5, "📀");
	std::cout << "For a string vector gold = {";
	if (gold.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = gold.begin(); it + 1 != gold.end(); it++)
			std::cout << *it << ", ";
		std::cout << gold[gold.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	gold.swap(argent);
	std::cout << "gold.swap(argent);" << std::endl;

	std::cout << "now argent = {";
	if (argent.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = argent.begin(); it + 1 != argent.end(); it++)
			std::cout << *it << ", ";
		std::cout << argent[argent.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	std::cout << "now argent = {";
	if (gold.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = gold.begin(); it + 1 != gold.end(); it++)
			std::cout << *it << ", ";
		std::cout << gold[gold.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	gold.swap(argent);
	std::cout << "gold.swap(argent);" << std::endl;

	std::cout << "now argent = {";
	if (argent.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = argent.begin(); it + 1 != argent.end(); it++)
			std::cout << *it << ", ";
		std::cout << argent[argent.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	std::cout << "now argent = {";
	if (gold.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = gold.begin(); it + 1 != gold.end(); it++)
			std::cout << *it << ", ";
		std::cout << gold[gold.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	argent.swap(gold);
	std::cout << "argent.swap(gold);" << std::endl;

	std::cout << "now argent = {";
	if (argent.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = argent.begin(); it + 1 != argent.end(); it++)
			std::cout << *it << ", ";
		std::cout << argent[argent.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	std::cout << "now argent = {";
	if (gold.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = gold.begin(); it + 1 != gold.end(); it++)
			std::cout << *it << ", ";
		std::cout << gold[gold.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	ft::vector<std::string>	empty_one;
	ft::vector<std::string>	empty_two;

	std::cout << "For a string vector empty_one = {";
	if (empty_one.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = empty_one.begin(); it + 1 != empty_one.end(); it++)
			std::cout << *it << ", ";
		std::cout << empty_one[empty_one.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	std::cout << "For a string vector empty_two = {";
	if (empty_two.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = empty_two.begin(); it + 1 != empty_two.end(); it++)
			std::cout << *it << ", ";
		std::cout << empty_two[empty_two.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	empty_one.swap(empty_two);
	std::cout << "empty_one.swap(empty_two);" << std::endl;

	std::cout << "now empty_one = {";
	if (empty_one.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = empty_one.begin(); it + 1 != empty_one.end(); it++)
			std::cout << *it << ", ";
		std::cout << empty_one[empty_one.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	std::cout << "now empty_two = {";
	if (empty_two.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = empty_two.begin(); it + 1 != empty_two.end(); it++)
			std::cout << *it << ", ";
		std::cout << empty_two[empty_two.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl << std::endl;

	std::cout << CYAN << BOLD << "---==--------------------==---" << RESET << std::endl << std::endl;
}

static void	test_12()
{
	std::cout << CYAN << BOLD "---==------| Non-member operators |------==---" << RESET << std::endl;
	std::cout << CYAN << "---------FT-----------" << RESET << std::endl;
	ft::vector<std::string>	v_str1;

	v_str1.push_back("🎥");
	v_str1.push_back("🎬");
	v_str1.push_back("📺");
	v_str1.push_back("📷");
	v_str1.push_back("📼");

	ft::vector<std::string>	v_str2(v_str1);

	ft::vector<std::string>	v_str3;

	v_str3.push_back("💼");
	v_str3.push_back("📁");
	v_str3.push_back("📊");
	v_str3.push_back("📈");
	v_str3.push_back("📉");

	std::cout << "{";
	for (size_t i = 0; i < v_str1.size() - 1; i++)
		std::cout << v_str1[i] << ", ";
	std::cout << v_str1[v_str1.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << "{";
	for (size_t i = 0; i < v_str2.size() - 1; i++)
		std::cout << v_str2[i] << ", ";
	std::cout << v_str2[v_str2.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << "{";
	for (size_t i = 0; i < v_str3.size() - 1; i++)
		std::cout << v_str3[i] << ", ";
	std::cout << v_str3[v_str3.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << "v_str1 == v_str1 : " << std::boolalpha << (v_str1 == v_str1) << std::endl << std::endl;

	std::cout << "v_str1 == v_str2 : " << std::boolalpha << (v_str1 == v_str2) << std::endl;
	std::cout << "v_str1 != v_str2 : " << std::boolalpha << (v_str1 != v_str2) << std::endl << std::endl;

	std::cout << "v_str1 == v_str3 : " << std::boolalpha << (v_str1 == v_str3) << std::endl;
	std::cout << "v_str1 != v_str3 : " << std::boolalpha << (v_str1 != v_str3) << std::endl << std::endl;

	std::cout << CYAN << "--- SUPERIOR & EQUAL-SUPERIOR ---" << RESET << std::endl;
	ft::vector<int>	v_nums1;

	v_nums1.push_back(0);
	v_nums1.push_back(1);
	v_nums1.push_back(10);
	v_nums1.push_back(11);
	v_nums1.push_back(100);
	v_nums1.push_back(101);
	v_nums1.push_back(110);
	v_nums1.push_back(111);

	ft::vector<int>	v_nums2(v_nums1);

	v_nums2.push_back(1000);

	std::cout << "{";
	for (size_t i = 0; i < v_nums1.size() - 1; i++)
		std::cout << v_nums1[i] << ", ";
	std::cout << v_nums1[v_nums1.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << "{";
	for (size_t i = 0; i < v_nums2.size() - 1; i++)
		std::cout << v_nums2[i] << ", ";
	std::cout << v_nums2[v_nums2.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << "v_nums1 < v_nums1 = " << (v_nums1 < v_nums1) << std::endl;
	std::cout << "v_nums1 < v_nums2 = " << (v_nums1 < v_nums2) << std::endl;
	std::cout << "v_nums2 < v_nums1 = " << (v_nums2 < v_nums1) << std::endl;
	std::cout << "v_nums1 <= v_nums1 = " << (v_nums1 <= v_nums1) << std::endl;
	std::cout << "v_nums1 <= v_nums2 = " << (v_nums1 <= v_nums2) << std::endl;
	std::cout << "v_nums2 <= v_nums1 = " << (v_nums2 <= v_nums1) << std::endl << std::endl;

	std::cout << CYAN << "--- INFERIOR & EQUAL-INFERIOR ---" << RESET << std::endl << std::endl;

	std::cout << "v_nums1 > v_nums1 = " << (v_nums1 > v_nums1) << std::endl;
	std::cout << "v_nums1 > v_nums2 = " << (v_nums1 > v_nums2) << std::endl;
	std::cout << "v_nums2 > v_nums1 = " << (v_nums2 > v_nums1) << std::endl;
	std::cout << "v_nums1 >= v_nums1 = " << (v_nums1 >= v_nums1) << std::endl;
	std::cout << "v_nums1 >= v_nums2 = " << (v_nums1 >= v_nums2) << std::endl;
	std::cout << "v_nums2 >= v_nums1 = " << (v_nums2 >= v_nums1) << std::endl << std::endl;

	std::cout << CYAN << BOLD << "---==------------------------------------==---" << RESET << std::endl << std::endl;
}

static void	test_13()
{
	std::cout << CYAN << BOLD "---==------| Non-member SWAP |------==---" << RESET << std::endl;
	std::cout << CYAN << "---------FT-----------" << RESET << std::endl;

	ft::vector<int> v_nums_a(10, 10);
	ft::vector<int> v_nums_b(10, 50);

	std::cout << "a = {";
	for (size_t i = 0; i < v_nums_a.size() - 1; i++)
		std::cout << v_nums_a[i] << ", ";
	std::cout << v_nums_a[v_nums_a.size() - 1];
	std::cout << "}" << std::endl;
	std::cout << "b = {";
	for (size_t i = 0; i < v_nums_b.size() - 1; i++)
		std::cout << v_nums_b[i] << ", ";
	std::cout << v_nums_b[v_nums_b.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl << "swap(a, b);" << std::endl << std::endl;
	swap(v_nums_a, v_nums_b);

	std::cout << "a = {";
	for (size_t i = 0; i < v_nums_a.size() - 1; i++)
		std::cout << v_nums_a[i] << ", ";
	std::cout << v_nums_a[v_nums_a.size() - 1];
	std::cout << "}" << std::endl;
	std::cout << "b = {";
	for (size_t i = 0; i < v_nums_b.size() - 1; i++)
		std::cout << v_nums_b[i] << ", ";
	std::cout << v_nums_b[v_nums_b.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << CYAN << BOLD << "---==------------------------------------==---" << RESET << std::endl << std::endl;
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
				test_9();
				break;
			case 10:
				test_10();
				break;
			case 11:
				test_11();
				break;
			case 12:
				test_12();
				break;
			case 13:
				test_13();
				break;
			case 42:
				return;
			default:
				std::cout << "Error: please choose a test again" << std::endl;
				break;
		}
	}
}


int main(int argc, char** argv) {
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
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

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

	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}
	ft::vector<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push_back(letter);
	for (ft::vector<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	main_vector();
	return (0);
}
