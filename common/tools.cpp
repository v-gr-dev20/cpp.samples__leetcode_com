#include "pch.h"
#include "tools.h"
#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

// Возвращает вектор чисел, полученный из одной строки потока ввода
vector<int> Tools::InputNumbers( istream& iStream )
{
	vector<int> result;
	string numVectorStr;
	getline( iStream, numVectorStr );
	istringstream numVectorStrStream( numVectorStr );
	vector<string> numStrVector(
		istream_iterator<string, char>{ numVectorStrStream }, istream_iterator<string, char>() );
	for( const auto& numberStr : numStrVector ) {
		int num = stoi( numberStr );
		result.push_back( num );
	}
	return result;
}
