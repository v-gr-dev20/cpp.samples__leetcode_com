#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class CNumberOfIslands : public CBaseSample {
public:
	CNumberOfIslands();
	virtual ~CNumberOfIslands() override;
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
	virtual void Clean() override;
private:
	// https://leetcode.com/problems/number-of-islands/
	// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
	std::vector<std::vector<char>> grid;
	int result;
};
} // namespace LeetcodeCom_Problems