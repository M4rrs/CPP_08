#pragma once

#include <iostream>
#include <list>
#include <algorithm>
#include <cmath>

#define CYAN "\033[36;1m"
#define CLEAR "\033[0m"

class Span {
	private:
		Span( void );
		unsigned int _range;
		bool spanCap;
		std::list<int> _span;

	public:
		Span( unsigned int N );
		Span( const Span &copy );
		Span &operator=( const Span &assign );
		~Span( void );

		bool addNumber( int num );
		int shortestSpan( void );
		int longestSpan( void );

		void fillSpan( int *numArr, int size );
		void printSpan( void );
		unsigned int getRange( void ) const;


		class spanFull : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		
		class noSpanFound : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};