#include "pch.h"
#include "leetcode_com__shortest_path_in_a_grid_with_obstacles_elimination.h"
#include "tools.h"
#include "myAssert.h"
#include <iostream>
#include <vector>
#include <string>

namespace {
LeetcodeCom_Problems::CShortestPathInAGridWithObstaclesElimination problem;
} // namespace

LeetcodeCom_Problems::CShortestPathInAGridWithObstaclesElimination::CShortestPathInAGridWithObstaclesElimination()
	: CBaseSample( "leetcode_com__shortest_path_in_a_grid_with_obstacles_elimination" )
{
}

LeetcodeCom_Problems::CShortestPathInAGridWithObstaclesElimination::~CShortestPathInAGridWithObstaclesElimination()
{
}

void LeetcodeCom_Problems::CShortestPathInAGridWithObstaclesElimination::Input( std::istream& iStream, std::ostream& oStream)
{
	grid.clear();
	oStream << "Input k: ";
	iStream >> k;
	std::string getRestLineStub;
	std::getline( iStream, getRestLineStub);
	oStream << "Input grid : ";
	while( true ) {
		std::vector<int> inputVector = Tools::InputNumbers( iStream );
		if( !iStream ) {
			break;
		}
		grid.push_back( inputVector );
	};
}

void LeetcodeCom_Problems::CShortestPathInAGridWithObstaclesElimination::Report( std::vector<std::string>& reportLines ) const
{
	reportLines.clear();
	reportLines.push_back( "Result: " + std::to_string( result ) );
}

void LeetcodeCom_Problems::CShortestPathInAGridWithObstaclesElimination::Clean()
{
	k = 0;
	grid.clear();
	result = 0;
}
