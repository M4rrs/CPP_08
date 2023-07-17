/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:01:46 by nnorazma          #+#    #+#             */
/*   Updated: 2023/07/17 14:01:47 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*========================= CONSTRUCTOR =========================*/

Span::Span( void ) {
	std::cout << "Default constructor is never used." << std::endl;
}

Span::Span( unsigned int N ) : _range(N) {
	this->spanCap = 0;
	std::cout << "Constructed Span of size: " << N << std::endl;
}

/*========================= CONSTRUCTOR =========================*/

Span::~Span( void ) {
	std::cout << "Span destructed." << std::endl;
}

/*====================== COPY CONSTRUCTOR =======================*/

Span::Span( const Span &copy ) {
	*this = copy;
	std::cout << "Span cloned" << std::endl;
}

/*===================== OVERLOADED OPERATOR =====================*/

Span &Span::operator=( const Span &assign ) {
	this->_span.assign(assign._span.begin(), assign._span.end());
	this->_range = assign._range;
	this->spanCap = assign.spanCap;
	return (*this);
}

/*=========================== PUBLIC ============================*/

// Added comment just for display. Not necessary.
bool Span::addNumber( int num ) {

	try {
		if (this->_span.size() == this->_range)
			throw Span::spanFull();
		else {
			this->_span.push_back(num);
			std::cout << "Added [" << num << "]" << std::endl;
		}
		return(0);
	}
	catch (Span::spanFull &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
}

void Span::fillSpan( int *numArr, int size ) {

	if (this->_range < (this->_span.size() + size)) {
		size = this->_range - this->_span.size();
		this->spanCap = 1;
	}

	this->_span.insert(this->_span.end(), numArr, numArr + size);
	try {
	if (spanCap)
		throw Span::spanFull();
	}
	catch (Span::spanFull &e) {
		std::cout << e.what() << std::endl;
	}
}

int Span::shortestSpan( void ) {
	std::list<int>::iterator it;
	int temp = abs(*this->_span.begin() - *std::next(this->_span.begin()));
	int result = abs(*this->_span.begin() - *std::next(this->_span.begin()));

	if (this->_span.max_size() == 0 || this->_span.max_size() == 1 || this->_span.empty())
		throw Span::noSpanFound();

	for (it = this->_span.begin(); it != this->_span.end(); it++) {
		if (std::next(it) == this->_span.end())
			break;
		temp = abs(*it - *std::next(it));
		if (temp < result)
			result = temp;
	}
	return (result);
}

int Span::longestSpan( void ) {
	std::list<int>::iterator it;

	int temp = 0;
	int result = abs(*this->_span.begin() - *std::next(this->_span.begin()));

	if (this->_span.max_size() == 0 || this->_span.max_size() == 1 || this->_span.empty())
		throw Span::noSpanFound();

	for (it = this->_span.begin(); it != this->_span.end(); it++) {
		if (std::next(it) == this->_span.end())
			break;
		temp = abs(*it - *std::next(it));
		if (temp > result)
			result = temp;
	}
	return (result);
}

void Span::printSpan( void ) {

	std::list<int>::iterator it;

	std::cout << "[ ";
	for (it = this->_span.begin(); it != this->_span.end(); it++) {
		std::cout << *it;
		if (std::next(it) != this->_span.end())
			std::cout << ", ";
	}
	std::cout << " ]" << std::endl;
}

unsigned int Span::getRange( void ) const {
	return (this->_range);
}

/*========================== EXCEPTION ===========================*/

const char *Span::spanFull::what( void ) const throw() {
	return ("\033[31mSpan full. Unable to assign new elements.\033[0m");
}

const char *Span::noSpanFound::what( void ) const throw() {
	return ("No span can be found");
}