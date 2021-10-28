#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class CShortestPathInAGridWithObstaclesElimination : public CBaseSample {
public:
	CShortestPathInAGridWithObstaclesElimination();
	virtual ~CShortestPathInAGridWithObstaclesElimination() override;
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
private:
	int k;
	std::vector<std::vector<int>> grid;
	int result;
};
} // namespace LeetcodeCom_Problems