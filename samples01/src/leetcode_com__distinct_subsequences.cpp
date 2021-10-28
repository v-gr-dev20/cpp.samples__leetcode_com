#include "pch.h"
#include "leetcode_com__distinct_subsequences.h"
#include "myAssert.h"
#include <iostream>
#include <vector>
#include <string>

namespace {
LeetcodeCom_Problems::CDistinctSubsequences problem;
} // namespace

LeetcodeCom_Problems::CDistinctSubsequences::CDistinctSubsequences()
	: CBaseSample( "leetcode_com__distinct_subsequences" )
{
}

LeetcodeCom_Problems::CDistinctSubsequences::~CDistinctSubsequences()
{
}

void LeetcodeCom_Problems::CDistinctSubsequences::Input( std::istream& iStream, std::ostream& oStream )
{
	oStream << "Input string s: ";
	iStream >> s;
	oStream << "Input string t: ";
	iStream >> t;
}

void LeetcodeCom_Problems::CDistinctSubsequences::Report( std::vector<std::string>& reportLines ) const
{
	reportLines.clear();
	reportLines.push_back( "Result: " + std::to_string( result ) );
}
