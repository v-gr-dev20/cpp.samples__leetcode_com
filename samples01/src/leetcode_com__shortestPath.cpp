// 1293. Shortest Path in a Grid with Obstacles Elimination
// Hard
// You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle).You can move up, down, left, or right from and to an empty cell in one step.
// Return the minimum number of steps to walk from the upper left corner(0, 0) to the lower right corner(m - 1, n - 1) given that you can eliminate at most k obstacles.If it is not possible to find such walk return -1.
//
// Example 1:
// Input:
// grid =
// [[0, 0, 0],
// [1, 1, 0],
// [0, 0, 0],
// [0, 1, 1],
// [0, 0, 0]],
// k = 1
// Output: 6
// Explanation :
// 	The shortest path without eliminating any obstacle is 10.
// 	The shortest path with one obstacle elimination at position(3, 2) is 6. Such path is(0, 0) -> (0, 1) -> (0, 2) -> (1, 2) -> (2, 2) -> (3, 2) -> (4, 2).
//
// Example 2 :
// Input :
// grid =
// [[0, 1, 1],
// [1, 1, 1],
// [1, 0, 0]],
// k = 1
// Output : -1
// Explanation :
// We need to eliminate at least two obstacles to find such a walk.
// 
// Constraints :
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 40
// 1 <= k <= m * n
// grid[i][j] == 0 or 1
// grid[0][0] == grid[m - 1][n - 1] == 0
//
// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

#include "pch.h"
#include "leetcode_com__shortestPath.h"
#include "tools.h"
#include "myAssert.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

namespace {
LeetcodeCom_Problems::CShortestPathInAGridWithObstaclesElimination problem;

using namespace std;

class Solution {
public:
	int shortestPath( vector<vector<int>>& grid, int k );
};
} // namespace

int Solution::shortestPath( vector<vector<int>>& grid, int k )
{
	assert( 0 <= k );
	const int m = grid.size();
	assert( 1 <= m );
	const int n = grid[0].size();
	assert( 1 <= n );
	assert( 0 == grid[0][0] && 0 == grid[m-1][n-1] );

	if( m+n-2 <= k ) {
		return m+n-2;
	}

	vector<vector<vector<int>>> distance( m, vector<vector<int>>( n, vector<int>( k+1, m*n ) ) );
	queue<tuple<int,int,int>> vertexWalkStore;
	distance[0][0][0] = 0;
	vertexWalkStore.push( make_tuple( 0, 0, 0 ) );
	while( !vertexWalkStore.empty() ) {
		const auto& currentRow = get<0>( vertexWalkStore.front() );
		const auto& currentColumn = get<1>(vertexWalkStore.front());
		const auto& currentEliminationCount = get<2>( vertexWalkStore.front() );
		auto tryModifyNextDistance = [&]( int nextRow, int nextColumn )
		{
			if( 0 == grid[nextRow][nextColumn]
				&& 1 + distance[currentRow][currentColumn][currentEliminationCount] < distance[nextRow][nextColumn][currentEliminationCount] )
			{
				distance[nextRow][nextColumn][currentEliminationCount] = 1 + distance[currentRow][currentColumn][currentEliminationCount];
				vertexWalkStore.push( make_tuple( nextRow, nextColumn, currentEliminationCount ) );
			} else if( currentEliminationCount < k
				&& 1 + distance[currentRow][currentColumn][currentEliminationCount] < distance[nextRow][nextColumn][currentEliminationCount+1] )
			{
				distance[nextRow][nextColumn][currentEliminationCount+1] = 1 + distance[currentRow][currentColumn][currentEliminationCount];
				if( rend( distance[nextRow][nextColumn] ) == find_if( rend( distance[nextRow][nextColumn])-currentEliminationCount, rend( distance[nextRow][nextColumn]), [&]( const auto& item )
					{
						return item < distance[nextRow][nextColumn][currentEliminationCount+1];
					} ) )
				{
					vertexWalkStore.push( make_tuple( nextRow, nextColumn, currentEliminationCount+1 ) );
				}
			}
		};
		if( 0 < currentRow ) {
			tryModifyNextDistance( currentRow-1, currentColumn );
		}
		if( 0 < currentColumn ) {
			tryModifyNextDistance( currentRow, currentColumn-1 );
		}
		if( currentRow < m-1 ) {
			tryModifyNextDistance( currentRow+1, currentColumn );
		}
		if( currentColumn < n-1 ) {
			tryModifyNextDistance( currentRow, currentColumn+1 );
		}
		vertexWalkStore.pop() ;
	}
	int minDistance = *min_element( distance[m-1][n-1].begin(), distance[m-1][n-1].end() );
	return minDistance == m*n ? -1: minDistance;
}

LeetcodeCom_Problems::CShortestPathInAGridWithObstaclesElimination::CShortestPathInAGridWithObstaclesElimination()
	: CBaseSample( "leetcode_com__shortestPath" )
{
}

LeetcodeCom_Problems::CShortestPathInAGridWithObstaclesElimination::~CShortestPathInAGridWithObstaclesElimination()
{
}

void LeetcodeCom_Problems::CShortestPathInAGridWithObstaclesElimination::Input( istream& iStream, ostream& oStream )
{
	grid.clear();
	oStream << "Input k: ";
	iStream >> k;
	string getRestLineStub;
	getline( iStream, getRestLineStub);
	oStream << "Input grid : ";
	while( true ) {
		vector<int> inputVector = Tools::InputNumbers( iStream );
		if( !iStream ) {
			break;
		}
		grid.push_back( inputVector );
	};
}

void LeetcodeCom_Problems::CShortestPathInAGridWithObstaclesElimination::Run()
{
	result = Solution().shortestPath( grid, k );
}

void LeetcodeCom_Problems::CShortestPathInAGridWithObstaclesElimination::Report( vector<string>& reportLines ) const
{
	reportLines.clear();
	reportLines.push_back( "Result: " + to_string( result ) );
}
