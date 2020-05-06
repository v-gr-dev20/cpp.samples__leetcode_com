// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such
//	that a + b + c + d = target ? Find all unique quadruplets in the array which gives the sum of target.
// Note :
// 	The solution set must not contain duplicate quadruplets.
// https://leetcode.com/problems/4sum/

#include "pch.h"
#include "leetcode_com__fourSum.h"
#include "tools.h"
#include "myAssert.h"
#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <vector>
#include <algorithm>

namespace {
LeetcodeCom_Problems::C4Sum problem;

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum( vector<int>&, int );
};
} // namespace

vector<vector<int>> Solution::fourSum( vector<int>& nums, int target4 )
{
	sort( nums.begin(), nums.end() );
	vector<vector<int>> result;
	const int N = static_cast<int>( nums.size() );
	vector<int> quadruplet( 4 );
	for( int i = 0; i < N-3; ++i ) {
		if( target4 / 4 < nums[i] ) {
			break;
		}
		if( 0 < i && nums[i-1] == nums[i] ) {
			continue;
		}
		quadruplet[0] = nums[i];
		int target3 = target4 - quadruplet[0];
		for( int j = i+1; j < N-2; ++j ) {
			if( target3 / 3 < nums[j] ) {
				break;
			}
			if( i+1 < j && nums[j-1] == nums[j] ) {
				continue;
			}
			quadruplet[1] = nums[j];
			int target2 = target3 - quadruplet[1];
			for( int k = j+1; k < N-1; ++k ) {
				if( target2 / 2 < nums[k] ) {
					break;
				}
				if( j+1 < k && nums[k-1] == nums[k] ) {
					continue;
				}
				quadruplet[2] = nums[k];
				int target1 = target2 - quadruplet[2];
				for( int l = k+1; l < N; ++l ) {
					if( target1 < nums[l] ) {
						break;
					}
					if( k+1 < l && nums[l-1] == nums[l] ) {
						continue;
					}
					if( nums[l] < target1 ) {
						continue;
					}
					quadruplet[3] = nums[l];
					if( result.rend() == find( result.rbegin(), result.rend(), quadruplet ) ) {
						result.push_back( quadruplet );
					}
				}
			}
		}
	}
	return result;
}

LeetcodeCom_Problems::C4Sum::C4Sum()
	: CBaseSample( "leetcode_com__fourSum" )
{
}

LeetcodeCom_Problems::C4Sum::~C4Sum()
{
}

void LeetcodeCom_Problems::C4Sum::Input( istream& iStream, ostream& oStream )
{
	oStream << "Input numbers: ";
	numbers = Tools::InputNumbers( iStream );
	iStream >> targetSum;
}

void LeetcodeCom_Problems::C4Sum::Run()
{
	result = Solution().fourSum( numbers, targetSum );
}

void LeetcodeCom_Problems::C4Sum::Report( vector<string>& reportLines ) const
{
	reportLines.clear();
	string resultStr;
	for( auto const& vectorItem : result ) {
		string numVectorStr;
		for( auto const& item : vectorItem ) {
			numVectorStr += ( 0 < numVectorStr.length() ? " " : "" ) + to_string( item );
		}
		numVectorStr = "[ " + numVectorStr + " ]";
		resultStr +=(  0 < resultStr.length() ? " " : "" ) + numVectorStr;
	}
	resultStr = "[ " + resultStr + " ]";
	reportLines.push_back( "Result: " + resultStr );
}
