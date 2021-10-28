#include "pch.h"
#include "leetcode_com__number_of_islands.h"
#include "tools.h"
#include "myAssert.h"
#include <iostream>
#include <vector>
#include <string>

namespace {
LeetcodeCom_Problems::CNumberOfIslands problem;
} // namespace

LeetcodeCom_Problems::CNumberOfIslands::CNumberOfIslands()
	: CBaseSample( "leetcode_com__number_of_islands" )
{
}

LeetcodeCom_Problems::CNumberOfIslands::~CNumberOfIslands()
{
}

void LeetcodeCom_Problems::CNumberOfIslands::Input( std::istream& iStream, std::ostream& oStream)
{
	grid.clear();
	oStream << "Input grid : ";
	while( true ) {
		std::vector<char> inputVector = Tools::Input01s<char>( iStream );
		if( !iStream ) {
			break;
		}
		grid.push_back( inputVector );
	}
}

void LeetcodeCom_Problems::CNumberOfIslands::Report( std::vector<std::string>& reportLines ) const
{
	reportLines.clear();
	reportLines.push_back( "Result: " + std::to_string( result ) );
}

void LeetcodeCom_Problems::CNumberOfIslands::Clean()
{
	grid.clear();
	result = 0;
}