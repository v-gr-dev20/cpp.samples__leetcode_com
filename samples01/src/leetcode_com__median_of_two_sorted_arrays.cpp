#include "pch.h"
#include "leetcode_com__median_of_two_sorted_arrays.h"
#include "tools.h"
#include "myAssert.h"
#include <iostream>
#include <vector>
#include <string>

namespace {
LeetcodeCom_Problems::CMedianOfTwoSortedArrays problem;
} // namespace

LeetcodeCom_Problems::CMedianOfTwoSortedArrays::CMedianOfTwoSortedArrays()
	: CBaseSample( "leetcode_com__median_of_two_sorted_arrays" )
{
}

LeetcodeCom_Problems::CMedianOfTwoSortedArrays::~CMedianOfTwoSortedArrays()
{
}

void LeetcodeCom_Problems::CMedianOfTwoSortedArrays::Input( std::istream& iStream, std::ostream& oStream )
{
	oStream << "Input vector1: ";
	nums1 = Tools::InputNumbers( iStream );
	
	oStream << "Input vector2: ";
	nums2 = Tools::InputNumbers( iStream );
}

void LeetcodeCom_Problems::CMedianOfTwoSortedArrays::Report( std::vector<std::string>& reportLines ) const
{
	reportLines.clear();
	reportLines.push_back( "Result: " + std::to_string( result ) );
}

void LeetcodeCom_Problems::CMedianOfTwoSortedArrays::Clean()
{
	nums1.clear();
	nums2.clear();
	result = 0;
}