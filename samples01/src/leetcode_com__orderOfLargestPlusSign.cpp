// 764. Largest Plus Sign
// You are given an integer n. You have an n x n binary grid grid with all values initially 1's except for some indices given in the array mines. The ith element of the array mines is defined as mines[i] = [xi, yi] where grid[xi][yi] == 0.
// Return the order of the largest axis-aligned plus sign of 1's contained in grid. If there is none, return 0.
// An axis-aligned plus sign of 1's of order k has some center grid[r][c] == 1 along with four arms of length k - 1 going up, down, left, and right, and made of 1's. Note that there could be 0's or 1's beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1's.
// 
// Example 1:
// Input: n = 5, mines = [[4,2]]
// Output: 2
// Explanation: In the above grid, the largest plus sign can only be of order 2. One of them is shown.
//
// Example 2:
// Input: n = 1, mines = [[0,0]]
// Output: 0
// Explanation: There is no plus sign, so return 0.
// 
// Constraints:
// 1 <= n <= 500
// 1 <= mines.length <= 5000
// 0 <= xi, yi < n
// All the pairs (xi, yi) are unique.
//
// https://leetcode.com/problems/largest-plus-sign

#include "pch.h"
#include "leetcode_com__orderOfLargestPlusSign.h"
#include "tools.h"
#include "myAssert.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

namespace {
LeetcodeCom_Problems::CLargestPlusSign problem;

using namespace std;

class Solution {
public:
	int orderOfLargestPlusSign( int n, vector<vector<int>>& mines );
	Solution() {}
private:
	vector<vector<int>> squareMatrix;
	void initSquare( int n, const vector<vector<int>>& mines );

	inline pair<int, int> nextClockwiseOnSquarePerimeterPosition( const pair<int, int>& current );
	inline bool pointBelongsToRowSection( const pair<int, int>& point, const pair<int, int>& sectionCenter, int regionHorizontalOrder );
	inline bool pointBelongsToColumnSection( const pair<int, int>& point, const pair<int, int>& sectionCenter, int regionVerticalOrder );
	inline bool isRowSectionContinuous( const pair<int,int>& sectionCenter, int regionHorizontalOrder );
	inline bool isColumnSectionContinuous( const pair<int,int>& sectionCenter, int regionVerticalOrder );
	enum CPlacingType { center, top, right, bottom, left };
	inline CPlacingType getOnSquarePerimeterPlacing( const pair<int, int>& point );
};
} // namespace

int Solution::orderOfLargestPlusSign( int n, vector<vector<int>>& mines )
{
	assert( 1 <= n && n <= 500 );
	assert( mines.size() <= 5000 );
	initSquare( n, mines );

	int maxOrder = 0;
	for( int tryMaxOrder = ( n+1 ) / 2; maxOrder < tryMaxOrder; --tryMaxOrder ) {
		const pair<int, int> beginOnPerimeterPosition = {tryMaxOrder-1,tryMaxOrder-1};
		pair<int, int> currentOnPerimeterPosition = beginOnPerimeterPosition;
		do {
			for( int currentOrder = maxOrder+1; currentOrder <= tryMaxOrder; ++currentOrder ) {
				if( !isRowSectionContinuous( currentOnPerimeterPosition, currentOrder )
					|| !isColumnSectionContinuous( currentOnPerimeterPosition, currentOrder ) )
				{
					break;
				}
				maxOrder = currentOrder;
			}
			currentOnPerimeterPosition = nextClockwiseOnSquarePerimeterPosition( currentOnPerimeterPosition );
		} while( currentOnPerimeterPosition != beginOnPerimeterPosition );
	}
	return maxOrder;
}

void Solution::initSquare( int n, const vector<vector<int>>& mines )
{
	squareMatrix.assign( n, vector<int>( n, 1 ) );
	for( const auto& mine: mines ) {
		squareMatrix[mine[0]][mine[1]] = 0;
	}
}

