/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:28:12 by nnorazma          #+#    #+#             */
/*   Updated: 2023/07/17 19:28:31 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

#define CYAN "\033[36m"
#define CLEAR "\033[0m"

template<typename T> class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack( void ) {
			std::cout << "MutantStack constructed." << std::endl;
		}

		MutantStack( const MutantStack &copy ) {
			*this = copy;
			std::cout << "MutantStack cloned." << std::endl;
		}

		MutantStack<T> &operator=( const MutantStack<T> &assign ) {
			this = assign;
			return (*this);
		}

		~MutantStack( void ) {
			std::cout << "MutantStack destructed." << std::endl;
		}

		/*
		Stack has an underlying container, default is deque.
		But we can set it to any other container we want.
		So we can't access the stack with iterators, but we can
		access the underlying containers.
		?????
		*/
		iterator begin( void ) {
			return (this->c.begin());
		}

		iterator end( void ) {
			return (this->c.end());
		}
};