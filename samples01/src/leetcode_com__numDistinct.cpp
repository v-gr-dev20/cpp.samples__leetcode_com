// 115. Distinct Subsequences
// Hard
// https://leetcode.com/problems/distinct-subsequences
// Given two strings s and t, return the number of distinct subsequences of s which equals t.
// A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).
// It is guaranteed the answer fits on a 32 - bit signed integer.
//
// Example 1:
// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from S.
// rabbbit
// ^^^^ ^^
// rabbbit
// ^^ ^^^^
// rabbbit
// ^^^ ^^^
//
// Example 2:
// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from S.
// babgbag
// ^^ ^   
// babgbag
// ^^    ^
// babgbag
// ^    ^^
// babgbag
//   ^  ^^
// babgbag
//     ^^^
//
// Constraints:
// 1 <= s.length, t.length <= 1000
// s and t consist of English letters.

#include "pch.h"
#include "leetcode_com__numDistinct.h"
#include "myAssert.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <algorithm>

namespace {
LeetcodeCom_Problems::CDistinctSubsequences problem;

using namespace std;

class Solution {
public:
	int numDistinct( string s, string t );
private:
	int getNumDistinct( const vector<char>& sAfterFilter, const vector<char>& tVector );
};
} // namespace

int Solution::numDistinct( string s, string t )
{
	set<char> tCharSet;
	vector<char> tVector;
	for( auto c: t ) {
		tCharSet.insert( c );
		tVector.push_back( c );
	}
	vector<char> sAfterFilter;
	for( auto c: s ) {
		if( end( tCharSet ) != tCharSet.find( c ) ) {
			sAfterFilter.push_back( c );
		}
	}
	return getNumDistinct( sAfterFilter, tVector );
}

int Solution::getNumDistinct( const vector<char>& sAfterFilter, const vector<char>& tVector )
{
	stack<pair<vector<char>::const_iterator, int>> counterBySPosStack;
	counterBySPosStack.push( make_pair( end( sAfterFilter ), 0 ) );
	map<pair<vector<char>::const_iterator, vector<char>::const_iterator>, const int> counterByPosStorage;
	auto tIt = begin( tVector );
	auto sIt = begin( sAfterFilter );
	if( tIt == end( tVector ) || sIt == end( sAfterFilter ) ) {
		return 0;
	}
	while( true ) {
		while( true ) {
			sIt = find( sIt, end( sAfterFilter ), *tIt );
			if( end( sAfterFilter ) - sIt < end( tVector ) - tIt ) {
				break;
			}
			auto tryCounterByCurrent = counterByPosStorage.find( make_pair( sIt, tIt ) );
			if( end( counterByPosStorage ) != tryCounterByCurrent ) {
				counterBySPosStack.top().second += ( *tryCounterByCurrent ).second;
			} else if( tIt == end( tVector ) - 1 ) {
				counterBySPosStack.top().second += 1;
				counterByPosStorage.insert( make_pair( make_pair( sIt, tIt ), 1 ) );
			} else {
				counterBySPosStack.push( make_pair( sIt, 0 ) );
				tIt += 1;
			}
			sIt += 1;
		}
		if( 1 == counterBySPosStack.size() ) {
			break;
		} else {
			auto currentCounter = counterByPosStorage.insert( make_pair( make_pair( counterBySPosStack.top().first, tIt-1 ), counterBySPosStack.top().second ) );
			sIt = counterBySPosStack.top().first + 1;
			tIt -= 1;
			counterBySPosStack.pop();
			counterBySPosStack.top().second += currentCounter.first->second;
		}
	}
	return counterBySPosStack.top().second;
}

LeetcodeCom_Problems::CDistinctSubsequences::CDistinctSubsequences()
	: CBaseSample( "leetcode_com__numDistinct" )
{
}

LeetcodeCom_Problems::CDistinctSubsequences::~CDistinctSubsequences()
{
}

void LeetcodeCom_Problems::CDistinctSubsequences::Input( istream& iStream, ostream& oStream )
{
	oStream << "Input string s: ";
	iStream >> s;
	oStream << "Input string t: ";
	iStream >> t;
}

void LeetcodeCom_Problems::CDistinctSubsequences::Run()
{
	result = Solution().numDistinct( s, t );
}

void LeetcodeCom_Problems::CDistinctSubsequences::Report( vector<string>& reportLines ) const
{
	reportLines.clear();
	reportLines.push_back( "Result: " + to_string( result ) );
}
