#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class CLargestPlusSign : public CBaseSample {
public:
	CLargestPlusSign();
	virtual ~CLargestPlusSign() override;
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
	virtual void Clean() override;
private:
	// https://leetcode.com/problems/largest-plus-sign/
	// You are given an integer n. You have an n x n binary grid grid with all values initially 1's except for some indices
	//	given in the array mines. The ith element of the array mines is defined as mines[i] = [xi, yi] where grid[xi][yi] == 0.
	// Return the order of the largest axis-aligned plus sign of 1's contained in grid. If there is none, return 0.
	int n;
	std::vector<std::vector<int>> mines;
	int result;
};
} // namespace LeetcodeCom_Problems