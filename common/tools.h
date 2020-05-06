#pragma once

#include "myAssert.h"
#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>

// Вспомогательные инструменты
///////////////////////////////////////////////////////////////////////////////

namespace Tools {
	// Возвращает вектор чисел, полученный из потока ввода
	std::vector<int> InputNumbers( std::istream& iStream );
	// Возвращает вектор нулей-единиц, полученный из потока ввода
	template<typename T>
	std::vector<T> Input01s( std::istream& iStream );
}

namespace {
template<typename T>
T input01( char digit )
{
	assert( '0' == digit || '1' == digit );
	return stoi( std::string( 1, digit ) );
}
template<>
char input01<char>( char digit )
{
	assert( '0' == digit || '1' == digit );
	return digit;
}
}

template<typename T>
std::vector<T> Tools::Input01s( std::istream& iStream )
{
	std::vector<T> result;
	std::string numVectorStr;
	getline( iStream, numVectorStr );
	std::istringstream numVectorStrStream( numVectorStr );
	std::vector<std::string> numStrVector(
		std::istream_iterator<std::string>{ numVectorStrStream }, std::istream_iterator<std::string>() );
	for( const auto& digitStr : numStrVector ) {
		for( auto digit: digitStr ) {
			result.push_back( input01<T>( digit ) );
		};
	}
	return result;
}
