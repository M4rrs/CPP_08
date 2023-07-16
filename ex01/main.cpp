#include "Span.hpp"

int main( void ) {

	std::cout << CYAN << "\n===== CONSTRUCTING =====\n" << CLEAR << std::endl;
	Span thing(5);
	
	std::cout << CYAN << "\n===== ADDING NUMBERS =====\n" << CLEAR << std::endl;
	thing.addNumber(5);
	thing.addNumber(7);
	thing.addNumber(1);
	thing.fillSpan(10);

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

	this2.fillSpan(50);
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
	std::cout << CYAN << "\n===== INSANELY BIG PDF TEST REQUIREMENT?? =====\n" << CLEAR << std::endl;
	Span big(10000);
	std::cout << std::endl;

	int arr[10000];
	for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
		arr[i] = 1 + (rand() % 10000);
	big.fillSpan(10000);
	std::cout << std::endl;

	std::cout << "Big span values:" << std::endl;
	big.printSpan();
	std::cout << std::endl;

	std::cout << "Shortest span: " << thing.shortestSpan() << std::endl;
	std::cout << "Longest span: "<< thing.longestSpan() << std::endl;
	std::cout << std::endl;
	
	std::cout << CYAN << "\n===== DESTRUCTING =====\n" << CLEAR << std::endl;

}