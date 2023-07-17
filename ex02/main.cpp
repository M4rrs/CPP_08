/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:28:08 by nnorazma          #+#    #+#             */
/*   Updated: 2023/07/17 19:45:51 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <deque>

int main()
{
	std::cout << CYAN << "\n==================================\n" << CLEAR << std::endl;
	MutantStack<int> mstack;
	std::cout << CYAN << "\n==================================\n" << CLEAR << std::endl;

	std::cout << "Pushed 2 numbers." << std::endl;
	mstack.push(5);
	mstack.push(17);

	std::cout << "Top of mstack: ";
	std::cout << mstack.top() << std::endl;

	std::cout << "Stack popped." << std::endl;
	mstack.pop();

	std::cout << "Size of mstack: ";
	std::cout << mstack.size() << std::endl;

	std::cout << "Pushed 4 numbers." << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "Mstack begin: " << *it << std::endl;
	++it;
	--it;
	std::cout << "Mstack end: " << *ite << std::endl;
	std::cout << std::endl;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << CYAN << "\n==================================\n" << CLEAR << std::endl;
	std::cout << "Test with another container type." << std::endl;
	std::deque<int> deq;

	std::cout << "Push_front 2 numbers." << std::endl;
	deq.push_back(5);
	deq.push_back(17);

	std::cout << "Top of deq: ";
	std::cout << deq[0] << std::endl;

	std::cout << "Deque popped." << std::endl;
	deq.pop_back();

	std::cout << "Size of deq: ";
	std::cout << deq.size() << std::endl;

	std::cout << "push_back 4 numbers." << std::endl;
	deq.push_back(3);
	deq.push_back(5);
	deq.push_back(737);
	deq.push_back(0);

	std::deque<int>::iterator deqIt = deq.begin();
	std::deque<int>::iterator deqIte = deq.end();

	std::cout << "Deq begin: " << *deqIt << std::endl;
	++it;
	--it;
	std::cout << "Deq end: " << *deqIte << std::endl;
	std::cout << std::endl;

	while (deqIt != deqIte)
	{
		std::cout << *deqIt << std::endl;
		++deqIt;
	}

	std::cout << CYAN << "\n==================================\n" << CLEAR << std::endl;
	//why tf did they include this???
	std::stack<int> s(mstack);
	std::cout << "I can't iterate through a normal stack but whatever heres a basic test." << std::endl;
	std::cout << "Top of stack: " << s.top() << std::endl;
	
	s.pop();
	std::cout << "Next value (popped): " << s.top() << std::endl;
	std::cout << CYAN << "\n==================================\n" << CLEAR << std::endl;

	return 0;
}