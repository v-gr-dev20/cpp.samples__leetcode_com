// Given an array of integers nums sorted in ascending order, find the startingand ending position of a given target value.
// Your algorithm's runtime complexity must be in the order of O(log n).
// If the target is not found in the array, return[-1, -1].
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include "pch.h"
#include "leetcode_com__searchRange.h"
#include "tools.h"
#include "myAssert.h"
#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <vector>
#include <algorithm>

namespace {
LeetcodeCom_Problems::CFindFirstAndLast problem;

using namespace std;

class Solution {
public:
	vector<int> searchRange( vector<int>& nums, int target );
};
} // namespace

vector<int> Solution::searchRange( vector<int>& nums, int target )
{
	const vector<int> noResult = { -1, -1 };
	if( nums.size() == 0 ) {
		return noResult;
	}
	vector<int> result;
	int leftPos = 0;
	int rightPos = nums.size() - 1;
	int prevRightPos = rightPos;
	while( leftPos < rightPos && nums[leftPos] < target && target <= nums[rightPos] ) {
		int middlePos = leftPos + ( rightPos - leftPos ) / 2;
		if( nums[middlePos] < target ) {
			if( middlePos == leftPos ) {
				break;
			}
			leftPos = middlePos;
		} else if( target < nums[middlePos] ) {
			prevRightPos = rightPos = middlePos;
		} else {
			rightPos = middlePos;
		}
	}
	if( nums[leftPos] < target && target < nums[rightPos] || target < nums[leftPos] || nums[rightPos] < target ) {
		return noResult;
	} 
	result.push_back( nums[leftPos] == target ? leftPos : rightPos );
	
	leftPos = result.front();
	rightPos = prevRightPos;
	while( leftPos < rightPos && nums[leftPos] == target && target < nums[rightPos] ) {
		int middlePos = leftPos + ( rightPos - leftPos ) / 2;
		if( target < nums[middlePos] ) {
			rightPos = middlePos;
		} else {
			if( middlePos == leftPos ) {
				break;
			}
			leftPos = middlePos;
		}
	}
	result.push_back( nums[rightPos] == target ? rightPos : leftPos );
	return result;
}

LeetcodeCom_Problems::CFindFirstAndLast::CFindFirstAndLast()
	: CBaseSample( "leetcode_com__searchRange" )
{
}

LeetcodeCom_Problems::CFindFirstAndLast::~CFindFirstAndLast()
{
}

void LeetcodeCom_Problems::CFindFirstAndLast::Input( istream& iStream, ostream& oStream )
{
	oStream << "Input numbers: ";
	numbers = Tools::InputNumbers( iStream );
	oStream << "Input target: ";
	iStream >> target;
}

void LeetcodeCom_Problems::CFindFirstAndLast::Run()
{
	result = Solution().searchRange( numbers, target );
}

void LeetcodeCom_Problems::CFindFirstAndLast::Report( vector<string>& reportLines ) const
{
	reportLines.clear();
	ostringstream resultStream;
	bool isBegin = true;
	for( const auto& item : result ) {
		resultStream << ( isBegin ? "" : ", " ) << to_string( item );
		isBegin = false;
	}
	reportLines.push_back( "Result: { " + resultStream.str() + " }" );
}
