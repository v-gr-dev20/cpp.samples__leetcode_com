// 200. Number of Islands
// Medium
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
// 
// Example 1:
// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// 
// Example 2:
// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
// 
// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.
//
// https://leetcode.com/problems/number-of-islands

#include "pch.h"
#include "leetcode_com__numIslands.h"
#include "tools.h"
#include "myAssert.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <memory>
#include <algorithm>

namespace {
LeetcodeCom_Problems::CNumberOfIslands problem;

using namespace std;

class Solution {
public:
	int numIslands( vector<vector<char>>& grid );
};
class Solution2 {
public:
	int numIslands( vector<vector<char>>& grid );
};
} // namespace

int Solution::numIslands( vector<vector<char>>& grid )
{
	size_t m = grid.size();
	assert( 0 < m );
	size_t n = grid[0].size();
	assert( 0 < n );

	shared_ptr<vector<size_t>> upperRow( new vector<size_t>( n, 0 ) );
	shared_ptr<vector<size_t>> currentRow( new vector<size_t>( n, 0 ) );
	vector<size_t> eqVector = { 0 };
	size_t mergeCounter = 0;
	for( size_t i = 0; i < m; ++i ) {
		for( size_t j = 0; j < n; ++j ) {
			size_t& assignedCluster = ( *currentRow )[j];
			if( '0' == grid[i][j] ) {
				assignedCluster = 0;
				continue;
			}
			size_t zeroStub = 0;
			size_t& leftCluster = ( 0 < j && '1' == grid[i][j-1] )? ( *currentRow )[j-1]: zeroStub;
			size_t& upperCluster = ( 0 < i && '1' == grid[i-1][j] )? ( *upperRow )[j]: zeroStub;
			assignedCluster = max( leftCluster, upperCluster );
			if( 0 == assignedCluster ) {
				assignedCluster = eqVector.size();
				eqVector.push_back( assignedCluster );
				continue;
			}
			if( leftCluster == upperCluster
				|| 0 == leftCluster || 0 == upperCluster )
			{
				continue;
			}
			set<size_t> mergedClusters;
			while( leftCluster != eqVector[leftCluster] ) {
				mergedClusters.insert( leftCluster );
				leftCluster = eqVector[leftCluster];
			}
			while( upperCluster != eqVector[upperCluster] ) {
				mergedClusters.insert( upperCluster );
				upperCluster = eqVector[upperCluster];
			}
			if( leftCluster != upperCluster ) {
				assignedCluster = min( leftCluster, upperCluster );
				if( assignedCluster != leftCluster ) {
					eqVector[leftCluster] = assignedCluster;
					leftCluster = assignedCluster;
				} else {
					eqVector[upperCluster] = assignedCluster;
					upperCluster = assignedCluster;
				}
				for( auto item: mergedClusters ) {
					eqVector[item] = assignedCluster;
				}
				++mergeCounter;
			}
		}
		swap( currentRow, upperRow );
	}
	return eqVector.size()-1 - mergeCounter;
}

int Solution2::numIslands( vector<vector<char>>& grid )
{
	size_t m = grid.size();
	assert( 0 < m );
	size_t n = grid[0].size();
	assert( 0 < n );

	vector<vector<size_t>> clasters( m, vector<size_t>( n, 0 ) );
	vector<size_t> eqVector = { 0 };
	size_t mergeCounter = 0;
	for( int i = 1; i < m + n; ++i ) {
		int r = i <= n? 0 : i - n;
		int c = i <= n? i-1 : n-1;
		for( ; r < m && 0 <= c; ++r, --c ) {
			if( '0' == grid[r][c] ) {
				continue;
			}
			size_t zeroStub = 0;
			size_t& assignedCluster = clasters[r][c];
			size_t& leftCluster = ( 0 < c && '1' == grid[r][c-1] )? clasters[r][c-1]: zeroStub;
			size_t& upperCluster = ( 0 < r && '1' == grid[r-1][c] )? clasters[r-1][c]: zeroStub;
			assignedCluster = max( leftCluster, upperCluster );
			if( 0 == assignedCluster ) {
				assignedCluster = eqVector.size();
				eqVector.push_back( assignedCluster );
				continue;
			}
			if( leftCluster == upperCluster
				|| 0 == leftCluster || 0 == upperCluster )
			{
				continue;
			}
			set<size_t> mergedClusters;
			while( leftCluster != eqVector[leftCluster] ) {
				mergedClusters.insert( leftCluster );
				leftCluster = eqVector[leftCluster];
			}
			while( upperCluster != eqVector[upperCluster] ) {
				mergedClusters.insert( upperCluster );
				upperCluster = eqVector[upperCluster];
			}
			if( leftCluster != upperCluster ) {
				assignedCluster = min( leftCluster, upperCluster );
				if( assignedCluster != leftCluster ) {
					eqVector[leftCluster] = assignedCluster;
					leftCluster = assignedCluster;
				} else {
					eqVector[upperCluster] = assignedCluster;
					upperCluster = assignedCluster;
				}
				for( auto item: mergedClusters ) {
					eqVector[item] = assignedCluster;
				}
				++mergeCounter;
			}
		}
	}
	return eqVector.size()-1 - mergeCounter;
}

LeetcodeCom_Problems::CNumberOfIslands::CNumberOfIslands()
	: CBaseSample( "leetcode_com__numIslands" )
{
}

LeetcodeCom_Problems::CNumberOfIslands::~CNumberOfIslands()
{
}

void LeetcodeCom_Problems::CNumberOfIslands::Input( istream& iStream, ostream& oStream )
{
	grid.clear();
	oStream << "Input grid : ";
	while( true ) {
		vector<char> inputVector = Tools::Input01s<char>( iStream );
		if( !iStream ) {
			break;
		}
		grid.push_back( inputVector );
	}
}

void LeetcodeCom_Problems::CNumberOfIslands::Run()
{
	result = Solution().numIslands( grid );
}

void LeetcodeCom_Problems::CNumberOfIslands::Report( vector<string>& reportLines ) const
{
	reportLines.clear();
	reportLines.push_back( "Result: " + to_string( result ) );
}
