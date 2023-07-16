#pragma once

#include <iostream>
#include <list>
#include <algorithm>
#include <cmath>

class Span {
	private:
		Span( void );
		std::list<int> _span;

	public:
		Span( unsigned int N );
		Span( const Span &copy );
		Span &operator=( const Span &assign );
		~Span( void );

		bool addNumber( int num );
		int shortestSpan( void );
		int longestSpan( void );

		void fillSpan( int numRange );

		class spanFull : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		
		class noSpanFound : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};