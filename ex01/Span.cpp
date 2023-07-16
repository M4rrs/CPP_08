#include "Span.hpp"

/*========================= CONSTRUCTOR =========================*/

Span::Span( void ) {
	std::cout << "Default constructor is never used." << std::endl;
}

Span::Span( unsigned int N ) : _span(N) {
	std::cout << "Constructed Span of size: " << N << std::endl;
}

/*====================== COPY CONSTRUCTOR =======================*/

Span::Span( const Span &copy ) : _span(copy._span.max_size()) {
	*this = copy;
	std::cout << "Span cloned" << std::endl;
}

/*===================== OVERLOADED OPERATOR =====================*/

Span &Span::operator=( const Span &assign ) {
	std::copy(assign._span.begin(), assign._span.end(), this->_span.begin());
}

/*=========================== PUBLIC ============================*/


bool Span::addNumber( int num ) {

	std::list<int>::iterator last = std::prev(this->_span.end());
	std::list<int>::iterator next = std::next(last);

	try {
		if (next == this->_span.end())
			throw Span::spanFull();
		else
			this->_span.push_back(num);
		return 0;
	}
	catch (Span::spanFull &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
}

int Span::shortestSpan( void ) {
	std::list<int>::iterator it;
	int temp = 0;
	int result = abs(*this->_span.begin() - *std::next(this->_span.begin()));

	if (this->_span.max_size() == 0 || this->_span.max_size() == 1 || this->_span.empty())
		throw Span::noSpanFound();

	for (it = this->_span.begin(); it != this->_span.end(); it++) {
		if (std::next(it) == this->_span.end())
			return result;
		temp = abs(*it - *std::next(it));
		if (temp > result)
			result = temp;
	}
}

int Span::longestSpan( void ) {
	std::list<int>::iterator it;

	int temp = 0;
	int result = abs(*this->_span.begin() - *std::next(this->_span.begin()));

	if (this->_span.max_size() == 0 || this->_span.max_size() == 1 || this->_span.empty())
		throw Span::noSpanFound();

	for (it = this->_span.begin(); it != this->_span.end(); it++) {
		if (std::next(it) == this->_span.end())
			return result;
		temp = abs(*it - *std::next(it));
		if (temp < result)
			result = temp;
	}
}

void Span::fillSpan( int numRange ) {
	std::list<int>::iterator it;

	for (it = this->_span.begin(); it != this->_span.end(); it++)
		if (addNumber(1 + (rand() % numRange)))
			break;
}

/*========================== EXCEPTION ===========================*/

const char *Span::spanFull::what( void ) const throw() {
	return ("Span full. Unable to assign new elements.");
}

const char *Span::noSpanFound::what( void ) const throw() {
	return ("No span can be found");
}