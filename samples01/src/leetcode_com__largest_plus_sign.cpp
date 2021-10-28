#include "pch.h"
#include "leetcode_com__largest_plus_sign.h"
#include "tools.h"
#include "myAssert.h"
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

namespace {
LeetcodeCom_Problems::CLargestPlusSign problem;
} // namespace

LeetcodeCom_Problems::CLargestPlusSign::CLargestPlusSign()
	: CBaseSample( "leetcode_com__largest_plus_sign" )
{
}

LeetcodeCom_Problems::CLargestPlusSign::~CLargestPlusSign()
{
}

void LeetcodeCom_Problems::CLargestPlusSign::Input( std::istream& iStream, std::ostream& oStream )
{
	mines.clear();
	std::string getLine;
	oStream << "Input n : ";
	iStream >> n;
	std::getline( iStream, getLine );
	oStream << "Input pairs : ";
	while( true ) {
		std::vector<int> inputVector = Tools::InputNumbers( iStream );
		if( !iStream ) {
			break;
		}
		mines.push_back( inputVector );
	};
}

void LeetcodeCom_Problems::CLargestPlusSign::Report( std::vector<std::string>& reportLines ) const
{
	reportLines.clear();
	reportLines.push_back( "Result: " + std::to_string( result ) );
}
