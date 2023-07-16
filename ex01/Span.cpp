#include "Span.hpp"

/*========================= CONSTRUCTOR =========================*/

Span::Span( void ) {
	std::cout << "Default constructor is never used." << std::endl;
}

Span::Span( unsigned int N ) : _range(N) {
	this->_count = 0;
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
	this->_count = assign._count;
	return (*this);
}

/*=========================== PUBLIC ============================*/

// Added comment just for display. Not necessary.
bool Span::addNumber( int num ) {

	try {
		if (this->_count == this->_range)
			throw Span::spanFull();
		else {
			this->_span.push_back(num);
			std::cout << "Added [" << num << "]" << std::endl;
			this->_count++;
		}
		return(0);
	}
	catch (Span::spanFull &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
}

void Span::fillSpan( int numRange ) {
	// std::list<int>::iterator it;

	// for (it = this->_span.begin(); it != this->_span.end(); it++)
	// 	if (addNumber(1 + (rand() % numRange)))
	// 		break;
}

int Span::shortestSpan( void ) {
	std::list<int>::iterator it;
	int temp = 0;
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