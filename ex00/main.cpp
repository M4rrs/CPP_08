/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:01:25 by nnorazma          #+#    #+#             */
/*   Updated: 2023/07/17 14:01:26 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main( void ) {

	std::vector<int> vec;

	//bcs c++98 don't let you use initializer list ????
	vec.push_back(23);
	vec.push_back(9);
	vec.push_back(18);
	vec.push_back(32);
	vec.push_back(49);
	vec.push_back(3);
	vec.push_back(12);

	int size = (int)vec.size();
	
	std::cout << "\n\033[35mCURRENT VECTOR VALUES [";
	for (int i = 0; i < size; i++) {
		std::cout << vec[i];
		if (i != size - 1)
			std::cout << ", ";
	}
	std::cout << "]\033[0m" << std::endl;


	std::cout << "\n================================================\n" << std::endl;
	try {

		std::cout << "To find: [9]\n"
				<< easyfind(vec, 9) << std::endl;
	}
	catch ( notFoundException &e ) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n================================================\n" << std::endl;
	try {

		std::cout << "To find: [49]\n"
				<< easyfind(vec, 49) << std::endl;
	}
	catch ( notFoundException &e ) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n================================================\n" << std::endl;
	try {

		std::cout << "To find: [12]\n"
				<< easyfind(vec, 12) << std::endl;
	}
	catch ( notFoundException &e ) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n================================================\n" << std::endl;
	try {

		std::cout << "To find: [21]\n"
				<< easyfind(vec, 21) << std::endl;
	}
	catch ( notFoundException &e ) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n================================================\n" << std::endl;
	try {

		std::cout << "To find: ['r']\n"
				<< easyfind(vec, 'r') << std::endl;
	}
	catch ( notFoundException &e ) {
		std::cout << e.what() << std::endl;
	}
}