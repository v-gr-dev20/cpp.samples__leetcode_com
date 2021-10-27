// 29. Divide Two Integers
// Medium
// https://leetcode.com/problems/divide-two-integers/
// Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
// Return the quotient after dividing dividend by divisor.
// The integer division should truncate toward zero, which means losing its fractional part.
//	For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.
// Note :
// 	Both dividend and divisor will be 32 - bit signed integers.
// 	The divisor will never be 0.
// 	Assume we are dealing with an environment which could only store integers within the 32 - bit signed integer range :
//	[−231, 231 − 1].For the purpose of this problem, assume that your function returns 231 − 1 when the division result
//	overflows.
// 
// Example 1:
// Input: dividend = 10, divisor = 3
// Output : 3
// Explanation : 10 / 3 = truncate(3.33333..) = 3.
// 
// Example 2 :
// 	Input : dividend = 7, divisor = -3
// 	Output : -2
// 	Explanation : 7 / -3 = truncate(-2.33333..) = -2.
// 
// 	Example 3 :
// 	Input : dividend = 0, divisor = 1
// 	Output : 0
// 
// 	Example 4 :
// 	Input : dividend = 1, divisor = 1
// 	Output : 1
// 
// 	Constraints :
// 	-2^31 <= dividend, divisor <= 2^31 - 1
// 	divisor != 0

#include "pch.h"
#include "leetcode_com__divide_two_integers.h"
#include "myAssert.h"
#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <vector>
#include <algorithm>

namespace {
LeetcodeCom_Problems::CDivideTwoIntegers problem;

using namespace std;

class Solution {
public:
	int divide( int dividend, int divisor );
};
} // namespace

int Solution::divide( int dividend, int divisor )
{
	if( 0 == dividend ) {
		return 0;
	}
	if( INT32_MIN == divisor ) {
		return dividend == divisor ? 1 : 0;
	}
	int restDivident = dividend;
	int result = 0;
	if( INT32_MIN == dividend ) {
		if( -1 == divisor ) {
			return INT32_MAX;
		}
		if( 1 == divisor ) {
			return dividend;
		}
		result += 1;
		restDivident += abs( divisor );
	}
	restDivident = abs( restDivident ); 
	for( int shiftCount = 0;; ) {
		unsigned int shiftedDivisor = abs( divisor ) << shiftCount;
		if( shiftedDivisor <= restDivident ) {
			result += 1 << shiftCount;
			restDivident -= shiftedDivisor;
			if( shiftCount < 30 ) {
				++shiftCount;
			}
		} else {
			if( shiftCount == 0 ) {
				break;
			}
			shiftCount = 0;
		}
	}
	bool isResultNegative = ( dividend < 0 && 0 < divisor || 0 < dividend && divisor < 0 );
	return isResultNegative ? - result : result;
}

LeetcodeCom_Problems::CDivideTwoIntegers::CDivideTwoIntegers()
	: CBaseSample( "leetcode_com__divide_two_integers" )
{
}

LeetcodeCom_Problems::CDivideTwoIntegers::~CDivideTwoIntegers()
{
}

void LeetcodeCom_Problems::CDivideTwoIntegers::Input( istream& iStream, ostream& oStream )
{
	oStream << "Input dividend: ";
	iStream >> dividend;
	oStream << "Input divisor: ";
	iStream >> divisor;
}

void LeetcodeCom_Problems::CDivideTwoIntegers::Run()
{
	result = Solution().divide( dividend, divisor );
}

void LeetcodeCom_Problems::CDivideTwoIntegers::Report( vector<string>& reportLines ) const
{
	reportLines.clear();
	reportLines.push_back( "Result: " + to_string( result ) );
}
