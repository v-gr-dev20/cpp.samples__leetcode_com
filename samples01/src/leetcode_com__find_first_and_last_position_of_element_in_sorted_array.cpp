#include "pch.h"
#include "leetcode_com__find_first_and_last_position_of_element_in_sorted_array.h"
#include "tools.h"
#include "myAssert.h"
#include <iostream>
#include <vector>
#include <string>

namespace {
LeetcodeCom_Problems::CFindFirstAndLastPositionOfElementInSortedArray problem;
} // namespace

LeetcodeCom_Problems::CFindFirstAndLastPositionOfElementInSortedArray::CFindFirstAndLastPositionOfElementInSortedArray()
	: CBaseSample( "leetcode_com__find_first_and_last_position_of_element_in_sorted_array" )
{
}

LeetcodeCom_Problems::CFindFirstAndLastPositionOfElementInSortedArray::~CFindFirstAndLastPositionOfElementInSortedArray()
{
}

void LeetcodeCom_Problems::CFindFirstAndLastPositionOfElementInSortedArray::Input( std::istream& iStream, std::ostream& oStream )
{
	oStream << "Input numbers: ";
	nums = Tools::InputNumbers( iStream );
	oStream << "Input target: ";
	iStream >> target;
}

void LeetcodeCom_Problems::CFindFirstAndLastPositionOfElementInSortedArray::Report( std::vector<std::string>& reportLines ) const
{
	reportLines.clear();
	std::ostringstream resultStream;
	bool isBegin = true;
	for( const auto& item : result ) {
		resultStream << ( isBegin ? "" : ", " ) << std::to_string( item );
		isBegin = false;
	}
	reportLines.push_back( "Result: { " + resultStream.str() + " }" );
}

void LeetcodeCom_Problems::CFindFirstAndLastPositionOfElementInSortedArray::Clean()
{
	nums.clear();
	int target;
	result.clear();
}