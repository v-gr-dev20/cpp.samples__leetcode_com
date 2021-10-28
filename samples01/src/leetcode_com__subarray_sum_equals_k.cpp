#include "pch.h"
#include "leetcode_com__subarray_sum_equals_k.h"
#include "tools.h"
#include "myAssert.h"
#include <iostream>
#include <vector>
#include <string>

namespace {
LeetcodeCom_Problems::CSubarraySumEqualsK problem;
} // namespace

LeetcodeCom_Problems::CSubarraySumEqualsK::CSubarraySumEqualsK()
	: CBaseSample( "leetcode_com__subarray_sum_equals_k" )
{
}

LeetcodeCom_Problems::CSubarraySumEqualsK::~CSubarraySumEqualsK()
{
}

void LeetcodeCom_Problems::CSubarraySumEqualsK::Input( std::istream& iStream, std::ostream& oStream )
{
	oStream << "Input numbers: ";
	nums = Tools::InputNumbers( iStream );

	oStream << "Input sum: ";
	iStream >> k;
}

void LeetcodeCom_Problems::CSubarraySumEqualsK::Report( std::vector<std::string>& reportLines ) const
{
	reportLines.clear();
	reportLines.push_back( "Result: " + std::to_string( result ) );
}

void LeetcodeCom_Problems::CSubarraySumEqualsK::Clean()
{
	nums.clear();
	k = 0;
	result = 0;
}
