#include "pch.h"
#include "leetcode_com__find_minimum_in_rotated_sorted_array_ii.h"
#include "tools.h"
#include "myAssert.h"
#include <iostream>
#include <vector>
#include <string>

namespace {
LeetcodeCom_Problems::CFindMinimumInRotatedSortedArrayII problem;
} // namespace

LeetcodeCom_Problems::CFindMinimumInRotatedSortedArrayII::CFindMinimumInRotatedSortedArrayII()
	: CBaseSample( "leetcode_com__find_minimum_in_rotated_sorted_array_ii" )
{
}

LeetcodeCom_Problems::CFindMinimumInRotatedSortedArrayII::~CFindMinimumInRotatedSortedArrayII()
{
}

void LeetcodeCom_Problems::CFindMinimumInRotatedSortedArrayII::Input( std::istream& iStream, std::ostream& oStream )
{
	oStream << "Input vector: ";
	nums = Tools::InputNumbers(iStream);
}

void LeetcodeCom_Problems::CFindMinimumInRotatedSortedArrayII::Report( std::vector<std::string>& reportLines ) const
{
	reportLines.clear();
	reportLines.push_back( "Result: " + std::to_string( result ) );
}

void LeetcodeCom_Problems::CFindMinimumInRotatedSortedArrayII::Clean()
{
	nums.clear();
	result = 0;
}
