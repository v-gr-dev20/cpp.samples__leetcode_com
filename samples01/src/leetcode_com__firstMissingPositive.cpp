// Given an unsorted integer array, find the smallest missing positive integer.
// 
// Example 1:
// 
// Input: [1, 2, 0]
// Output : 3
// Example 2 :
// 
// 	Input : [3, 4, -1, 1]
// 	Output : 2
// https://leetcode.com/problems/first-missing-positive/

#include "pch.h"
#include "leetcode_com__firstMissingPositive.h"
#include "tools.h"
#include "myAssert.h"
#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <vector>
#include <algorithm>

namespace {
LeetcodeCom_Problems::CFirstMissingPositive problem;

using namespace std;

class Solution {
public:
	int firstMissingPositive( vector<int>& nums );
private:
	int splitByMedian( vector<int>& v, int left, int right, int medianValue );
	int findFirstMissed( vector<int>& v, int left, int right, int beginValue );
};
} // namespace

int Solution::firstMissingPositive( vector<int>& nums )
{
	int firstPositivePos = splitByMedian( nums, 0, nums.size() - 1, 1 );
	return firstPositivePos < 0 ? 1 : findFirstMissed( nums, firstPositivePos, nums.size() - 1, 1 );
}

int Solution::splitByMedian( vector<int>& v, int left, int right, int medianValue )
{
	if( right < left ) {
		return -1;
	}
	while( true ) {
		while( left < right && v[left] < medianValue ) {
			++left;
		}
		while( left < right && medianValue <= v[right] ) {
			--right;
		}
		if( left == right ) {
			return v[right] < medianValue ? -1 : right;
		}
		swap( v[left], v[right] );
		++left;
	}
}

int Solution::findFirstMissed( vector<int>& v, int left, int right, int beginValue )
{
	if( right < left ) {
		return beginValue;
	}
	if( left == right ) {
		return v[right] == beginValue ? beginValue + 1 : beginValue;
	}
	int medianShift = ( right - left + 1 ) / 2;
	int medianValue = max( beginValue + 1, min( beginValue + medianShift, v[right] ) );
	int medianPos = splitByMedian( v, left, right, medianValue );
	if( medianPos < 0 && beginValue + 1 == medianValue ) {
		return beginValue + 1;
	}
	int probablyMissed = findFirstMissed( v, left, medianPos - 1, beginValue );
	return probablyMissed < medianValue
		? probablyMissed
		: findFirstMissed( v, medianPos, right, probablyMissed );
}

LeetcodeCom_Problems::CFirstMissingPositive::CFirstMissingPositive()
	: CBaseSample( "leetcode_com__firstMissingPositive" )
{
}

LeetcodeCom_Problems::CFirstMissingPositive::~CFirstMissingPositive()
{
}

void LeetcodeCom_Problems::CFirstMissingPositive::Input( istream& iStream, ostream& oStream )
{
	oStream << "Input numbers: ";
	v = Tools::InputNumbers( iStream );
}

void LeetcodeCom_Problems::CFirstMissingPositive::Run()
{
	result = Solution().firstMissingPositive( v );
}

void LeetcodeCom_Problems::CFirstMissingPositive::Report( vector<string>& reportLines ) const
{
	reportLines.clear();
	reportLines.push_back( "Result: " + to_string( result ) );
}
