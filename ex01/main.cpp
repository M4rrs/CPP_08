/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:01:41 by nnorazma          #+#    #+#             */
/*   Updated: 2023/07/17 14:01:42 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main( void ) {

	std::cout << CYAN << "\n===== CONSTRUCTING =====\n" << CLEAR << std::endl;
	Span thing(5);
	
	std::cout << CYAN << "\n===== ADDING NUMBERS =====\n" << CLEAR << std::endl;
	thing.addNumber(10);
	thing.addNumber(9);
	thing.addNumber(18);

	int thingArr[5];
	for (int i = 0; i < (int)(sizeof(thingArr)/sizeof(int)); i++)
		thingArr[i] = 1 + (rand() % 10);

	thing.fillSpan(thingArr, (int)(sizeof(thingArr)/sizeof(int)));

	std::cout << CYAN << "\n===== CURRENT SPAN VALUES =====\n" << CLEAR << std::endl;
	thing.printSpan();

	std::cout << CYAN << "\n===== SHORTEST AND LONGEST SPAN =====\n" << CLEAR << std::endl;
	std::cout << "Shortest span: " << thing.shortestSpan() << std::endl;
	std::cout << "Longest span: "<< thing.longestSpan() << std::endl;
	
	std::cout << CYAN << "\n===== SPAN COPY TEST =====\n" << CLEAR << std::endl;
	Span this1(10);
	std::cout << std::endl;

	this1.addNumber(6);
	this1.addNumber(89);
	this1.addNumber(12);
	this1.addNumber(4);
	std::cout << std::endl;

	Span this2(this1);
	std::cout << std::endl;

	std::cout << "Original range: " << this1.getRange() << std::endl;
	std::cout << "Copy range: " << this2.getRange() << std::endl;
	std::cout << std::endl;

	std::cout << "Original span: ";
	this1.printSpan();
	std::cout << "Copy span: ";
	this2.printSpan();
	std::cout << std::endl;

	int arr1[50];
	for (int i = 0; i < (int)(sizeof(arr1)/sizeof(int)); i++)
		arr1[i] = 1 + (rand() % 10000);
	this2.fillSpan(arr1, (int)(sizeof(arr1)/sizeof(int)));
	std::cout << std::endl;

	std::cout << "Original span: ";
	this1.printSpan();
	std::cout << "Copy span: ";
	this2.printSpan();

	std::cout << std::endl;

	{
		std::cout << CYAN << "\n===== PDF SIMPLE TEST =====\n" << CLEAR << std::endl;

		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	}
	/* It looks disgusting, so uncomment if you really want to try*/

	// std::cout << CYAN << "\n===== INSANELY BIG PDF TEST REQUIREMENT?? =====\n" << CLEAR << std::endl;
	// Span big(10000);
	// std::cout << std::endl;

	// int arr[12381];
	// for (int i = 0; i < (int)(sizeof(arr)/sizeof(int)); i++)
	// 	arr[i] = 1 + (rand() % 14023);
	// big.fillSpan(arr, sizeof(arr)/sizeof(int));
	// std::cout << std::endl;

	// std::cout << "Big span values:" << std::endl;
	// big.printSpan();
	// std::cout << std::endl;

	// std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
	// std::cout << "Longest span: "<< big.longestSpan() << std::endl;
	// std::cout << std::endl;
	
	std::cout << CYAN << "\n===== DESTRUCTING =====\n" << CLEAR << std::endl;

}