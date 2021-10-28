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
	virtual void Clean() override;
private:
	// https://leetcode.com/problems/4sum/
	// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]]
	// such that : 0 <= a, b, c, d < n
	// 	a, b, c, and d are distinct.
	// 	nums[a] + nums[b] + nums[c] + nums[d] == target
	std::vector<int> nums;
	int target;
	std::vector<std::vector<int>> result;
};
} // namespace LeetcodeCom_Problems
