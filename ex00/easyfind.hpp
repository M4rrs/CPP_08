/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:01:19 by nnorazma          #+#    #+#             */
/*   Updated: 2023/07/24 16:15:46 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

class notFoundException : std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Ocurrence not found.");
		}
};

template <typename T> int easyfind( T par1, int par2 ) {

	std::vector<int>::iterator it;

	it = std::find(par1.begin(), par1.end(), par2);
	if (it == par1.end())
		throw notFoundException();
	return (it - par1.begin());
}
