#include "pch.h"
#include "leetcode_com__4Sum.h"
#include "tools.h"
#include "myAssert.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

namespace {
LeetcodeCom_Problems::C4Sum problem;
} // namespace

LeetcodeCom_Problems::C4Sum::C4Sum()
	: CBaseSample( "leetcode_com__4Sum" )
{
}

LeetcodeCom_Problems::C4Sum::~C4Sum()
{
}

void LeetcodeCom_Problems::C4Sum::Input( std::istream& iStream, std::ostream& oStream )
{
	oStream << "Input numbers: ";
	nums = Tools::InputNumbers( iStream );
	iStream >> target;
}

void LeetcodeCom_Problems::C4Sum::Report( std::vector<std::string>& reportLines ) const
{
	reportLines.clear();
	std::string resultStr;
	for( auto const& vectorItem : result ) {
		std::string numVectorStr;
		for( auto const& item : vectorItem ) {
			numVectorStr += ( 0 < numVectorStr.length() ? " " : "" ) + std::to_string( item );
		}
		numVectorStr = "[ " + numVectorStr + " ]";
		resultStr +=(  0 < resultStr.length() ? " " : "" ) + numVectorStr;
	}
	resultStr = "[ " + resultStr + " ]";
	reportLines.push_back( "Result: " + resultStr );
}
