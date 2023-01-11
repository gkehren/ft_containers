#include "../ft_containers.hpp"
#include "../stack.hpp"
#include "../vector.hpp"
#include "../map.hpp"
#include "../set.hpp"
#include <stack>
#include <map>
#include <vector>
#include <set>

class time_test
{
	private:
		std::clock_t _start;

	public:
		time_test() {
			_start = 0;
		}

		time_test(const time_test &other) {
			this->_start = other._start;
		}

		time_test &operator=(const time_test &rhs) {
			this->_start = rhs._start;
			return (*this);
		}

		~time_test() {}

		void start() {
			this->_start = std::clock();
		}

		std::clock_t stop() {
			return (std::clock() - this->_start);
		}
};

template <typename vector_type>
std::clock_t vector_insert(size_t count, vector_type vector)
{
	time_test	t;
	int			tmp;

	t.start();
	tmp = 0;
	for (size_t i = 0; i < count; i++)
	{
		vector.push_back(i);
		tmp = vector[i];
	}
	vector_type new_vec(vector);
	(void)tmp;
	vector.erase(vector.begin(), vector.end());
	return (t.stop());
}

template <typename stack_type>
std::clock_t stack_insert(size_t count, stack_type stack)
{
	time_test t;
	t.start();

	int tmp = 0;

	for (size_t i = 0; i < count; i++)
	{
		stack.push(i);
	}
	{
		stack_type new_st(stack);
	}

	for (size_t i = 0; i < count; i++)
	{
		tmp = stack.top();
		stack.pop();
	}
	(void)tmp;
	return (t.stop());
}

template <typename map_type>
std::clock_t map_insert(size_t count, map_type map)
{
	time_test t;
	t.start();

	for (size_t i = 0; i < count; i++)
	{
		map[i] = true;
		map.find(i);
	}
	{
		map_type new_map(map);
	}

	return (t.stop());
}

template <typename set_type>
std::clock_t set_insert(size_t count, set_type set)
{
	time_test t;
	t.start();

	for (size_t i = 0; i < count; i++)
	{
		set.insert(i);
		set.find(i);
	}
	{
		set_type new_set(set);
	}

	return (t.stop());
}

void	time_test_vector(int n) {
	if (!n)
		std::cout << MAGENTA << "------------------------------------";
	std::cout << MAGENTA << "\n\tTIME TEST:" << RESET <<std::endl;
	if (!n)
		std::cout << MAGENTA << "------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	if (!n)
		std::cout << BLUE << "Vector time:" << RESET << std::endl;
	std::clock_t std;
	std::clock_t ft;

	std::vector<int> sv1;
	ft::vector<int> mv1;

	std = vector_insert(2000, sv1);
	std::cout << "Std: " << std << std::endl;

	ft = vector_insert(2000, mv1);
	std::cout << "Ft : " << ft << std::endl;

	std::cout << "Our vector is " << GREEN << (double)ft / (double)std << RESET << " times slower." << std::endl;

	std::cout << "\nTime test:\t\t\t";
	if (((double)ft / (double)std) < 20.0)
		std::cout << SUCS << std::endl;
	else
		std::cout << FAIL << std::endl;
	std::cout << std::endl;
	return ;
}

void time_test_stack(int n) {
	if (n)
		std::cout << MAGENTA << "\n\tTIME TEST:" << RESET << std::endl << std::endl;
	if (!n)
		std::cout << BLUE << "Stack time" << RESET << std::endl;

	std::clock_t std;
	std::clock_t ft;

	std::stack<int> st1;
	ft::stack<int> ms1;

	std = stack_insert(2000, st1);
	std::cout << "Std: " << std << std::endl;

	ft = stack_insert(2000, ms1);
	std::cout << "Ft : " << ft << std::endl;

	std::cout << "Our stack is " << GREEN << (double)ft / (double)std << RESET << " times slower." << std::endl;

	std::cout << "\nTime test:\t\t\t";
	if (((double)ft / (double)std) < 20.0)
		std::cout << SUCS << std::endl;
	else
		std::cout << FAIL << std::endl;
	std::cout << std::endl;
}

void time_test_map(int n) {
	if (n)
		std::cout << MAGENTA << "\n\tTIME TEST:" << RESET << std::endl << std::endl;
	if (!n)
		std::cout << BLUE << "Map time" << RESET << std::endl;

	std::clock_t std;
	std::clock_t ft;

	std::map<int, bool> sm1;
	ft::map<int, bool> m1;

	std = map_insert(200000, sm1);
	std::cout << "Std: " << std << std::endl;

	ft = map_insert(200000, m1);
	std::cout << "Ft : " << ft << std::endl;

	std::cout << "Our map is " << GREEN << (double)ft / (double)std << RESET << " times slower." << std::endl;

	std::cout << "\nTime test:\t\t\t";
	if (((double)ft / (double)std) < 20.0)
		std::cout << SUCS << std::endl;
	else
		std::cout << FAIL << std::endl;
	std::cout << std::endl;
}

void	time_test_set(int n)
{
	if (n)
		std::cout << MAGENTA << "\n\tTIME TEST:" << RESET << std::endl << std::endl;
	if (!n)
		std::cout << BLUE << "Set time" << RESET << std::endl;

	std::clock_t std;
	std::clock_t ft;

	std::set<int> sm1;
	ft::set<int> m1;

	std = set_insert(200000, sm1);
	std::cout << "Std: " << std << std::endl;

	ft = set_insert(200000, m1);
	std::cout << "Ft : " << ft << std::endl;

	std::cout << "Our map is " << GREEN << (double)ft / (double)std << RESET << " times slower." << std::endl;

	std::cout << "\nTime test:\t\t\t";
	if (((double)ft / (double)std) < 20.0)
		std::cout << SUCS << std::endl;
	else
		std::cout << FAIL << std::endl;
	std::cout << std::endl;
}
