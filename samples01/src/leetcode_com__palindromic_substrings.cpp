#include "pch.h"
#include "leetcode_com__palindromic_substrings.h"
#include "tools.h"
#include "myAssert.h"
#include <iostream>
#include <vector>
#include <string>

namespace {
LeetcodeCom_Problems::CPalindromicSubstrings problem;
} // namespace

LeetcodeCom_Problems::CPalindromicSubstrings::CPalindromicSubstrings()
	: CBaseSample( "leetcode_com__palindromic_substrings" )
{
}

LeetcodeCom_Problems::CPalindromicSubstrings::~CPalindromicSubstrings()
{
}

void LeetcodeCom_Problems::CPalindromicSubstrings::Input( std::istream& iStream, std::ostream& oStream )
{
	Clean();
	oStream << "Input zero: ";
	iStream >> s;
}

void LeetcodeCom_Problems::CPalindromicSubstrings::Report( std::vector<std::string>& reportLines ) const
{
	reportLines.clear();
	reportLines.push_back( "Result: " + std::to_string( result ) );
}

void LeetcodeCom_Problems::CPalindromicSubstrings::Clean()
{
	s.clear();
	result = 0;
}