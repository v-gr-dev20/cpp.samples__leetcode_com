#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class CSubarraySumEqualsK : public CBaseSample {
public:
	CSubarraySumEqualsK();
	virtual ~CSubarraySumEqualsK() override;
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
	virtual void Clean() override;
private:
	// https://leetcode.com/problems/subarray-sum-equals-k
	// Given an array of integers nums and an integer k, return the total number of continuous subarrays whose k equals to k.
	std::vector<int> nums;
	int k;
	int result;
};
} // namespace LeetcodeCom_Problems