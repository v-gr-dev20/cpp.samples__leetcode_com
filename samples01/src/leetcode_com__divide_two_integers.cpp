#include "pch.h"
#include "leetcode_com__divide_two_integers.h"
#include "myAssert.h"
#include <iostream>
#include <vector>
#include <string>

namespace {
LeetcodeCom_Problems::CDivideTwoIntegers problem;
} // namespace

LeetcodeCom_Problems::CDivideTwoIntegers::CDivideTwoIntegers()
	: CBaseSample( "leetcode_com__divide_two_integers" )
{
}

LeetcodeCom_Problems::CDivideTwoIntegers::~CDivideTwoIntegers()
{
}

void LeetcodeCom_Problems::CDivideTwoIntegers::Input( std::istream& iStream, std::ostream& oStream )
{
	oStream << "Input dividend: ";
	iStream >> dividend;
	oStream << "Input divisor: ";
	iStream >> divisor;
}

void LeetcodeCom_Problems::CDivideTwoIntegers::Report( std::vector<std::string>& reportLines ) const
{
	reportLines.clear();
	reportLines.push_back( "Result: " + std::to_string( result ) );
}
