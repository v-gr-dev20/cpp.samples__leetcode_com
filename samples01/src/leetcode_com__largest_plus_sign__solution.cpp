// 764. Largest Plus Sign
// Medium
// https://leetcode.com/problems/largest-plus-sign
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

#include "pch.h"
#include "leetcode_com__largest_plus_sign.h"
#include "myAssert.h"
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

namespace {
// Solution public: as on the leetcode.com
class Solution {
public:
	int orderOfLargestPlusSign( int n, vector<vector<int>>& mines );
private:
	vector<vector<int>> grid;
	void initSquare( int n, const vector<vector<int>>& mines );
	inline pair<int, int> getNextClockwiseOnSquarePerimeterPosition( const pair<int, int>& current ) const;
	inline bool isPointBelongsToRowSection( const pair<int, int>& point, const pair<int, int>& sectionCenter, int regionHorizontalOrder ) const;
	inline bool isPointBelongsToColumnSection( const pair<int, int>& point, const pair<int, int>& sectionCenter, int regionVerticalOrder ) const;
	inline bool isRowSectionContinuous( const pair<int,int>& sectionCenter, int regionHorizontalOrder ) const;
	inline bool isColumnSectionContinuous( const pair<int,int>& sectionCenter, int regionVerticalOrder ) const;
	enum CPlacingType { center, top, right, bottom, left };
	inline CPlacingType getOnSquarePerimeterPlacing( const pair<int, int>& point ) const;
};

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
			currentOnPerimeterPosition = getNextClockwiseOnSquarePerimeterPosition( currentOnPerimeterPosition );
		} while( currentOnPerimeterPosition != beginOnPerimeterPosition );
	}
	return maxOrder;
}

void Solution::initSquare( int n, const vector<vector<int>>& mines )
{
	grid.assign( n, vector<int>( n, 1 ) );
	for( const auto& mine: mines ) {
		grid[mine[0]][mine[1]] = 0;
	}
}

bool Solution::isRowSectionContinuous( const pair<int,int>& sectionCenter, int sectionOrder ) const
{
	return grid[sectionCenter.first].begin() + ( sectionCenter.second + sectionOrder )
		== find_if( grid[sectionCenter.first].begin() + ( sectionCenter.second - sectionOrder + 1 ),
			grid[sectionCenter.first].begin() + ( sectionCenter.second + sectionOrder ),
			[]( const auto& item )
			{ 
				return 0 == item;
			} );
}

bool Solution::isColumnSectionContinuous( const pair<int,int>& sectionCenter, int sectionOrder ) const
{
	return grid.begin() + ( sectionCenter.first + sectionOrder )
		== find_if( grid.begin() + ( sectionCenter.first - sectionOrder + 1 ),
			grid.begin() + ( sectionCenter.first + sectionOrder ),
			[&]( const auto& row )
			{
				return 0 == row[sectionCenter.second];
			} );
}

bool Solution::isPointBelongsToRowSection( const pair<int, int>& point, const pair<int, int>& sectionCenter, int regionHorizontalOrder ) const
{
	return sectionCenter.first == point.first
		&& sectionCenter.second - regionHorizontalOrder + 1 <= point.second && point.second <= sectionCenter.second + regionHorizontalOrder - 1;
}

bool Solution::isPointBelongsToColumnSection( const pair<int, int>& point, const pair<int, int>& sectionCenter, int regionVerticalOrder ) const
{
	return sectionCenter.second == point.second
		&& sectionCenter.first - regionVerticalOrder + 1 <= point.first && point.first <= sectionCenter.first + regionVerticalOrder - 1;
}

pair<int, int> Solution::getNextClockwiseOnSquarePerimeterPosition( const pair<int, int>& current ) const
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

Solution::CPlacingType Solution::getOnSquarePerimeterPlacing( const pair<int, int>& current ) const
{
	const int n = grid.size();
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
} // namespace

void LeetcodeCom_Problems::CLargestPlusSign::Run()
{
	result = Solution().orderOfLargestPlusSign( n, mines );
}