bool Solution::isRowSectionContinuous( const pair<int,int>& sectionCenter, int sectionOrder )
{
	return squareMatrix[sectionCenter.first].begin() + ( sectionCenter.second + sectionOrder )
		== find_if( squareMatrix[sectionCenter.first].begin() + ( sectionCenter.second - sectionOrder + 1 ),
			squareMatrix[sectionCenter.first].begin() + ( sectionCenter.second + sectionOrder ),
			[]( const auto& item )
			{ 
				return 0 == item;
			} );
}

bool Solution::isColumnSectionContinuous( const pair<int,int>& sectionCenter, int sectionOrder )
{
	return squareMatrix.begin() + ( sectionCenter.first + sectionOrder )
		== find_if( squareMatrix.begin() + ( sectionCenter.first - sectionOrder + 1 ),
			squareMatrix.begin() + ( sectionCenter.first + sectionOrder ),
			[&]( const auto& row )
			{
				return 0 == row[sectionCenter.second];
			} );
}

bool Solution::pointBelongsToRowSection( const pair<int, int>& point, const pair<int, int>& sectionCenter, int regionHorizontalOrder )
{
	return sectionCenter.first == point.first
		&& sectionCenter.second - regionHorizontalOrder + 1 <= point.second && point.second <= sectionCenter.second + regionHorizontalOrder - 1;
}

bool Solution::pointBelongsToColumnSection( const pair<int, int>& point, const pair<int, int>& sectionCenter, int regionVerticalOrder )
{
	return sectionCenter.second == point.second
		&& sectionCenter.first - regionVerticalOrder + 1 <= point.first && point.first <= sectionCenter.first + regionVerticalOrder - 1;
}

pair<int, int> Solution::nextClockwiseOnSquarePerimeterPosition( const pair<int, int>& current )
{
	switch( getOnSquarePerimeterPlacing( current ) ) {
		case center:
			return current;
		case top:
			return { current.first, current.second+1 };
		case right:
			return { current.first+1, current.second };
		case bottom:
			return { current.first, current.second-1 };
		case left:
			return { current.first-1, current.second };
	}
	assert( true );
}

Solution::CPlacingType Solution::getOnSquarePerimeterPlacing( const pair<int, int>& current )
{
	const int n = squareMatrix.size();
	int topInterval = current.first;
	int rightInterval = n - current.second - 1;
	int bottomInterval = n - current.first - 1;
	int leftInterval = current.second;
	int minInterval = std::min( { topInterval, rightInterval, bottomInterval, leftInterval } );
	if( minInterval == topInterval && topInterval < rightInterval ) {
		return top;
	}
	if( minInterval == rightInterval && rightInterval < bottomInterval ) {
		return right;
	}
	if( minInterval == bottomInterval && bottomInterval < leftInterval ) {
		return bottom;
	}
	if( minInterval == leftInterval && leftInterval < topInterval ) {
		return left;
	}
	return center;
}

LeetcodeCom_Problems::CLargestPlusSign::CLargestPlusSign()
	: CBaseSample( "leetcode_com__orderOfLargestPlusSign" )
{
}

LeetcodeCom_Problems::CLargestPlusSign::~CLargestPlusSign()
{
}

void LeetcodeCom_Problems::CLargestPlusSign::Input( istream& iStream, ostream& oStream )
{
	mines.clear();
	string getLine;
	oStream << "Input n : ";
	iStream >> n;
	getline( iStream, getLine );
	oStream << "Input pairs : ";
	while( true ) {
		vector<int> inputVector = Tools::InputNumbers( iStream );
		if( !iStream ) {
			break;
		}
		mines.push_back( inputVector );
	};
}

void LeetcodeCom_Problems::CLargestPlusSign::Run()
{
	result = Solution().orderOfLargestPlusSign( n, mines );
}

void LeetcodeCom_Problems::CLargestPlusSign::Report( vector<string>& reportLines ) const
{
	reportLines.clear();
	reportLines.push_back( "Result: " + to_string( result ) );
}
