#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class CFirstMissingPositive : public CBaseSample {
public:
	CFirstMissingPositive();
	virtual ~CFirstMissingPositive() override;
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
private:
	// https://leetcode.com/problems/first-missing-positive/
	// Given an unsorted integer array, find the smallest missing positive integer.
	std::vector<int> nums;
	int result;
};
} // namespace LeetcodeCom_Problems