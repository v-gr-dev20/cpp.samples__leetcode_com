#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class C4Sum : public CBaseSample {
public:
	C4Sum();
	virtual ~C4Sum() override;
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
private:
	std::vector<std::vector<int>> result;
	std::vector<int> numbers;
	int targetSum;
};
} // namespace LeetcodeCom_Problems
