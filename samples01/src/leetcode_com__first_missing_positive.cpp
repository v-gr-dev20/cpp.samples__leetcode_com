#include "pch.h"
#include "leetcode_com__first_missing_positive.h"
#include "tools.h"
#include "myAssert.h"
#include <iostream>
#include <vector>
#include <string>

namespace {
LeetcodeCom_Problems::CFirstMissingPositive problem;
} // namespace

LeetcodeCom_Problems::CFirstMissingPositive::CFirstMissingPositive()
	: CBaseSample( "leetcode_com__first_missing_positive" )
{
}

LeetcodeCom_Problems::CFirstMissingPositive::~CFirstMissingPositive()
{
}

void LeetcodeCom_Problems::CFirstMissingPositive::Input( std::istream& iStream, std::ostream& oStream )
{
	oStream << "Input numbers: ";
	nums = Tools::InputNumbers( iStream );
}

void LeetcodeCom_Problems::CFirstMissingPositive::Report( std::vector<std::string>& reportLines ) const
{
	reportLines.clear();
	reportLines.push_back( "Result: " + std::to_string( result ) );
}

void LeetcodeCom_Problems::CFirstMissingPositive::Clean()
{
	nums.clear();
	result = 0;
}